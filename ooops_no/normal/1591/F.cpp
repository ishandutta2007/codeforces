#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
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
    return (a * b) % MOD;
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
    vector<int> a(n + 1), l(n + 1, -1);
    vector<vector<int>> dp(n + 1, vector<int>(2));
    vector<vector<int>> pref(n + 1, vector<int>(2));
    dp[0][0] = pref[0][0] = 1;
    deque<int> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--){
        while(!q.empty() && a[i] < a[q.back()]){
            l[q.back()] = i;
            q.pop_back();
        }
        q.pb(i);
    }
    for (int i = 1; i <= n; i++){
        for (int k = 0; k < 2; k++){
            if (l[i] != -1){
                dp[i][k] = add(mul(sub(pref[i - 1][k ^ 1], pref[l[i] - 1][k ^ 1]), a[i]), dp[l[i]][k]);
            }
            else{
                dp[i][k] = mul(pref[i - 1][k ^ 1], a[i]);
            }
            pref[i][k] = add(pref[i - 1][k], dp[i][k]);
        }
    }
    cout << sub(dp[n][n & 1], dp[n][(n & 1) ^ 1]);
    return 0;
}