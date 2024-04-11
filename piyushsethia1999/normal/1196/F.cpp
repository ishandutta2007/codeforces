#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define pii pair<int, pair<int, int> >
#define inf 10000000000000000ll
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int m; cin >> m;
	int k; cin >> k;
	if (n <= 3) {
		int dist[n][n];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				if (i == j) dist[i][j] = 0;
				else dist[i][j] = inf;
			}
		for (int i = 0; i < m; ++i) {
			int x; cin >> x;
			int y; cin >> y;
			cin >> dist[x - 1][y - 1];
			dist[y - 1][x - 1] = dist[x - 1][y - 1];
		} 
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (dist[i][k] + dist[k][j] < dist[i][j])
						dist[i][j] = dist[i][k] + dist[k][j];
		std::vector<int> di;
		for (int i = 0; i < n; ++i) 
			for (int j = i + 1; j < n; ++j) 
				di.pb(dist[i][j]);
		sort(di.begin(), di.end());
		cout << di[k - 1];
	} else {
		priority_queue<pii, std::vector<pii>, greater<pii>> pq;
		for (int i = 0; i < m; ++i) {
			int x; cin >> x;
			int y; cin >> y;
			int w; cin >> w;
			pq.push({w, {x - 1, y - 1}});
		}
		std::vector<map<int, int> > dsu(n);
		for (int i = 0; i < n; ++i) dsu[i][i] = 0;
		int last = -1;
		while (k) {
			auto to = pq.top();
			pq.pop();
			if (dsu[to.se.se].find(to.se.fi) == dsu[to.se.se].end()) {
				k--;
				dsu[to.se.se][to.se.fi] = to.fi;
				dsu[to.se.fi][to.se.se] = to.fi;
				int w = to.fi;
				last = w;
				for (auto p1 : dsu[to.se.se]) {
					for (auto p2 : dsu[to.se.fi]) {
						int u = p1.fi;
						int w1 = p1.se;
						int w2 = p2.se;
						int v = p2.fi;
						if (dsu[u].find(v) == dsu[u].end())
							pq.push({w + w1 + w2, {u, v}});
					} 
				}
			} 
		} 
		cout << last;
	}
}