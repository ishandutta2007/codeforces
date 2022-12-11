#include <stdio.h>

#define M 50010
#define K 5

int arr[M][K];
int opt[M][K];
int m,n;

int main() {
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			opt[i][j] = 0;
			if(i > 0) opt[i][j] = opt[i-1][j];
			if(j > 0 && opt[i][j-1] > opt[i][j]) opt[i][j] = opt[i][j-1];
			opt[i][j] += arr[i][j];
		}
	}
	for(int i=0;i<m;i++) {
		printf("%d ",opt[i][n-1]);
	}
	printf("\n");
	return 0;
}