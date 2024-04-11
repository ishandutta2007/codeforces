#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

const int MOD = 1e9 + 7, N = 3e6 + 10;
int f[N], inv_f[N];

int add(int a, int b){
    return a + b >= MOD ? a + b - MOD : a + b;
}

int sub(int a, int b){
    return a - b < 0 ? a - b + MOD : a - b;
}

int mul(int a, int b){
    return (a * b % MOD);
}

int binpow(int a, int n){
    int res = 1;
    while(n){
        if (n & 1){
            res = mul(res, a);
        }
        a = mul(a, a);
        n /= 2;
    }
    return res;
}

int inv(int a){
    return binpow(a, MOD - 2);
}

int cnk(int n, int k){
    if (k > n) return 0;
    return mul(f[n], mul(inv_f[k], inv_f[n - k]));
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; i++){
        f[i] = (i > 0 ? mul(f[i - 1], i) : 1);
        inv_f[i] = inv(f[i]);
    }
    int n, q;
    cin >> n >> q;
    vector<vector<int>> dp(3 * n + 1, vector<int>(3));
    dp[0][0] = dp[0][1] = dp[0][2] = n + 1;
    int inv3 = inv(3);
    for (int i = 1; i <= 3 * n; i++){
        dp[i][0] = mul(sub(sub(cnk(3 * (n + 1), i + 1), mul(dp[i - 1][0], 2)), dp[i - 1][1]), inv3);
        dp[i][1] = add(dp[i][0], dp[i - 1][0]);
        dp[i][2] = add(dp[i][1], dp[i - 1][1]);
    }
    for (int i = 0; i < q; i++){
        int a;
        cin >> a;
        cout << dp[a][0] << '\n';
    }
    return 0;
}