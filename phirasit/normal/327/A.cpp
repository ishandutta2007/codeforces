#include <stdio.h>

int arr[110];
int n;

int main() {
	int i,j,k,ans = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		arr[i] += arr[i-1];
	}
	for(i=0;i<n;i++) {
		for(j=i;j<n;j++) {
			k = arr[i-1] + (j-i+1 - (arr[j]-arr[i-1])) + arr[n-1] - arr[j];
			if(k > ans)
				ans = k;
		}
	}
	printf("%d\n",ans);
	return 0;
}