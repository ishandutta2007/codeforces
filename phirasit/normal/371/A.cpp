#include <stdio.h>

int arr[110][2];

int main() {
	int n,k,x;
	scanf("%d %d",&n,&k);
	
	for(int i=0;i<n;i++) {
		scanf("%d",&x);
		arr[i%k][x-1]++;
	}
	int ans = 0;
	for(int i = 0;i<k;i++) {
		if(arr[i][0] < arr[i][1])
			ans += arr[i][0];
		else
			ans += arr[i][1];
	}
	printf("%d\n",ans);
	return 0;
}