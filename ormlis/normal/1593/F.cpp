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

int dp[41][40][40][41];

void solve() {
    int n, A, B;
    cin >> n >> A >> B;
    str x;
    cin >> x;
    // dp[pref][a][b][c1]
    rep(a, A) rep(b, B) dp[0][a][b][0] = -228;
    dp[0][0][0][0] = 0;
    rep(i, n) {
        rep(a, A) rep(b, B) rep(c1, i + 2) dp[i + 1][a][b][c1] = -228;
        rep(a, A) {
            int a2 = ((a * 10) + (x[i] - '0')) % A;
            rep(b, B) {
                int b2 = ((b * 10) + (x[i] - '0')) % B;
                rep(c1, i + 1) {
                    if (dp[i][a][b][c1] == -228) continue;
                    dp[i + 1][a2][b][c1 + 1] = (-a - 1);
                    dp[i + 1][a][b2][c1] = b + 1;
                }
            }
        }
    }
    pair<int, int> to = {1e9, -1};
    for(int c1 = 1; c1 < n; ++c1) {
        int c2 = n - c1;
        if (dp[n][0][0][c1] != -228) {
            to = min(to, {abs(c1 - c2), c1});
        }
    }
    if (to.second == -1) {
        cout << "-1\n";
        return;
    }
    int c1 = to.second;
    int a = 0;
    int b = 0;
    str res;
    for(int t = n; t >= 1; --t) {
        assert(dp[t][a][b][c1] != -228);
        if (dp[t][a][b][c1] < 0) {
            res += 'R';
            a = (-dp[t][a][b][c1])-1;
            c1--;
        } else {
            res += 'B';
            b = dp[t][a][b][c1] - 1;
        }
    }
    reverse(all(res));
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}