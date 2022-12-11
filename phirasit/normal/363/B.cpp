#include <stdio.h>
#define MX_N 200010

int arr[MX_N];
int n,k;

int main() {
	int i,j;
	scanf("%d %d",&n,&k);
	int ans = k-1;
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		if(i > 0) arr[i] += arr[i-1];
		if(i >= k-1) { 
			if(arr[i]-arr[i-k] < arr[ans]-arr[ans-k])
				ans = i;
		}
	}
	printf("%d\n",ans-k+2);
	return 0;
}