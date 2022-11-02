#include <bits/stdc++.h>
using namespace std;

int n, m; long long k;
int a[500010], b[500010];
int pa[1000010], pb[1000010];
long long xbe[500010], ybe[500010];
long long ll[500010], LL[500010];
int alive[500010];

int exgcd(int a, int b, long long &x, long long &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	int g = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return g;
}

long long check(long long mid) {
	long long ans = mid;
	long long x, y, g = exgcd(n, m, x, y); y = -y;
	long long dx = m / g, dy = n / g;
	long long tn = mid % n, tm = mid % m, bn = mid / n, bm = mid / m;
	for (int i = 0; i < n; i++) {
		if (pb[a[i]] == -1) continue;
		int j = pb[a[i]];
		if (alive[i]) continue;
		int tmp = (j - i) / g;
		long long tx = 1ll * x * tmp, ty = 1ll * y * tmp;
		long long ttn = bn + (tn > i), ttm = bm + (tm > j);
		long long l = ll[i], r = l + (ttn - xbe[i] + dx - 1) / dx;
		long long L = LL[i], R = L + (ttm - ybe[i] + dy - 1) / dy;
		l = max(l, L), r = min(R, r);
		if (l < r) ans -= r - l;
	}
	return ans;
}

int main() {
//	freopen("data.in", "r", stdin);
	memset(pa, -1, sizeof(pa)), memset(pb, -1, sizeof(pb));
	scanf("%d%d%I64d", &n, &m, &k);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]), pa[a[i]] = i;
	for (int i = 0; i < m; i++) scanf("%d", &b[i]), pb[b[i]] = i;
	long long x, y, g = exgcd(n, m, x, y); y = -y;
	long long dx = m / g, dy = n / g;
	for (int i = 0; i < n; i++) {
		if (pb[a[i]] == -1) continue;
		int j = pb[a[i]];
		alive[i] = ((j - i) % g + g) % g;
		if (((j - i) % g + g) % g) continue;
		int tmp = (j - i) / g;
		long long tx = 1ll * x * tmp, ty = 1ll * y * tmp;
		xbe[i] = (tx % dx + dx) % dx;
		ll[i] = (xbe[i] - tx) / dx;
		ybe[i] = (ty % dy + dy) % dy;
		LL[i] = (ybe[i] - ty) / dy;
	}
	long long l = 0, r = 4000000000000000000;
	while (l < r) {
		long long mid = l + r >> 1;
		if (check(mid) >= k) r = mid;
		else l = mid + 1;
	}
	printf("%I64d\n", l);
	return 0;
}