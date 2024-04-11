#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200000;
int t, s[maxn + 10], scnt, n;
ll c[maxn + 10], f[maxn + 10], ans;

struct node {
	int i, o, h;
	bool operator < (const node &t) const {
		return o == t.o ? i > t.i : o > t.o;
	}
}a[maxn + 10];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &a[i].i, &a[i].o, &a[i].h);
		s[++scnt] = a[i].i; s[++scnt] = a[i].o;
	}
	sort(a + 1, a + n + 1);
	sort(s + 1, s + scnt + 1); scnt = unique(s + 1, s + scnt + 1) - s - 1;
	for (int i = 1; i <= n; ++i) {
		a[i].i = lower_bound(s + 1, s + scnt + 1, a[i].i) - s;
		a[i].o = lower_bound(s + 1, s + scnt + 1, a[i].o) - s;
		f[i] = 0;
		for (int j = a[i].o - 1; j; j -= j & -j) f[i] = max(f[i], c[j]);
		f[i] += a[i].h;
		for (int j = a[i].i; j <= scnt; j += j & -j) c[j] = max(c[j], f[i]);
		ans = max(ans, f[i]);
	}
	printf("%lld\n", ans);
}