#include <stdio.h>

#define N 110

int arr[N];
int cnt[N];
int n;

int main() {
	scanf("%d", &n);
	int mx = 0;
	for(int i = 1;i <= n;i++) {
		scanf("%d", &arr[i]);
		for(int j = 1;j <= arr[i];j++) {
			cnt[j]++;
		}
		if(arr[i] > mx) {
			mx = arr[i];
		}
	}
	for(int i = 1;i <= n;i++) {
		int ans = 0;
		for(int j = 1;j <= mx;j++) {
			if(n-cnt[j]+1 <= i) {
				ans++;
			}
		}
		printf("%d ", ans);
	}
	printf("\n");
	return 0;
}