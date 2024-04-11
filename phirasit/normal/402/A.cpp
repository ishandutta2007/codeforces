#include <stdio.h>

int k, a, b, v;

int main() {
	scanf("%d%d%d%d", &k, &a, &b, &v);
	int ans = 0;
	while(a > 0) {
		ans++;
		int sec;
		if(b+1 > k) {
			sec = k;
			b -= k-1;
		}else {
			sec = b+1;
			b = 0;
		}
		a -= sec * v;
	}
	printf("%d\n", ans);
}