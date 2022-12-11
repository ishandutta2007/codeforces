#include <stdio.h>

#define N 100010

int lf[N], rg[N];
int n, arr[N];

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
	}
	for(int i = 0;i < n;i++) {
		if(i == 0) {
			lf[i] = 1;
		}else if(arr[i] > arr[i-1]) {
			lf[i] = lf[i-1] + 1;
		}else {
			lf[i] = 1;
		}
	}
	for(int i = n-1;i >= 0;i--) {
		if(i == n-1) {
			rg[i] = 1;
		}else if(arr[i] < arr[i+1]) {
			rg[i] = rg[i+1] + 1;
		}else {
			rg[i] = 1;
		}
	}
	int ans = 1;
	for(int i = 0;i < n;i++) {
		if(lf[i] > ans) {
			ans = lf[i];
		}
		if(rg[i] > ans) {
			ans = rg[i];
		}
		if(i < n-1 && lf[i] + 1 > ans) {
			ans = lf[i] + 1;
		}
		if(i > 0 && rg[i] + 1 > ans) {
			ans = rg[i] + 1;
		}
	}
	for(int i = 0;i+2 < n;i++) {
		if(arr[i] < arr[i+2]-1) {
			if(lf[i] + rg[i+2] + 1 > ans) {
				ans = lf[i] + rg[i+2] + 1;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}