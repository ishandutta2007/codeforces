#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

const int N = 510, MOD = 1e9 + 7;
int n;
vector<int> a(N);
vector<vector<int>> dp(N, vector<int>(N, -1));

int add(int a, int b){
    return a + b >= MOD ? a + b - MOD : a + b;
}

int mul(int a, int b){
    return (a * b % MOD);
}

int solve(int l, int r){
    if (l >= r){
        dp[l][r] = 1;
    }
    if (dp[l][r] != -1) return dp[l][r];
    dp[l][r] = 0;
    for (int i = l + 1; i <= r; i++){
        if (a[i] > a[l]){
            dp[l][r] = add(dp[l][r], mul(solve(l + 1, i - 1), solve(i, r)));
        }
    }
    if (l + 1 <= r) dp[l][r] = add(dp[l][r], solve(l + 1, r));
    return dp[l][r];
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << solve(1, n - 1) << endl;
    return 0;
}