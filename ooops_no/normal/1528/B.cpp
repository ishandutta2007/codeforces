#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MOD = 998244353;

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n + 2);
    vector<int> del(n + 1);
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j += i){
            del[j]++;
        }
    }
    int now = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = (now + del[i]) % MOD;
        now = (dp[i] + now) % MOD;
    }
    cout << dp[n] << endl;
    return 0;
}