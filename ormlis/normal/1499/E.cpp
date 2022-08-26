#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;

using namespace std;
//using namespace __gnu_pbds;

const int INFi = 2e9 + 5;
const int maxN = 2e7 + 5;
const int md = 998244353;
const ll INF = 2e18;

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

void solve() {
    string x, y;
    cin >> x >> y;
    int n = x.size();
    int m = y.size();
    vector<vector<ar<int, 2>>> dp(n, vector<ar<int, 2>>(m));
    int ans = 0;
    vector<int> al(n), bl(m);
    int l = 0;
    range(i, n) {
        if (i && x[i] == x[i - 1]) l = i;
        al[i] = l;
    }
    l = 0;
    range(i, m) {
        if (i && y[i] == y[i - 1]) l = i;
        bl[i] = l;
    }
    range(i, n) {
        range(j, m) {
            if (x[i] != y[j]) {
                dp[i][j][0] = j - bl[j] + 1;
                dp[i][j][1] = i - al[i] + 1;
            }
            if (i) {
                if (x[i] != x[i - 1]) dp[i][j][0] = add(dp[i][j][0], dp[i - 1][j][0]);
                if (x[i] != y[j]) dp[i][j][0] = add(dp[i][j][0], dp[i - 1][j][1]);
            }
            if (j) {
                if (y[j] != y[j - 1]) dp[i][j][1] = add(dp[i][j][1], dp[i][j - 1][1]);
                if (y[j] != x[i]) dp[i][j][1] = add(dp[i][j][1], dp[i][j - 1][0]);
            }
            ans = add(ans, dp[i][j][0]);
            ans = add(ans, dp[i][j][1]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}