#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <complex>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <cassert>
#include <random>

#define sz(a) (int)((a).size())

using namespace std;

mt19937 rnd(239);

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
    {
        return 1;
    }
    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<ll> > dp(n + 2, vector<ll>((n + 3) / 2, INF)), dp2 = dp;
    dp[0][1] = max(0LL, a[1] - a[0] + 1);
    dp[n - 1][1] = max(0LL, a[n - 2] - a[n - 1] + 1);
    for (int i = 1; i < n - 1; i++)
        dp[i][1] = max(0LL, a[i - 1] - a[i] + 1) + max(0LL, a[i + 1] - a[i] + 1);
    dp2[0][1] = dp[0][1];
    for (int i = 1; i < n; i++)
        dp2[i][1] = min(dp[i][1], dp2[i - 1][1]);
    for (int j = 2; j <= (n + 1) / 2; j++)
        for (int i = 2; i < n; i++)
        {
            ll t = (i + 1 == n ? 0LL : max(0LL, a[i + 1] - a[i] + 1));
            ll q = max(0LL, min(a[i - 2] - 1, a[i - 1]) - a[i] + 1);
            ll z = max(0LL, a[i - 1] - a[i] + 1);
            dp[i][j] = min(dp[i][j], min(dp[i - 2][j - 1] + q, dp2[i - 2][j - 1] + z) + t);
            dp2[i][j] = min(dp[i][j], dp2[i - 1][j]);
        }
    for (int i = 1; i <= (n + 1) / 2; i++)
    {
        ll ans = 1e18;
        for (int j = 0; j < n; j++)
            ans = min(ans, dp[j][i]);
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cerr << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cerr << "_______________________________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}