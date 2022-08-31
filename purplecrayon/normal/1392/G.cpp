#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;
const int K = 20;

struct P {
    vector<int> p;
    P() {}
    P(int n) {
        p.resize(n);
        std::iota(p.begin(), p.end(), 0);
    }
    P mul(const P& he) const {
        assert(sz(p) == sz(he.p));
        P ans(sz(p));
        for (int i = 0; i < sz(p); i++) {
            ans.p[i] = p[he.p[i]];
        }
        return ans;
    }
    string perm(const string& s) const {
        assert(sz(p) == sz(s));
        string ans(sz(p), '?');
        for (int i = 0; i < sz(p); i++) {
            ans[i] = s[p[i]];
        }
        return ans;
    }
};

int get_value(const string& s) {
    int ans = 0;
    for (char c : s) ans *= 2, ans += c - '0';
    return ans;
}

int n, m, k, s_pre[N], t_pre[N];
string s, t;
int dp[1 << K], new_dp[1 << K];

void solve() {
    cin >> n >> m >> k;
    cin >> s >> t;
    P pre(k);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b, --a, --b;
        P cur(k);
        swap(cur.p[a], cur.p[b]);

        pre = cur.mul(pre);

        s_pre[i] = get_value(pre.perm(s));
        t_pre[i] = get_value(pre.perm(t));
    }
    // (S * pre[L-1]) ^ (T * pre[R])
    std::fill(dp, dp + (1 << k), n);
    for (int l = n-1; l >= 0; l--) {
        int cur = l ? s_pre[l-1] : get_value(s);
        dp[cur] = l;
    }

    for (int rep = 0; rep <= k; rep++) {
        for (int r = 0; r < n; r++) {
            if (dp[t_pre[r]] <= r - m + 1) {
                cout << k - rep << '\n';
                cout << dp[t_pre[r]] + 1 << ' ' << r + 1 << '\n';
                return;
            }
        }
        memcpy(new_dp, dp, sizeof(dp));
        for (int mask = 0; mask < (1 << k); mask++) if (dp[mask] != n) {
            for (int b = 0; b < k; b++) {
                new_dp[mask ^ (1 << b)] = min(new_dp[mask ^ (1 << b)], dp[mask]);
            }
        }
        memcpy(dp, new_dp, sizeof(dp));
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}