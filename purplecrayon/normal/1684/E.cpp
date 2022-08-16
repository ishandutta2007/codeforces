#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e2+10, MOD = 1e9+7;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void upd(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll qry(int pos) { // sum of values in [0, pos]
		ll res = 0;
		for (++pos; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
    ll qry(int l, int r) {
        return qry(r) - qry(l-1);
    }
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

void solve() {
    int n, k; cin >> n >> k; k = min(k, n);
    vector<int> a(n); for (auto& x : a) cin >> x;

    map<int, int> mp;
    set<int> s;
    for (int x : a) mp[x]++, s.insert(x);
    FT bit(n + 1);
    FT cnt(n + 1);
    for (auto& [_, k] : mp) bit.upd(k, +k), cnt.upd(k, +1);

    int hole = 0;
    int ans = n;
    for (int m = 0; m <= n; m++) {
        if (m && !mp[m-1]) hole++;
        else if (m) {
            // can't use previous counts anymore
            bit.upd(mp[m-1], -mp[m-1]);
            cnt.upd(mp[m-1], -1);
        }
        s.erase(m-1);

        if (hole > k) break;
        // find maximum number of things in the set s.t. sum <= k
        int pos = bit.lower_bound(k + 1) - 1;
        int sum = bit.qry(0, pos);
        int cur_ans = 0; // -m for mex + m for elements contributing to mex
        cur_ans += cnt.qry(0, pos);
        cur_ans += (k - sum) / (pos + 1);
        cur_ans = sz(s) - cur_ans;

        ans = min(ans, cur_ans);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}