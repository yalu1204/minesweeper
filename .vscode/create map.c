#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int map[3000][3000], minenumber,xsize,ysize;
void SetMine() {
	int x, y;
	for (int i = 0;i < minenumber;i++) {
		x = rand() % xsize + 1;
		y = rand() % ysize + 1;
		if (map[y][x] == 0)
			map[y][x] = -1;
		else i--;
	}
}
void CreateMine() {
	for (int i = 1;i <= xsize;i++)
		for (int j = 1;j <= ysize;j++)
			if (map[j][i] == -1)
				for (int k = i - 1;k <= i + 1;k++)
					for (int l = j - 1;l <= j + 1;l++)
						if (map[l][k] != -1)
							map[l][k]++;
}
void PrintMine() {
	for (int i = 1;i <= xsize;i++) {
		for (int j = 1;j <= ysize;j++) {
			if (map[j][i] != -1) printf("%d ", map[j][i]);
			else printf("* ");
		}
		printf("\n");
	}
}
int main() {
	printf("mine number : ");
	scanf("%d", &minenumber);
	printf("size (x , y) : ");
	scanf("%d %d", &xsize, &ysize);
	if (minenumber > xsize * ysize) {
		printf("error");
		return 1;
	}
	SetMine();
	PrintMine();
	printf("\n");
	CreateMine();
	PrintMine();
}