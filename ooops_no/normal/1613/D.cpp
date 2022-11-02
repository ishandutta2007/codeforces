#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

const int MOD = 998244353, N = 2e5 + 10;

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

int solve(int n, vector<int> a){
    vector<int> dp(n + 3);
    map<int,int> cnt;
    for (auto to : a) cnt[to]++;
    dp[0] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++){
        cnt[a[i]]--;
        if (a[i] > 0){
            int val = dp[a[i] - 1];
            val = mul(val, binpow(2, cnt[a[i] - 2] + cnt[a[i]]));
            ans = add(ans, val);
        }
        dp[a[i] + 1] = add(dp[a[i] + 1], add(dp[a[i]], dp[a[i] + 1]));
    }
    for (auto to : dp) ans = add(ans, to);
    return sub(ans, 1);
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
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve(n, a) << endl;
    }
    return 0;
}