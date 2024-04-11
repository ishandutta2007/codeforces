#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int MOD = 1e9 + 7;

int add(int a, int b){
    return a + b >= MOD ? a + b - MOD : a + b;
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
    int k;
    cin >> k;
    vector<int> dp(6, 1);
    for (int i = 1; i < k; i++){
        vector<int> dpp(6);
        for (int j = 0; j < 6; j++){
            for (int l = 0; l < 6; l++){
                for (int f = 0; f < 6; f++){
                    if (j == l || j == f) continue;
                    if ((j ^ l) == 1 || (j ^ f) == 1) continue;
                    dpp[j] = add(dpp[j], mul(dp[l], dp[f]));
                }
            }
        }
        dp = dpp;
    }
    int ans = 0;
    for (int i = 0; i < dp.size(); i++) ans = add(ans, dp[i]);
    cout << ans << endl;
    return 0;
}