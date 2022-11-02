#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

const int MOD = 1e9 + 7;

int add(int a, int b){
    return a + b >= MOD ? a + b - MOD : a + b;
}

int sub(int a, int b){
    return a - b < 0 ? a - b + MOD : a - b;
}

void solve(){
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    map<int, int> dp;
    dp[0] = 1;
    int now_bal = 0, now_sum = 1;
    for (int i = 0; i < n; i++){
        int sum = sub(now_sum, dp[now_bal]);
        now_bal += b[i];
        dp[now_bal - b[i]] = add(dp[now_bal - b[i]], sum);
        now_sum = add(now_sum, sum);
    }
    cout << now_sum << endl;
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
        solve();
    }
    return 0;
}