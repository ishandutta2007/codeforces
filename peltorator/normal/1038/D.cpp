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
#ifdef ONPC
    #define deb(a) cerr << "       " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

using namespace std;

mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

int a[10];

int dp[13][13];

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    vector<ll> a(n);
    ll sum = 0, ans = -1e18;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += abs(a[i]);
    }
    if (n == 1)
    {
        cout << a[0] << endl;
        return 0;
    }
    for (int i = 0; i + 1 < n; i++)
    {
        ans = max(ans, sum - abs(a[i]) - abs(a[i + 1]) + abs(a[i] - a[i + 1]));
    }
    cout << ans << endl;
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cout << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cout << "__________________________\n";
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}