#include <stdio.h>

#define N 50

int seat[4][N];

int k;

int main() {
	scanf("%d", &k);
	int x = 0, y = 0;
	for(int i = 0;i < k;i++) {
		seat[x][y] = 1;
		x++;
		if(x == 2 && y) {
			x++;
		}
		if(x >= 4) {
			x = 0;
			y++;
		}
	}
	printf("+------------------------+\n");
	for(int i = 0;i < 4;i++) {
		printf("|");
		for(int j = 0;j < 11;j++) {
			if(i == 2 && j) {
				printf(".");
			}else if(seat[i][j]) {
				printf("O");
			}else {
				printf("#");
			}
			printf(".");
		}
		if(i == 2) {
			printf(".");
		}else {
			printf("|");
		}
		if(i == 0) {
			printf("D");
		}else {
			printf(".");
		}
		printf("|");
		if(i == 0 || i == 3) {
			printf(")");
		}
		printf("\n");
	}
	printf("+------------------------+\n");
	return 0;
}