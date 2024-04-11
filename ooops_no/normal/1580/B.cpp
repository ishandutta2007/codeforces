#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = 101;
int MOD, dp[N][N][N], c[N][N];

int add(int a, int b){
    return a + b < MOD ? a + b : a + b - MOD;
}

int mul(int a, int b){
    return (1LL * a * b % MOD);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k >> MOD;
    for (int i = 0; i < N; i++){
        c[i][0] = 1;
        for (int j = 1; j <= i; j++){
            c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
        }
    }
    for (int i = 1; i <= m; i++){
        dp[0][i][0] = 1;
    }
    int val = 1;
    for (int i = 1; i <= n; i++){
        val = mul(val, i);
        dp[i][1][1] = val;
    }
    for (int i = 1; i < m; ++i){
        for (int l = 0; l < n; ++l){
            for (int k1 = 0; k1 <= k; ++k1){
                if (dp[l][i][k1] == 0) continue;
                for (int r = 0; r < n - l; ++r){
                    for (int k2 = 0; k2 < k - k1 + 1; ++k2){
                        if (dp[r][i][k2] == 0) continue;
                        dp[l + r + 1][i + 1][k1 + k2] = add(dp[l + r + 1][i + 1][k1 + k2], mul(c[l + r][l], mul(dp[l][i][k1], dp[r][i][k2])));
                    }
                }
            }
        }
    }
    cout << dp[n][m][k] << endl;
    return 0;
}