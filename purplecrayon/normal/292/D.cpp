#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e4+10, MOD = 1e9+7;

int n, m;
vector<int> pre[MAXN], suf[MAXN];

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

vector<int> merge_state(vector<int> a, vector<int> b) {
    d.init(n);

    vector<int> last_a(n, -1);
    vector<int> last_b(n, -1);
    for (int i = 0; i < n; i++) {
        if (last_a[a[i]] != -1) {
            d.union_sets(i, last_a[a[i]]);
        }
        last_a[a[i]] = i;

        if (last_b[b[i]] != -1) {
            d.union_sets(i, last_b[b[i]]);
        }
        last_b[b[i]] = i;
    }

    vector<int> c(n);
    for (int i = 0; i < n; i++) c[i] = d.find_set(i);
    return c;
}
vector<int> init_state(int a, int b) {
    vector<int> c(n); iota(c.begin(), c.end(), 0);
    c[b] = a;
    return c;
}
int tt = 0;
int cnt(vector<int> a) {
    static int has[MAXN];
    tt++;

    int ans = 0;
    for (int c : a) {
        if (has[c] != tt) ans++;
        has[c] = tt;
    }
    return ans;
}

void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        pre[i] = suf[i] = init_state(a, b);
    }
    for (int i = 1; i < m; i++) pre[i] = merge_state(pre[i], pre[i-1]);
    for (int i = m-2; i >= 0; i--) suf[i] = merge_state(suf[i], suf[i+1]);

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r, --l, --r;
        if (l == 0 && r == m-1) cout << n << '\n';
        else if (l == 0) cout << cnt(suf[r+1]) << '\n';
        else if (r == m-1) cout << cnt(pre[l-1]) << '\n';
        else cout << cnt(merge_state(pre[l-1], suf[r+1])) << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}