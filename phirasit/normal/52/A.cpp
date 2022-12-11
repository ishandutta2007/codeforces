#include <stdio.h>


int min(int a,int b) {
	if(a < b) return a;
	return b;
}
int main() {
	int arr[10],j;
	int i,n,ans;
	scanf("%d",&n);
	ans = n;
	arr[1] = arr[2] = arr[3] = 0;
	while(n--) {
		scanf("%d",&j);
		arr[j]++;
	}
	ans = min(ans,arr[1]+arr[2]);
	ans = min(ans,arr[1]+arr[3]);
	ans = min(ans,arr[2]+arr[3]);
	printf("%d\n",ans);
	return 0;
}