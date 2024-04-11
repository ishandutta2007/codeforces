#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T> T edmondsKarp(vector<unordered_map<int, T>>& graph, int source, int sink) {
	assert(source != sink);
	T flow = 0;
	vi par(sz(graph)), q = par;

	for (;;) {
		fill(all(par), -1);
		par[source] = 0;
		int ptr = 1;
		q[0] = source;

		rep(i,0,ptr) {
			int x = q[i];
			for (auto e : graph[x]) {
				if (par[e.first] == -1 && e.second > 0) {
					par[e.first] = x;
					q[ptr++] = e.first;
					if (e.first == sink) goto out;
				}
			}
		}
		return flow;
out:
		T inc = numeric_limits<T>::max();
		for (int y = sink; y != source; y = par[y])
			inc = min(inc, graph[par[y]][y]);

		flow += inc;
		for (int y = sink; y != source; y = par[y]) {
			int p = par[y];
			if ((graph[p][y] -= inc) <= 0) graph[p].erase(y);
			graph[y][p] += inc;
		}
	}
} //kactl

void solve(){
    cout << fixed << setprecision(10);
    
    int n, m, x; cin >> n >> m >> x;
    vector<unordered_map<int, ll>> adj(n);
    vector<ar<int, 3>> ed;
    for (int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c, --a, --b;
        ed.push_back({a, b, c});
    }
    auto v = [&](ld mid){
        for (int i = 0; i < n; i++) adj[i].clear();
        for (auto& it : ed) adj[it[0]][it[1]] = floor(ld(it[2])/mid);

        return edmondsKarp(adj, 0, n-1) >= x;
    };
    ld lo=0, hi=1e6;
    for (int rep = 0; rep < 61; rep++){
        ld mid = (lo+hi)/ld(2);

        if (v(mid)) lo=mid;
        else hi=mid;
    }
    cout << lo*x << '\n';

}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}