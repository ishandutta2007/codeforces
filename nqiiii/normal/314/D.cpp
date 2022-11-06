#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000;
int n;
ll smax[maxn + 10], smin[maxn + 10], pmax[maxn + 10], pmin[maxn + 10];
struct node {
	ll x, y;
	bool operator < (const node &t) const {
		return x < t.x;
	}
}a[maxn * 2 + 10];

bool chk(ll v) {
	for (int i = 1, p = 1; i <= n; ++i) {
		while (p <= n && a[p].x - a[i].x <= v * 2) ++p;
		if (max(pmax[i - 1], smax[p]) - min(pmin[i - 1], smin[p]) <= v * 2) return 1;
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld%lld", &a[i].x, &a[i].y);
		ll tmpx = a[i].x - a[i].y, tmpy = a[i].x + a[i].y;
		a[i].x = tmpx * 2; a[i].y = tmpy * 2;
	}
	sort(a + 1, a + n + 1);
	pmax[0] = smax[n + 1] = -1e10;
	pmin[0] = smin[n + 1] = 1e10;
	for (int i = 1; i <= n; ++i) {
		pmax[i] = max(pmax[i - 1], a[i].y);
		pmin[i] = min(pmin[i - 1], a[i].y);
	}
	for (int i = n; i >= 1; --i) {
		smax[i] = max(smax[i + 1], a[i].y);
		smin[i] = min(smin[i + 1], a[i].y);
	}
	ll l = 0, r = 1e10;
	while (l != r) {
		ll mid = (l + r) / 2;
		if (chk(mid)) r = mid; else l = mid + 1;
	}
	printf("%.10lf", l / 2.0);
}