#include <stdio.h>

long long ans = 0;
int n;

int main() {
	int ls = 0, e = 0;
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		int h;
		scanf("%d", &h);
		if(e + ls-h < 0) {
			ans -= (long long)e + ls-h;
			e = 0;
		}else {
			e += ls-h;
		}
		ls = h;
	}
	printf("%I64d\n", ans);
	return 0;
}