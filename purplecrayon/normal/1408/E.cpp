#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

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

int n, m, p[MAXN];
ll a[MAXN], b[MAXN];
vector<pair<ll, ar<int, 2>>> ed;

void solve(){
    cin >> m >> n;
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        while (k--) {
            int c; cin >> c, --c;
            ans += a[i]+b[c];
            ed.emplace_back(a[i]+b[c], ar<int, 2>{i, c});
        }
    }
    sort(ed.rbegin(), ed.rend());

    d.init(n+m);
    for (auto [c, e] : ed) {
        auto [a, b] = e;
        if (d.union_sets(a, b+m)) {
            ans -= c;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}