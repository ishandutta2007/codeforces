#include <stdio.h>
int n, k, a, b;
char ans[100001];
int main() {
	int i, j, K;
	scanf("%d%d%d%d", &n, &k, &a, &b);
	for(i = 0; i < n; ++i) {
		if(a > b) {
			if(i == 0 || ans[i - 1] == 'B') {
				ans[i] = 'G';
				--a;
				K = k - 1;
			} else if(K) {
				ans[i] = 'G';
				--a;
				--K;
			} else {
				ans[i] = 'B';
				--b;
				K = k - 1;
			}
		} else {
			if(i == 0 || ans[i - 1] == 'G') {
				ans[i] = 'B';
				--b;
				K = k - 1;
			} else if(K) {
				ans[i] = 'B';
				--b;
				--K;
			} else {
				ans[i] = 'G';
				--a;
				K = k - 1;
			}
		}
	}
	if(a < 0 || b < 0) puts("NO"); else {
		ans[n] = '\0';
		puts(ans);
	}
	return 0;
}