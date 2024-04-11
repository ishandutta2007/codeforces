#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int MOD = 1e9 + 7;

int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

int sub(int a, int b) {
    return a - b < 0 ? a - b + MOD : a - b;
}

int mul(int a, int b) {
    return (a * b % MOD);
}

int binpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n /= 2;
    }
    return res;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= m; i++) {
            dp[i][i] = mul(i, k);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i != j) dp[i][j] = mul(add(dp[i - 1][j - 1], dp[i - 1][j]), (MOD + 1) / 2);
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}