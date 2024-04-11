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

int n, q;
ar<int, 2> e[MAXN];

void solve() {
    cin >> n >> q;
    for (int i = 0; i < q; i++) cin >> e[i][0] >> e[i][1], --e[i][0], --e[i][1];
    for (int i = 0; i < q; i++) {
        d.init(n);
        int free = 0;
        for (int j = 0; j <= i; j++) {
            auto [a, b] = e[j];
            if (!d.union_sets(a, b)) {
                free++;
            }
        }
        vector<int> comp;
        for (int i = 0; i < n; i++) if (d.p[i] == i) comp.push_back(d.sz[i]);
        sort(comp.rbegin(), comp.rend());
        int ans = 0;
        for (int i = 0; i < min(sz(comp), free + 1); i++) ans += comp[i];
        cout << ans-1 << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}