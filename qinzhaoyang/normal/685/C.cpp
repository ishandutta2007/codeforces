#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
typedef long long ll;
const ll inf = 4e18;
void ckmax(ll &x, ll y) {x = max(x, y);}
void ckmin(ll &x, ll y) {x = min(x, y);}

ll T, n, x[N], y[N], z[N], X, Y, Z, l[4], r[4], tl[4], tr[4], t[4];

int S(ll d) {
	for (int i = 0; i < 4; i++) l[i] = -inf, r[i] = inf;
	for (int i = 1; i <= n; i++) {
		ckmax(l[0], -d + x[i] + y[i] + z[i]), ckmin(r[0], d + x[i] + y[i] + z[i]);
		ckmax(l[1], -d - x[i] + y[i] + z[i]), ckmin(r[1], d - x[i] + y[i] + z[i]);
		ckmax(l[2], -d + x[i] - y[i] + z[i]), ckmin(r[2], d + x[i] - y[i] + z[i]);
		ckmax(l[3], -d + x[i] + y[i] - z[i]), ckmin(r[3], d + x[i] + y[i] - z[i]);
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) tl[j] = l[j] + ((l[j] & 1) ^ i), tr[j] = r[j] - ((r[j] & 1) ^ i);
		if(tl[0] > tr[0] || tl[1] > tr[1] || tl[2] > tr[2] || tl[3] > tr[3]) continue;
		t[1] = tl[1], t[2] = tl[2], t[3] = tl[3];
		if (t[1] + t[2] + t[3] > tr[0]) continue;
		for (int j = 1; j <= 3; j++) if(t[1] + t[2] + t[3] < tl[0])
			t[j] = min(tr[j], tl[0] - t[1] - t[2] - t[3] + t[j]);
		if (t[1] + t[2] + t[3] < tl[0]) continue;
		return X = (t[2] + t[3]) >> 1, Y = (t[1] + t[3]) >> 1, Z = (t[1] + t[2]) >> 1, 1;
	}
	return 0;
}

int main() {
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
		ll l = 0, r = inf;
		while(l <= r) {
			ll mid = (l + r) >> 1;
			if(S(mid)) r = mid - 1;
			else l = mid + 1;
		}
		printf("%lld %lld %lld\n", X, Y, Z);
	}
	return 0;
}