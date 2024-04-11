#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long

mt19937 rnd(51);

const int MOD = 998244353, N = 1e5 + 10;

int dp[2][N];
vector<int> all[2];

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
        int n, ans = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int now = 0;
        for (int i = n - 1; i >= 0; i--){
            all[now].pb(a[i]);
            dp[now][a[i]] = 1;
            int last = a[i];
            for (auto to : all[now ^ 1]){
                int dl = (a[i] + to - 1) / to;
                int val = a[i] / dl;
                ans = (ans + (ll)(dl - 1) * dp[now ^ 1][to] * (i + 1)) % MOD;
                dp[now][val] += dp[now ^ 1][to];
                if (last != val){
                    all[now].pb(val);
                    last = val;
                }
            }
            for (auto to : all[now ^ 1]){
                dp[now ^ 1][to] = 0;
            }
            all[now ^ 1].clear();
            now ^= 1;
        }
        cout << ans << '\n';
        for (auto to : all[0]) dp[0][to] = 0;
        for (auto to : all[1]) dp[1][to] = 0;
        all[0].clear(), all[1].clear();
    }
    return 0;
}