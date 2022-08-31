#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;
const ll INF = 1e18 + 10;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

struct DSU {
	vector<int> p, sz;
	void init(int n){ p.resize(n); sz.assign(n, 1); iota(p.begin(), p.end(), 0); }
	int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
	bool union_sets(int a, int b){
		if ((a=find_set(a))==(b=find_set(b))) return false;
		if (sz[a] < sz[b]) swap(a, b);
		p[b]=a, sz[a]+=sz[b], sz[b]=0;
		return true;
	}
} d;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> g(n); for (auto& s : g) cin >> s;
    d.init(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (g[i][j] == '.') {
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (g[ni][nj] != '.') continue;
                d.union_sets(i * m + j, ni * m + nj);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                cout << '.';
                continue;
            }
            set<int> s;
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (g[ni][nj] != '.') continue;
                s.insert(d.find_set(ni * m + nj));
            }
            int ans = 1;
            for (int x : s) ans += d.sz[d.find_set(x)];
            cout << (ans % 10);
        }
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}