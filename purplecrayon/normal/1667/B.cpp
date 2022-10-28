#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 5e3+10, MOD = 1e9+7;
const ll INF = 1e18+10;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tree {
	typedef int T;
	static constexpr T unit = -MOD;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void upd(int pos, T val) {
        s[pos + n] = f(s[pos+n], val);
		for (pos += n; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T qry(int b, int e) { // query [b, e)
        e++;
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};


void solve() {
    int n; cin >> n;
    vector<ll> a(n); for (auto& x : a) cin >> x;
    vector<ll> pre(n);
    for (int i = 0; i < n; i++) {
        pre[i] = a[i];
        if (i) pre[i] += pre[i-1];
    }

    int cc = 0;
    map<ll, int> mp; mp[0]++;
    for (auto& x : pre) mp[x]++;
    for (auto& [_, v] : mp) v = cc++;


    // in one segtree: pre[l-1]: -l + 1 + dp[l-1] (pre[l-1] < pre[r])
    // in other segtree: pre[l-1]: l - 1 + dp[l-1]

    Tree one(cc), two(cc);
    vector<int> same(cc, -MOD);

    vector<int> dp(n, -MOD);

    auto add = [&](int l, ll me_pre, int me_dp) {
        int c_pre = mp[me_pre];

        one.upd(c_pre, -l + 1 + me_dp);
        two.upd(c_pre, l - 1 + me_dp);
        same[c_pre] = max(same[c_pre], me_dp);
    };

    add(0, 0, 0);
    for (int i = 0; i < n; i++) {
        int c_pre = mp[pre[i]];
        dp[i] = max(dp[i], one.qry(0, c_pre - 1) + i);
        dp[i] = max(dp[i], two.qry(c_pre + 1, cc - 1) - i);
        dp[i] = max(dp[i], same[c_pre]);

        add(i + 1, pre[i], dp[i]);
    }
    cout << dp[n-1] << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}