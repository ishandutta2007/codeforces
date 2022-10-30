#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7, mod = 1e9 + 7;




signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    int n = 2e6;
    vector<int> dp(n + 1);
    if (n >= 3) dp[3] = 4;
    for(int i = 4;i <= n;i++) {
        dp[i] = max((dp[i - 1] + 2 * dp[i - 2]) % mod,
         (4 + dp[i - 2] + 4 * dp[i - 3] + 4 * dp[i - 4]) % mod);
    }   
    while(t--) {
        cin >> n;
        cout << dp[n] << endl;
    }
}