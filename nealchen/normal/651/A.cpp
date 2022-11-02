#include <stdio.h>
int main() {
	int a[2], ans = 0;
	scanf("%d%d", a, a + 1);
	while(a[0] > 0 && a[1] > 0) {
		if(a[0] == 1 && a[1] == 1) break;
		++ans;
		if(a[0] < a[1]) {
			++a[0];
			a[1] -= 2;
		}
		else {
			++a[1];
			a[0] -= 2;
		}
		if(a[0] <= 0 || a[1] <= 0) break;
	}
	printf("%d\n", ans);
	return 0;
}