#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

int n, m;

int add(int a, int b){
    return a + b >= m ? a + b - m : a + b;
}

int sub(int a, int b){
    return a - b < 0 ? a - b + m : a - b;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int last = 0;
    vector<int> dp(n + 2), pr(n + 2);
    dp[n] = pr[n] = 1;
    for (int i = n - 1; i >= 1; i--){
        dp[i] = pr[i + 1];
        for (int j = 2; j * i <= n; j++){
            dp[i] = add(dp[i], sub(pr[j * i], pr[min(n + 1, j * (i + 1))]));
        }
        pr[i] = add(pr[i + 1], dp[i]);
    }
    cout << dp[1] << endl;
    return 0;
}