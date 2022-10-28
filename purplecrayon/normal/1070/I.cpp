#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}
int hopcroftKarp(vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (int a : cur) for (int b : g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,0,sz(g))
			res += dfs(a, 0, g, btoa, A, B);
	}
}


void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> ed(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        ed[a].push_back(i), ed[b].push_back(i);
    }
    auto deg = [&](int c) -> int { return sz(ed[c]); };
    auto NO = [&](){
        while (m--) cout << 0 << ' ';
        cout << '\n';
        return;
    }; 

    vector<vector<int>> g;
    for (int i = 0; i < n; i++) {
        if (deg(i) < k) continue;
        if (deg(i) > 2*k) {
            NO();
            return;
        }
        for (int j = 0; j < deg(i)-k; j++) for (int rep : {0, 1}) g.push_back(ed[i]);
    }
    vector<int> btoa(m, -1);
    int mx_match = hopcroftKarp(g, btoa);

    if (mx_match != sz(g)) {
        NO();
        return;
    }
    int c = 100499; 
    for (int i = 0; i < m; i++) {
        if (btoa[i] != -1) btoa[i] /= 2;
        else btoa[i] = c-i;
    }
    for (int i = 0; i < m; i++) cout << btoa[i]+1 << ' '; cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}