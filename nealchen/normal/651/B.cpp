#include <stdio.h>
#include <algorithm>
int n, a[1000], t = 233, last, ans = 0;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", a + i);
	std::sort(a, a + n);
	while(1) {
		t = last = 0;
		for(int i = 0; i < n; ++i) if(a[i] && a[i] != last) {
			last = a[i];
			a[i] = 0;
			++t;
		}
		if(!t) break;
		ans += t - 1;
	}
	printf("%d", ans);
	return 0;
}