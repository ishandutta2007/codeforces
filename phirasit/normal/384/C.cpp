#include <stdio.h>

#define N 200010

long long lf = 0, rg = 0;

int arr[N];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
	}
	long long cnt1 = 0;
	for(int i = 0;i < n;i++) {
		if(arr[i] == 1) {
			cnt1++;
		}else {
			lf += cnt1;
		}
	}
	long long cnt2 = 0;
	for(int i = n-1;i >= 0;i--) {
		if(arr[i] == 0) {
			cnt2++;
		}else {
			rg += cnt2;
		}
	}
	if(lf < rg) {
		printf("%I64d\n", lf);
	}else {
		printf("%I64d\n", rg);
	}
	return 0;
}