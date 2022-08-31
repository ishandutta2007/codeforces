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
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
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

const int maxN = 700;
bool dp[maxN][maxN][2];
int a[maxN];
bool g[maxN][maxN];

void solve() {
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n) {
        rep(j, n) {
            g[i][j] = (__gcd(a[i], a[j]) != 1);
        }
    }
    for (int l = n - 1; l >= 0; --l) {
        dp[l][l][0] = dp[l][l][1] = true;
        for (int mid = l; mid < n; ++mid) {
            if (l < mid && dp[l + 1][mid][1]) {
                for (int r = mid; r < n; ++r) {
                    dp[l][r][0] |= (dp[mid][r][0] & g[l][mid]);
                }
            }
        }
        for (int mid = l; mid < n; ++mid) {
            if (dp[l][mid][1]) {
                for (int r = mid + 1; r < n; ++r) {
                    // dp[l][r][1] = (dp[l][mid][1] & dp[mid][r-1][0] & g[mid][r])
                    dp[l][r][1] |= (dp[mid][r - 1][0] & g[mid][r]);
                }
            }
        }
    }
    rep(root, n) {
        if (dp[0][root][1] && dp[root][n - 1][0]) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}