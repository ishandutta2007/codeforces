#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "@@@@@@@ " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
#define char unsigned char

using namespace std;
mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

const int N = 2123;

ll dp[N][N];

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    vector<ll> a(n);
    for (ll &val : a) {
        cin >> val;
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    auto relax = [&](int i, int j, ll val) {
        dp[i][j] = max(dp[i][j], val);
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (dp[i][j] >= 0) {
                relax(i + 1, j, dp[i][j]);
                relax(i + 1, j + 1, dp[i][j] + a[i]);
            }
        }
    }
    int ans = n;
    while (dp[n][ans] < 0) {
        ans--;
    }
    cout << ans << '\n';
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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