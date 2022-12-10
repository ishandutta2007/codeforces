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

const int maxn = 1e5 + 10,
	  maxl = 60;
LL a[maxn];
int n;
vector<int> adj[maxn];
int dis[maxn],
	par[maxn];
bool mark[maxn];

int bfs(int s) {
	int mn = 1000 * 1000;
	vector<int> q;
	mark[s] = true;
	dis[s] = 0;
	q.PB(s);
	for (int i = 0; i < sz(q); i++) {
		int u = q[i];
		for (auto v : adj[u]) {
			if (!mark[v]) {
				mark[v] = dis[v] = dis[u] + 1;
				par[v] = u;
				q.PB(v);
			}
			else if (v != par[u])
				smin(mn, dis[u] + dis[v] + 1);
		}
	}
	for (auto u : q)
		mark[u] = false, par[u] = -1;
	return mn;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(par, -1, sizeof par);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int j = 0; j < maxl; j++) {
		vector<int> vec;
		vec.reserve(n);
		for (int i = 0; i < n; i++)
			if ((a[i] >> j) & 1LL)
				vec.PB(i);
		if (sz(vec) >= 3) {
			cout << 3 << endl;
			return 0;
		}
		else if (sz(vec) == 2) {
			adj[vec[0]].PB(vec[1]);
			adj[vec[1]].PB(vec[0]);
		}
	}
	for (int i = 0; i < n; i++) {
		sort(all(adj[i]));
		adj[i].resize(unique(all(adj[i])) - adj[i].begin());
	}
	int ans = 1000 * 1000;
	for (int i = 0; i < n; i++)
		smin(ans, bfs(i));
	if (ans == 1000 * 1000)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}