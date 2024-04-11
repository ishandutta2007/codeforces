#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500000;
const ll inf = 1e18;

int n, m;
int f[maxn + 10], g[maxn + 10];
ll h[maxn + 10], t[maxn + 10];
int res[maxn + 10], ans, cnt[maxn + 10];
vector<pair<ll, int> > ask[maxn + 10];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%lld", &h[i]);
	for (int i = 1; i <= m; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		ask[x].push_back(make_pair(y, i));
	}
	memset(t, 0x7f, sizeof t); t[0] = -inf;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < (int)ask[i].size(); ++j)
			res[ask[i][j].second] += lower_bound(t + 1, t + n + 1, ask[i][j].first) - t;
		f[i] = lower_bound(t + 1, t + n + 1, h[i]) - t;
		t[f[i]] = h[i]; ans = max(ans, f[i]);
	}
	memset(t, 0x7f, sizeof t); t[0] = -inf;
	for (int i = n; i >= 1; --i) {
		for (int j = 0; j < (int)ask[i].size(); ++j)
			res[ask[i][j].second] += lower_bound(t + 1, t + n + 1, -ask[i][j].first) - t;
		g[i] = lower_bound(t + 1, t + n + 1, -h[i]) - t;
		t[g[i]] = -h[i];
	}
	for (int i = 1; i <= n; ++i)
		if (f[i] + g[i] == ans + 1) ++cnt[f[i]];
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < (int)ask[i].size(); ++j)
			res[ask[i][j].second] = max(res[ask[i][j].second] - 1, ans - (f[i] + g[i] == ans + 1 && cnt[f[i]] == 1));
	for (int i = 1; i <= m; ++i) printf("%d\n", res[i]);
}