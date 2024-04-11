#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
const int MAXN = 1e5+10, MOD = 777777777;


#define ll long long
using ld = long double;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void upd(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll qry(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (++pos; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};
int n, a[MAXN];

#undef ll

using ll = long double;

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], --a[i];

    FT inv(n), seg(n);
    ll no_range = 0, num_ranges = ll(n)*(n+1)/2;
    for (int i = 0; i < n; i++) {
        ll cur_inv = inv.qry(n-1)-inv.qry(a[i]);
        ll tot_left = seg.qry(n-1)-seg.qry(a[i]);

        int right = n-i;

        ll sum_range = tot_left*right;
        no_range += num_ranges*cur_inv - sum_range;

        inv.upd(a[i], 1), seg.upd(a[i], i+1);
    }
    ld ans = ld(no_range);
    for (int range_size = 1; range_size <= n; range_size++) {
        int cnt_ranges = n-range_size+1;
        ll exp_inv = ll(range_size)*(range_size-1)/2;
        ld cur = ld(cnt_ranges)*ld(exp_inv)/ld(2);
        ans += cur;
    }
    cout << fixed << setprecision(15);
    cout << ans/ld(num_ranges) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}