#include <stdio.h>
#define cmax(x, y) ((y) > x ? x = (y) : x)
const int N = 2005;
int n, a[N], pre[N], suf[N];
int main() {
	register int i, j, ans = 0, cnt, now, tot;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(i = 1; i <= n; ++i) pre[i] = pre[i-1] + (a[i]==1);
	for(i = n; i >= 1; --i) suf[i] = suf[i+1] + (a[i]==2);
	for(i = 1; i <= n; ++i) {
		now = cnt = pre[i];
		for(j = i; j >= 1; --j) {
			cnt += a[j] == 1 ? -1 : 1;
			cmax(now, cnt);
		}
		tot = now;
		now = cnt = suf[i + 1];
		for(j = i + 1; j <= n; ++j) {
			cnt += a[j] == 2 ? -1 : 1;
			cmax(now, cnt);
		}
		tot += now;
		cmax(ans, tot);
	}
	printf("%d", ans);
	return 0;
}