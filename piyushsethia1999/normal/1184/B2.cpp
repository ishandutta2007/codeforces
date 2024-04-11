#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

#define NIL 0
#define INF INT_MAX
class Matcher
{
	std::vector<std::vector<int> > G;
	std::vector<int> dist, match;
	int n, m;
public:
	Matcher(int n, int m) : n(n), m(m), G(n + m + 1), match(n + m + 1), dist(n + 1) {}
	void pb(int u, int v) { G[u + 1].pb(v + 1 + n); G[v + 1 + n].pb(u + 1);}
	bool bfs() {
		int u;
		queue<int> Q;
		for (unsigned i = 1; i <= n; i++)
			if (match[i] == 0) {
				dist[i] = 0;
				Q.push(i);
			}
			else dist[i] = INT_MAX;
		dist[0] = INT_MAX;
		while (!Q.empty()) {
			u = Q.front(); Q.pop();
			if (u != 0)
				for (int v : G[u])
					if (dist[match[v]] == INT_MAX) {
						dist[match[v]] = dist[u] + 1;
						Q.push(match[v]);
					}
		}
		return (dist[0] != INT_MAX);
	}
	bool dfs(int u) {
		if (u == 0)
			return true;
		for (int v : G[u])
			if (dist[match[v]] == dist[u] + 1)
				if (dfs(match[v])) {
					match[v] = u;
					match[u] = v;
					return true;
				}
		dist[u] = INT_MAX;
		return false;
	}
	int MaxMatching() {
		int matching = 0;
		while (bfs())
			for (unsigned i = 1; i <= n; i++)
				if (match[i] == 0 && dfs(i))
					matching++;
		return matching;
	}
	std::vector<int> GetMatching() {
		std::vector<int> res(n);
		for (int i = 0; i < n; ++i)
			res[i] = match[i + 1] - n - 1;
		return res;
	}
};

int dist[200][200];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int m; cin >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			dist[i][j] = INF;
	for (int i = 0; i < n; ++i)
		dist[i][i] = 0;
	for (int i = 0; i < m; ++i) {
		int u; cin >> u; u--;
		int v; cin >> v; v--;
		dist[u][v] = min(dist[u][v], 1ll);
		dist[v][u] = min(dist[v][u], 1ll);
	}
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
	int s; cin >> s;
	int b; cin >> b;
	int k; cin >> k;
	int h; cin >> h;
	Matcher B(s, b);
	std::vector<int> x(s);
	std::vector<int> a(s);
	std::vector<int> f(s);
	for (int i = 0; i < s; ++i)
		cin >> x[i] >> a[i] >> f[i];
	std::vector<int> y(b);
	std::vector<int> d(b);
	for (int i = 0; i < b; ++i)
		cin >> y[i] >> d[i];
	for (int i = 0; i < s; ++i)
		for (int j = 0; j < b; ++j)
			if (dist[x[i]][y[j]] <= f[i] && a[i] >= d[j])
				B.pb(i, j);
	int u = B.MaxMatching();
	int mi = k * u;
	for (int i = 0; i <= u; ++i)
		mi = min(mi, h * (s - i) + i * k);
	cout << mi;
}