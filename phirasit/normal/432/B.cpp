#include <stdio.h>

#define N 100010

int H[N];
int arr[N][2];
int n;

int main() {
	scanf("%d",&n);
	for(int i = 0;i < n;i++) {
		scanf("%d%d",&arr[i][0],&arr[i][1]);
		H[arr[i][0]]++;
	}
	for(int i = 0;i < n;i++) {
		int ans1 = n-1 + H[arr[i][1]];
		int ans2 = 2*n - 2 - ans1;
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}