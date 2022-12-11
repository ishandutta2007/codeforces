#include <stdio.h>

int arr[110];
int n;

int abs(int x) {
	if(x < 0) return -x;
	return x;
}
int main() {
	int i,j,k,m = 999999;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		if(i > 0) {
			if((j = abs(arr[i]-arr[i-1])) < m) {
				m = j;
				k = i;
			}
		}
	}
	if(abs(arr[0]-arr[n-1]) < m) {
		printf("%d %d\n",1,n);
	}else {
		printf("%d %d\n",k,k+1);
	}
	return 0;
}