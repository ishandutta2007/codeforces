#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

const int MOD = 998244353, N = 510;
int cnk[N][N], val[N][N];

int add(int a, int b){
    return a + b >= MOD ? a + b - MOD : a + b;
}

int sub(int a, int b){
    return a - b < 0 ? a - b + MOD : a - b;
}

int mul(int a, int b){
    return (a * b % MOD);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i < N; i++){
        int now = 1;
        for (int j = 0; j < N; j++){
            val[i][j] = now;
            now = mul(now, i);
        }
    }
    for (int i = 0; i < N; i++){
        cnk[i][0] = 1;
        for (int j = 1; j <= i; j++){
            cnk[i][j] = add(cnk[i - 1][j - 1], cnk[i - 1][j]);
        }
    }
    int n, x, ans = 0;
    cin >> n >> x;
    vector<vector<int>> dp(n + 1, vector<int>(n + x));
    dp[n][0] = 1;
    for (int i = n; i >= 2; i--){
        for (int k = 0; k < x; k++){
            for (int j = 0; j <= i; j++){
                int can = min(x - k, i - 1), now = val[can][j];
                int val = k + can;
                dp[i - j][val] = add(dp[i - j][val], mul(dp[i][k], mul(cnk[i][j], now)));
            }
        }
    }
    for (int f = 0; f <= x; f++) ans = add(ans, dp[0][f]);
    cout << ans << endl;
    return 0;
}