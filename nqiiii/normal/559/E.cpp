#include <bits/stdc++.h>
using namespace std;
const int maxn = 100, inf = 1e9;

map<int, int> mp;
struct data {
	int p, l;
	bool operator < (const data &t) const {
		return p < t.p;
	}
}a[maxn + 10];
int n;

int dp(int x) {
	if (mp.count(x)) return mp[x];
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (a[i].p < x)
			for (int j = 0; j < 2; ++j) {
				int l, r;
				if (j)
					l = a[i].p, r = min(a[i].p + a[i].l, x);
				else
					l = a[i].p - a[i].l, r = a[i].p;
				for (int j = n; j >= 1; --j)
					if (i != j && a[j].p < x && a[j].p <= r && a[j].p >= l)
						l = min(l, a[j].p - a[j].l);
				ans = max(ans, r - l + dp(l));
			}
	return mp[x] = ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].p, &a[i].l);
	sort(a + 1, a + n + 1);
	printf("%d", dp(inf));
}