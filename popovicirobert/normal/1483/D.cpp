#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

constexpr ll INF = 1e18;

struct Edge {
	int x, y;
	ll w;
};


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
    	int x, y, w;
    	cin >> x >> y >> w;
    	g[x].push_back({y, w});
    	g[y].push_back({x, w});
    	edges[i] = {x, y, w};
    }

    vector<vector<pair<int, int>>> nodes(n + 1);
    int q;
    cin >> q;
    while (q--) {
    	int u, v, l;
    	cin >> u >> v >> l;
    	nodes[u].push_back({v, l});
    	nodes[v].push_back({u, l});
    }

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
    for (auto e : edges) {
    	dist[e.x][e.y] = dist[e.y][e.x] = e.w;
    }
    for (int i = 1; i <= n; i++) {
    	dist[i][i] = 0;
    }
    for (int z = 1; z <= n; z++) {
    	for (int x = 1; x <= n; x++) {
    		for (int y = 1; y <= n; y++) {
    			dist[x][y] = min(dist[x][y], dist[x][z] + dist[z][y]);
    		}
    	}
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INF));
    for (int src = 1; src <= n; src++) {
    	for (int nod = 1; nod <= n; nod++) {
    		for (auto itr : nodes[src]) {
    			dp[nod][itr.first] = min(dp[nod][itr.first], dist[src][nod] - itr.second);
    		}
    	}
    }

    vector<bool> good(m);
    for (int src = 1; src <= n; src++) {
    	for (int i = 0; i < m; i++) {
    		int x = edges[i].x;
    		int y = edges[i].y;
    		ll current = dp[x][src] + dist[y][src] + edges[i].w;
    		if (current <= 0) {
    			good[i] = true;
    		}
    	}
    }

    cout << count(good.begin(), good.end(), true);
    
    return 0;
}