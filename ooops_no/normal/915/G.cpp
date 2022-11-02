#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb emplace_back
#define ll long long
#define int long long

mt19937 rnd(51);

const int MOD = 1e9 + 7;

int mul(int a, int b){
    return (a * b % MOD);
}

int add(int a, int b){
    return a + b >= MOD ? a + b - MOD : a + b;
}

int sub(int a, int b){
    return a - b < 0 ? a - b + MOD : a - b;
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

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    int n, k;
    cin >> n >> k;
    vector<int> pw(k + 1), dp(k + 1);
    for (int i = 1; i <= k; i++){
        pw[i] = binpow(i, n);
    }
    int ans = 0, sum = 0;
    for (int i = 1; i <= k; i++){
        dp[i] = add(dp[i], sub(pw[i], pw[i - 1]));
        sum = add(sum, dp[i]);
        ans = add(ans, sum ^ i);
        for (int j = i + i; j <= k; j += i){
            dp[j] = sub(dp[j], dp[i]);
        }
    }
    cout << ans << endl;
    return 0;
}