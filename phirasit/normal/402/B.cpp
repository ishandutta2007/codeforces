#include <stdio.h>

#define N 1010

int arr[N];
int n, k;

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
	}
	int mn = (-1u/2), st;
	for(int h = 1;h <= 1000;h++) {
		int cnt = 0;
		for(int i = 0,j = h;i < n;i++,j += k) {
			if(arr[i] != j) {
				cnt++;
			}
		}
		if(cnt < mn) {
			mn = cnt;
			st = h;
		}
	}
	printf("%d\n", mn);
	for(int i = 0, j = st;i < n;i++,j += k) {
		if(arr[i] < j) {
			printf("+ %d %d\n", i+1, j-arr[i]);
		}else if(arr[i] > j) {
			printf("- %d %d\n", i+1, arr[i]-j);
		}
	}
	return 0;
}