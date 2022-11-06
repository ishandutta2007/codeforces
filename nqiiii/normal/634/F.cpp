#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4;
int n, m, l, k;
ll ans;

struct node {
	int x, y;
	bool operator < (const node &t) const {
		return x < t.x;
	}

}a[maxn + 10];

int pre[maxn + 10], nxt[maxn + 10], val[maxn + 10];
int res[maxn + 10];

void del(int p) {
	pre[nxt[p]] = pre[p];
	nxt[pre[p]] = nxt[p];
}

void solve(int d) {
	memset(res, 0, sizeof res);
	memset(val, 0, sizeof val);
	for (int i = 1; i <= l; ++i)
		if (a[i].x <= d) ++val[a[i].y];
	for (int i = 0; i <= m + 1; ++i)
		pre[i] = i - 1, nxt[i] = i + 1;
	for (int i = 1; i <= m; ++i)
		if (!val[i]) del(i);
	ll now = 0;
	for (int i = nxt[0]; i != m + 1; i = nxt[i]) {
		int p = i, s = val[i];
		while (s < k) {
			p = pre[p];
			if (!p) break;
			s += val[p];
		}
		res[i] = (nxt[i] - i) * p;
		now += res[i];
	}
	for (int i = 1; i <= l; ++i)
		if (a[i].x <= d) {
			ans += (a[i].x - a[i - 1].x) * now;
			int r, st; r = st = pre[a[i].y];
			if (!--val[a[i].y]) {
				now -= res[a[i].y];
				del(a[i].y);
			}
			for (int j = 1; j <= k + 1; ++j) {
				if (r == m + 1) break;
				else {
					now -= res[r]; 
					r = nxt[r];
				}
			}
			int l = r, s = 0; r = pre[r];
			for (int j = 1; j <= k + 1; ++j) {
				while (l && s < k) {
					l = pre[l];
					if (!l) break;
					s += val[l];
				}
				res[r] = (nxt[r] - r) * l;
				now += res[r];
				if (r == st) break;
				else {
					s -= val[r];
					r = pre[r];
				}
			}
		}
}


int main() {
	scanf("%d%d%d%d", &n, &m, &l, &k);
	for (int i = 1; i <= l; ++i) scanf("%d%d", &a[i].x, &a[i].y);
	sort(a + 1, a + l + 1);
	for (int i = 1; i <= n; ++i)
		solve(i);
	printf("%lld", ans);
}