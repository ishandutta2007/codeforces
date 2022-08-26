#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5 + 1;
const int P = 998244353;
int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int mul(ll a, ll b) {
    return (a * b) % md;
}

int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int dp[1005][1005];

void addt(int &a, int b) {
    a = add(a, b);
}

void solve() {
    int n, m;
    cin >> n >> m >> md;
    vector<vector<int>> a(m, vector<int>(n));
    range(i, m) {
        range(j, n) {
            char s;
            cin >> s;
            a[i][j] = s - '0';
        }
    }
    if (n == m) {
        cout << 1;
        return;
    }

    int need_one = 0, need_two = 0;
    range(i, n) {
        int f = 0;
        range(j, m) {
            f += a[j][i];
        }
        if (f == 0) {
            need_two++;
        } else if (f == 1) {
            need_one++;
        }
    }
    dp[need_one][need_two] = 1;
    for(int n_t = need_two; n_t >= 0; n_t--) {
        for(int n_o = need_one + need_two * 2 - n_t * 2; n_o >= 0; n_o--) {
            if (n_o > 1)
                addt(dp[n_o][n_t], mul(1ll * (n_t + 2) * (n_t + 1) / 2, dp[n_o - 2][n_t + 2]));
            addt(dp[n_o][n_t], mul(1ll * (n_o + 2) * (n_o + 1) / 2, dp[n_o + 2][n_t]));
            addt(dp[n_o][n_t], mul(mul(n_o, n_t + 1), dp[n_o][n_t + 1]));
        }
    }
    cout << dp[0][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}