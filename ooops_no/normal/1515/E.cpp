#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 500;
int c[N][N];

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, MOD;
    cin >> n >> MOD;
    vector<int> po(N);
    po[0] = 1;
    for (int i = 1; i < N; i++){
        po[i] = (po[i - 1] * 2) % MOD;
    }
    c[0][0] = 1;
    for (int i = 1; i < N; i++){
        for (int j = 0; j < N; j++){
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
    vector<vector<int>> dp(n, vector<int>(n + 1));
    for (int i = 0; i < n; i++){
        dp[i][i + 1] = po[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= n; j++){
            for (int k = 1; k <= n; k++){
                if (i + k + 1 < n && j + k <= n){
                    dp[i + k + 1][j + k] = (dp[i + k + 1][j + k] + (dp[i][j] * c[j + k][k]) % MOD * po[k - 1]) % MOD;
                }
            }
        }
    }
    int anss = 0;
    for (int i = 0; i <= n; i++){
        anss = (anss + dp[n - 1][i]) % MOD;
    }
    cout << anss << endl;
    return 0;
}