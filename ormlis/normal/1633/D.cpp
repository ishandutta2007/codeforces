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
const int maxN = 1e3 + 5;
const int LG = 19;

int dp[maxN];

void precalc() {
    rep(i, maxN) dp[i] = i - 1;
    for(int i = 1; i < maxN; ++i) {
        for(int j = 1; j <= i; ++j) {
            int t = i + (i / j);
            if (t < maxN) dp[t] = min(dp[t], dp[i] + 1);
        }
    }
}

void solve() {
    int n, k; cin >> n >> k;
    int m = 1;
    vi rp(m, 0);
    vector<pair<int, int>> A(n);
    rep(i, n) cin >> A[i].first;
    rep(i, n) cin >> A[i].second;
    for(auto &[x, y] : A) {
        m = min(m + dp[x], k + 1);
        rp.resize(m, 0);
        for(int i = m - 1; i >= dp[x]; --i) {
            rp[i] = max(rp[i], rp[i - dp[x]] + y);
        }
    }
    cout << *max_element(all(rp)) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    precalc();
    range(i, t) {
        solve();
    }
    return 0;
}