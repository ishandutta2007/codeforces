#include <stdio.h>

int ans = -1;

int n, d;

int main() {
	scanf("%d%d", &n, &d);
	for(int i = 0;i < n;i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(x < d || (x == d && y == 0)) {
			if(y == 0) {
				if(y > ans) {
					ans = y;
				}
			}else {
				if(100-y > ans) {
					ans = 100-y;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}