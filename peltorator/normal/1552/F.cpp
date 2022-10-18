#ifdef ONPC
    #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char
 
using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long ll;
typedef long double ld;
 
const ll MOD2 = 998244353;
const ll MOD = 2 * MOD2;
 
 
 
int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    vector<int> x(n), y(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> s[i];
    }
    vector<ll> dp(n, 0);
    ll cursum = 1;
    priority_queue<pair<int, int>> q;
    for (int i = n - 1; i >= 0; i--) {
        while (sz(q) && q.top().first > x[i]) {
            cursum = (cursum + MOD - dp[q.top().second]) % MOD;
            q.pop();
        }
        dp[i] = (cursum + s[i] - 1 + MOD) % MOD;
        q.push({y[i], i});
        cursum = (cursum + dp[i]) % MOD;
    }
    ll ans = (x[n - 1] + 1) % MOD;
    for (int i = 0; i < n; i++) {
        ans = (ans + dp[i] * (x[i] - y[i])) % MOD;
    }
    cout << ans % MOD2 << '\n';
    return 0;
}
 
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1e9;
    //cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}