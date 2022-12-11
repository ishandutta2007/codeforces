#include <stdio.h>

char str[]="wb";
int n;

int min(int a,int b) {
	if(a < b) return a;
	return b;
}
int main() {
	int i,j,k,x,y;
	int m;
	scanf("%d",&n);
	if(n%2) {
		printf("-1\n");
		return 0;
	}else {
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				for(k=0;k<n;k++) {
					if(j >= n/2) x = n-j-1;
					else x = j;
					if(k >= n/2) y = n-k-1;
					else y = k;
					m = min(x,y);
					printf("%c",str[(m+i)%2]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	return 0;
}