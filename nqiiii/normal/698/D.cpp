#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
int k, n, ans;
int ax[10], ay[10];
int mx[maxn + 10], my[maxn + 10];
vector<int> a[10][maxn + 10];
int q[10], ql, qr;
bool us[10], vis[maxn + 10];

bool is(int r, int p) {
	int l = 0;
	if (l > r) swap(l, r);
	return p >= l && p <= r;
}

bool chk(int xa, int ya, int xb, int yb) {
	if (1ll * xa * yb != 1ll * ya * xb) return 0;
	return is(xa, xb) && is(ya, yb);
}

bool dfs() {
	if (ql > qr) return 1;
	int p = q[ql], lst = qr;
	++ql; //vis[p] = 0;
	for (int i = 1; i <= k; ++i)
		if (!us[i]) {
			us[i] = 1; bool fd = 1;
			for (int j = 0; j < (int)a[i][p].size(); ++j) {
				int e = a[i][p][j];
				if (vis[e]) continue;
				if (qr == k) {
					fd = 0; break;
				}
				vis[e] = 1;
				q[++qr] = e;
			}
			if (fd && dfs()) return 1;
			while (qr > lst) {
				vis[q[qr]] = 0; --qr;
			}
			us[i] = 0; 
		}
	--ql; vis[p] = 1; return 0;
}

int main() {
	scanf("%d%d", &k, &n);
	for (int i = 1; i <= k; ++i) scanf("%d%d", &ax[i], &ay[i]);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &mx[i], &my[i]);
	for (int i = 1; i <= k; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
				if (k != j && chk(mx[j] - ax[i], my[j] - ay[i], mx[k] - ax[i], my[k] - ay[i]))
					a[i][j].push_back(k);
	for (int i = 1; i <= n; ++i) {
		memset(us, 0, sizeof us);
		memset(vis, 0, sizeof vis);
		q[ql = qr = 1] = i;
		ans += dfs();
	}
	printf("%d", ans);
}