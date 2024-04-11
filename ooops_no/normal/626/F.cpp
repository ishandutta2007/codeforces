#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb emplace_back
#define ll long long
#define int long long

mt19937 rnd(51);

const int MOD = 1e9 + 7;

int add(int a, int b){
    return a + b >= MOD ? a + b - MOD : a + b;
}

int sub(int a, int b){
    return a - b < 0 ? a - b + MOD : a - b;
}

int mul(int a, int b){
    return (a * b) % MOD;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.pb(MOD);
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++){
        vector<vector<int>> dpp(n + 1, vector<int>(k + 1));
        for (int j = 0; j <= n; j++){
            for (int f = 0; f <= k; f++){
                if (j + 1 <= n) dpp[j + 1][f] = add(dpp[j + 1][f], dp[j][f]);
                if (j - 1 >= 0) dpp[j - 1][f] = add(dpp[j - 1][f], mul(dp[j][f], j));
                dpp[j][f] = add(dpp[j][f], mul(dp[j][f], j + 1));
            }
        }
        for (int j = 0; j <= n; j++) for (int f = 0; f <= k; f++) dp[j][f] = 0;
        for (int j = 0; j <= n; j++){
            for (int f = 0; f <= k; f++){
                if (j * (a[i + 1] - a[i]) + f <= k){
                    dp[j][j * (a[i + 1] - a[i]) + f] = add(dp[j][j * (a[i + 1] - a[i]) + f], dpp[j][f]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; i++) ans = add(ans, dp[0][i]);
    cout << ans << endl;
    return 0;
}