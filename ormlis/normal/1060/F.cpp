#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 100;
const int LG = 20;

vi g[maxN];
// for

void merge(vector<ld> &dp1, vector<ld> &dp2) {
    {
        int sz = dp2.size();
        vector<ld> dp(sz + 1);
        for (int i = 1; i < sz; ++i) {
            dp[i + 1] += dp2[i] * (ld) i / (ld) sz;
            for (int t = i + 1; t <= sz; ++t) {
                dp[0] += dp2[i] / (ld) (sz * 2);
                dp[t] += dp2[i] / (ld) (sz * 2);
            }
        }
        for (int t = 1; t <= sz; ++t) {
            dp[t] += dp2[0] / (ld) (sz * 2);
            dp[0] += dp2[0] / (ld) (sz * 2);
        }
        swap(dp2, dp);
    }
    {
        int sz1 = (int) dp1.size() - 1;
        int sz2 = (int) dp2.size() - 1;
        vector<ld> dp(sz1 + sz2 + 1);
        vector<ld> dp_kek(sz1 + 1);
        dp_kek[0] = 1;
        for (int k3 = 1; k3 <= sz1 + sz2; ++k3) {
            vector<ld> dp_kek2(sz1 + 1);
            rep(a, sz1 + 1) {
                int b = k3 - 1 - a;
                if (b > sz2) continue;
                if (b < 0) break;
                int o1 = sz1 - a;
                int o2 = sz2 - b;
                if (o1 >= 1) {
                    ld cur = dp_kek[a] * (ld) o1 / (ld) (o1 + o2);
                    dp_kek2[a + 1] += cur;
                    int k1 = a + 1;
                    for (int k2 = 0; k2 <= b; ++k2) {
                        dp[k3] += dp1[k1] * dp2[k2] * cur;
                    }
                }
                if (o2 >= 1) {
                    ld cur = dp_kek[a] * (ld) o2 / (ld) (o1 + o2);
                    dp_kek2[a] += cur;
                    int k2 = b + 1;
                    for (int k1 = 0; k1 <= a; ++k1) {
                        dp[k3] += dp1[k1] * dp2[k2] * cur;
                    }
                }
            }
            swap(dp_kek, dp_kek2);
        }
        dp[0] += dp1[0] * dp2[0];
        swap(dp, dp1);
    }
}

vector<ld> dfs(int v, int p) {
    vector<ld> dp(1);
    dp[0] = 1;
    for (auto &u : g[v]) {
        if (u == p) continue;
        auto dp2 = dfs(u, v);
        merge(dp, dp2);
    }
    return dp;
}

void solve() {
    int n;
    cin >> n;
    rep(_, n - 1) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int root = 1; root <= n; ++root) {
        auto dp = dfs(root, -1);
        cout << dp[0] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}