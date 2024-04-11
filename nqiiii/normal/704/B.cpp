#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5000;
ll f[maxn + 10][2][2], g[maxn + 10][2][2];
ll a[maxn + 10], b[maxn + 10], c[maxn + 10], d[maxn + 10], x[maxn + 10];
int n, s, e;

inline void upd(ll &x, ll y) {
	if (y < x) x = y;
}

int main() {
	scanf("%d%d%d", &n, &s, &e);
	for (int i = 1; i <= n; ++i) scanf("%lld", &x[i]);
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; ++i) scanf("%lld", &b[i]);
	for (int i = 1; i <= n; ++i) scanf("%lld", &c[i]);
	for (int i = 1; i <= n; ++i) scanf("%lld", &d[i]);
	memset(f, 0x3f, sizeof f);
	f[0][0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		memset(g, 0x3f, sizeof g);
		for (int j = 0; j <= n; ++j)
			for (int k = 0; k <= 1; ++k)
				for (int l = 0; l <= 1; ++l)
					if (f[j][k][l] < 1e18) {
						ll w = f[j][k][l] + (x[i] - x[i - 1]) * (j * 2 + k + l);
						if (i == s) {
							if (k) upd(g[j][k - 1][l], w + c[i]);
							if (!l && j) upd(g[j - 1][k][l + 1], w + c[i]);
							if (!l) upd(g[j][k][l + 1], w + d[i]);
						} else if (i == e) {
							if (l) upd(g[j][k][l - 1], w + a[i]);
							if (!k && j) upd(g[j - 1][k + 1][l], w + a[i]);
							if (!k) upd(g[j][k + 1][l], w + b[i]);
						} else {
							upd(g[j + 1][k][l], w + b[i] + d[i]);
							if (j > 1 || (j && (k || l)))
								upd(g[j - 1][k][l], w + a[i] + c[i]);
							if (j || l) upd(g[j][k][l], w + a[i] + d[i]);
							if (j || k) upd(g[j][k][l], w + b[i] + c[i]);
							if (i == n && k && l) upd(g[j][k - 1][l - 1], w + a[i] + c[i]);
						}
					}
		memcpy(f, g, sizeof g);
	}
	printf("%lld", f[0][0][0]);
}