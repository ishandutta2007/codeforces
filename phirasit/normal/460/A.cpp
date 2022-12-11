#include <stdio.h>

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	int ans = 0;
	while(n) {
		n--;
		ans++;
		if(ans%m == 0) {
			n++;
		}
	}
	printf("%d\n", ans);
	return 0;
}