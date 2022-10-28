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
const int MAXN = 1e2+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

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

int n, m, d[MAXN][MAXN];

void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++){
        if (i == j) d[i][j] = 0;
        else d[i][j] = 1e9;
    }
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b, --a, --b;
        d[a][b]=1, d[b][a]=1;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
            }
        }
    }
    int s, b; ll k, h; cin >> s >> b >> k >> h;
    vector<vector<int>> g(s);
    vector<int> btoa(b, -1);
    vector<ar<ll, 3>> sv(s);
    vector<ar<ll, 2>> bv(b);
    for (auto& it : sv) cin >> it[0] >> it[1] >> it[2], --it[0];
    for (auto& it : bv) cin >> it[0] >> it[1], --it[0];
    //cerr << "AD\n";
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < b; j++) if (sv[i][1] >= bv[j][1] && d[sv[i][0]][bv[j][0]] <= sv[i][2]){
            g[i].push_back(j);
            //cerr << i << ' ' << j << '\n';
        }
    }
    int matching = hopcroftKarp(g, btoa);
    //cerr << "BTOA "; for (auto& it : btoa) //cerr << it << ' '; //cerr << '\n';
    //cerr << "MATCHING " << matching << '\n';
    ll ans=1e18;
    for (int nm = 0; nm <= s; nm++){
        int moved = max(nm-(s-matching), 0);
        ll c=nm*h+(matching-moved)*k;
        //cerr << nm << ' ' << c << '\n';
        ans = min(ans, c);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}