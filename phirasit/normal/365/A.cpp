#include <stdio.h>

int tmp[10];

int n, k, ans = 0;

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0;i < n;i++) {
		int x;
		scanf("%d", &x);
		for(int j = 0;j <= k;j++) {
			tmp[j] = 0;
		}
		while(x) {
			tmp[x%10] = 1;
			x /= 10;
		}
		bool err = false;
		for(int j = 0;j <= k;j++) {
			if(!tmp[j]) {
				err = true;
			}
		}
		if(!err) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}