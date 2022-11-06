#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e6;
int n, L, t[maxn + 10], xx[maxn + 10], yy[maxn + 10];
int ansx[maxn + 10], ansy[maxn + 10];
int *a, *ans;
int nowt, nowp;

struct data {
	int t, p;
	bool operator < (const data &o) const {
		return t % L < o.t % L;
	}
}b[maxn + 10];

void ext() {
	printf("NO"); exit(0);
}

bool chk(int x) {
	int lt = 0, lp = 0, lk = 0;
	for (int i = 1; i <= n; ++i) {
		int t = b[i].t % L, p = b[i].p - (b[i].t / L) * x, k = b[i].t / L;
		if (k > lk) {
			if (t - lt < p - lp) return 1;
		} else {
			if (t - lt < lp - p) return 1;
		}
		lt = t; lp = p; lk = k;
	}
	int t = L, p = x, k = -1;
	if (k > lk) {
		if (t - lt < p - lp) return 1;
	} else {
		if (t - lt < lp - p) return 1;
	}
	return 0;
}

void moveto(int t, int p) {
	while (nowt < t) {
		++nowt;
		if (nowp < p) ans[nowt] = 1, ++nowp;
		else ans[nowt] = -1, --nowp;
	}
	if (nowp != p) ext();
}

void getans(int d) {
	if ((L & 1) != (d & 1)) ext();
	nowt = 0; nowp = 0;
	for (int i = 1; i <= n; ++i)
		moveto(b[i].t % L, b[i].p - d * (b[i].t / L));
	moveto(L, d);
}

void solve() {
	for (int i = 1; i <= n; ++i) b[i] = (data){t[i], a[i]}; 
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; ++i)
		if ((b[i].t & 1) != (b[i].p & 1)) ext();
	for (int i = 1; i <= n; ++i)
		if (b[i].t % L == b[i - 1].t % L) {
			int x = b[i].p - b[i - 1].p, c = (b[i].t - b[i - 1].t) / L;
			if (x % c) ext();
			getans(x / c); return;
		}
	int l = 0, r = L;
	while (l != r) {
		int mid = l + (r - l) / 2;
		if (chk(mid * 2 - L)) l = mid + 1;
		else r = mid;
	}
	getans(l * 2 - L);
}

signed main() {
	scanf("%lld%lld", &n, &L);
	for (int i = 1; i <= n; ++i) {
		int x, y;
		scanf("%lld%lld%lld", &t[i], &x, &y);
		xx[i] = x + y; yy[i] = x - y;
	}
	a = xx; ans = ansx;
	solve();
	a = yy; ans = ansy;
	solve();
	for (int i = 1; i <= L; ++i)
		if (ansx[i] == -1 && ansy[i] == -1) printf("L");
		else if (ansx[i] == 1 && ansy[i] == -1) printf("U");
		else if (ansx[i] == 1 && ansy[i] == 1) printf("R");
		else if (ansx[i] == -1 && ansy[i] == 1) printf("D");
}