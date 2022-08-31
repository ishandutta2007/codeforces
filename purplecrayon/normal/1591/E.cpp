#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e6+10, MOD = 998244353;

struct FT {
	vector<ll> s;
    FT(){}
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos]
        pos = min(pos, sz(s) - 1);
		ll res = 0;
		for (pos++; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(int start, ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
        ll prv = query(start - 1);
        sum += prv;

		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
        assert(pos >= start);
		return pos;
	}
} ft; 


int n, q, a[MAXN], ans[MAXN];
vector<int> adj[MAXN];
vector<ar<int, 3>> qs[MAXN];

int cnt[MAXN];
set<int> st[MAXN];

void dfs(int c) {
    if (cnt[a[c]]) {
        ft.update(cnt[a[c]], -1);
        st[cnt[a[c]]].erase(a[c]);
    }
    cnt[a[c]]++;
    ft.update(cnt[a[c]], +1);
    st[cnt[a[c]]].insert(a[c]);

    for (auto [l, k, i] : qs[c]) {
        int occ = ft.lower_bound(l, k);
        if (occ == -1 || !sz(st[occ])) {
            ans[i] = -1;
            continue;
        }
        ans[i] = *st[occ].begin() + 1;
    }
    for (int nxt : adj[c]) dfs(nxt);

    ft.update(cnt[a[c]], -1);
    st[cnt[a[c]]].erase(a[c]);
    cnt[a[c]]--;
    if (cnt[a[c]]) {
        ft.update(cnt[a[c]], +1);
        st[cnt[a[c]]].insert(a[c]);
    }
}
void solve(){
    cin >> n >> q;
    for (int i = 0; i < n; i++) adj[i].clear(), qs[i].clear(), cnt[i] = 0, st[i].clear();
    for (int i = 0; i < n; i++) cin >> a[i], --a[i];
    for (int i = 1; i < n; i++) {
        int p; cin >> p, --p;
        adj[p].push_back(i);
    }
    for (int qt = 0; qt < q; qt++) {
        int c, l, k; cin >> c >> l >> k, --c;
        qs[c].push_back({l, k, qt});
    }
    ft = FT(n + 1);
    dfs(0);
    for (int i = 0; i < q; i++) cout << ans[i] << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}