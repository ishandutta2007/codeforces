#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e2+10, MOD = 1e9+7;

namespace kactl {

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
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

#undef rep
#undef all
};


int n, m, rgt[MAXN][MAXN], down[MAXN][MAXN];
bool g[MAXN][MAXN];

void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) g[i][j] = (s[j] == '#');
    }

    memset(rgt, -1, sizeof(rgt));
    memset(down, -1, sizeof(down));

    int L = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m-1; j++) if (g[i][j] && g[i][j+1]) {
            rgt[i][j] = L++;
        }
    }
    int R = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m; j++)  if (g[i][j] && g[i+1][j]) {
            down[i][j] = R++;
        }
    }

    vector<vector<int>> adj(L);
    vector<int> btoa(R, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<int> horiz;
            if (j && rgt[i][j-1] != -1) horiz.push_back(rgt[i][j-1]);
            if (j < m-1 && rgt[i][j] != -1) horiz.push_back(rgt[i][j]);


            vector<int> vert;
            if (i && down[i-1][j] != -1) vert.push_back(down[i-1][j]);
            if (i < n-1 && down[i][j] != -1) vert.push_back(down[i][j]);

            for (auto a : horiz) for (auto b : vert) {
                adj[a].push_back(b);
            }
        }
    }
    int big = L+R-kactl::hopcroftKarp(adj, btoa);
    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        ans += g[i][j];
    }

    ans -= big;

    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}