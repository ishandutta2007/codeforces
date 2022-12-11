#include <stdio.h>

int mx, mn;
long long cnt_mx, cnt_mn;
int n;

int main() {
	mx = -(-1u/2);
	mn = (-1u/2);
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		int val;
		scanf("%d", &val);
		if(val > mx) {
			mx = val;
			cnt_mx = 1;
		}else if(val == mx) {
			cnt_mx++;
		}
		if(val < mn) {
			mn = val;
			cnt_mn = 1;
		}else if(val == mn) {
			cnt_mn++;
		}
	}
	if(mx == mn) {
		printf("%d %I64d\n", mx-mn, cnt_mx * (cnt_mx-1)/2);
	}else {
		printf("%d %I64d\n", mx-mn, cnt_mx * cnt_mn);
	}
	return 0;
}