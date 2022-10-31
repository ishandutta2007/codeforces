#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int MOD = 998244353;

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
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(26));
    vector<int> dp(1 << n);
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (auto to : s){
            a[i][to - 'a']++;
        }
    }
    int show = 0;
    for (int i = 1; i < (1 << n); i++){
        int ans = 1;
        vector<int> mn(26, 1e9);
        for (int k = 0; k < n; k++){
            if (i & (1 << k)){
                for (int f = 0; f < 26; f++){
                    mn[f] = min(mn[f], a[k][f]);
                }
            }
        }
        for (int f = 0; f < 26; f++){
            ans = mul(ans, mn[f] + 1);
        }
        if (__builtin_popcount(i) & 1) dp[i] = ans;
        else dp[i] = sub(0, ans);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < (1 << n); j++){
            if (j & (1 << i)){
                dp[j] = add(dp[j], dp[j ^ (1 << i)]);
            }
        }
    }
    for (int i = 1; i < (1 << n); i++){
        int sum = 0;
        for (int k = 0; k < n; k++){
            if (i & (1 << k)) sum += k + 1;
        }
        sum *= (int)__builtin_popcount(i);
        show ^= dp[i] * sum;
    }
    cout << show << endl;
    return 0;
}