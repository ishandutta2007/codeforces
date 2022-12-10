//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 2e5 + 10;
bool h[maxn],
	 mark[maxn];
vector<int> adj[maxn];
int n, m;

void dfs(int u) {
	mark[u] = true;
	for (auto v : adj[u]) if (!mark[v]) {
		h[v] = h[u] ^ 1;
		dfs(v);
	}
}

void solve() {
	cin >> n >> m;
	fill(mark, mark + n, false);
	for (int i = 0; i < n; i++)
		adj[i].clear();
	for (int i = 0; i < m; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	for (int i = 0; i < n; i++)
		if (!mark[i]) {
			h[i] = 0;
			dfs(i);
		}
	int cnt[2] = {0};
	for (int i = 0; i < n; i++)
		cnt[h[i]]++;
	int id = cnt[0] > cnt[1] ? 0 : 1;
	cout << cnt[id ^ 1] << '\n';
	for (int i = 0; i < n; i++)
		if (h[i] ^ id)
			cout << i + 1 << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}