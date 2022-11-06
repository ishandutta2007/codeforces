#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5;
int t, n;
ll x[maxn + 10], y[maxn + 10], z[maxn + 10];
ll l[4], r[4], tl[4], tr[4];
ll a[4];

void update(int p, ll a, ll b) {
	l[p] = max(l[p], a - b);
	r[p] = min(r[p], a + b);
}

bool calc() {
	ll sum = 0;
	for (int i = 0; i <= 3; ++i) {
		tl[i] = l[i] & 1 ? (l[i] + 1) / 2 : l[i] / 2;
		tr[i] = r[i] & 1 ? (r[i] - 1) / 2 : r[i] / 2;
		if (tl[i] > tr[i]) return 0;
		if (i) {
			a[i] = tl[i]; sum += tl[i];
		}
	}
	for (int i = 1; i <= 3; ++i) {
		ll v = min(max(tl[0] - sum, 0ll), tr[i] - tl[i]);
		a[i] += v; sum += v;
	}
	return sum >= tl[0] && sum <= tr[0];
}

bool chk(ll v) {
	memset(l, -0x3f, sizeof l);
	memset(r, 0x3f, sizeof r);
	for (int i = 1; i <= n; ++i) {
		update(0, x[i] + y[i] + z[i], v);
		update(1, x[i] + y[i] - z[i], v);
		update(2, x[i] - y[i] + z[i], v);
		update(3, -x[i] + y[i] + z[i], v);
	}
	if (calc()) {
		for (int i = 1; i <= 3; ++i)
			a[i] *= 2;
		return 1;
	}
	l[0] -= 3; r[0] -= 3;
	for (int i = 1; i <= 3; ++i) {
		--l[i]; --r[i];
	}
	if (calc()) {
		for (int i = 1; i <= 3; ++i)
			a[i] = a[i] * 2 + 1;
		return 1;
	}
	return 0;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
		ll l = 0, r = 3e18;
		while (l != r) {
			ll mid = (l + r) >> 1;
			if (chk(mid)) r = mid;
			else l = mid + 1;
		}
		chk(l);
		printf("%lld %lld %lld\n", (a[1] + a[2]) / 2, (a[1] + a[3]) / 2, (a[2] + a[3]) / 2);
	}
}