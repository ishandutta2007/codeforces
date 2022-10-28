#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void upd(int pos, ll dif) {
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll qry(int pos) { 
		ll res = 0;
		for (++pos; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};

int n, a[MAXN];
map<int, int> mp;
ll cnt[MAXN];

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], mp[a[i]]++;

    int cc = 0;
    for (auto& x : mp)
        x.second = cc++;

    FT left(n);
    for (int i = 0; i < n; i++) {
        cnt[i] += ll(n-i)*left.qry(mp[a[i]]);
        left.upd(mp[a[i]], i+1);
    }
    FT right(n);
    for (int i = n-1; i >= 0; i--) {
        cnt[i] += ll(i+1)*right.qry(mp[a[i]]);
        right.upd(mp[a[i]], n-i);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cnt[i] += ll(i+1)*ll(n-i);
        ans += cnt[i]%MOD*a[i]%MOD;
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}