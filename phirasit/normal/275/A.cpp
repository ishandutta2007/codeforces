#include <stdio.h>

int arr[5][5];

int main() {
	int i,j;
	for(i=0;i<3;i++) {
		for(j=0;j<3;j++)
			scanf("%d",&arr[i][j]);
	}
	for(i=0;i<3;i++) {
		for(j=0;j<3;j++) {
			printf("%d",!((arr[i][j] + arr[i-1][j] + arr[i][j-1] + arr[i+1][j] + arr[i][j+1]) % 2));
		}
		printf("\n");
	}
	return 0;
}