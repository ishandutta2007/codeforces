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


const int N = 59;

bool dp[N][N];

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
    {
        return 1;
    }
    ll ans = 0;
    int k;
    cin >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> p(n);
    p[0] = a[0];
    for (int i = 1; i < n; i++)
        p[i] = p[i - 1] + a[i];
    for (ll bit = 59; bit >= 0; bit--)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dp[i][j] = 0;
        ll T = (1LL << bit);
        ans |= T;
        for (int i = 0; i < n; i++)
            if ((p[i] & ans) == ans)
                dp[i][1] = 1;
        for (int j = 2; j <= k; j++)
            for (int i = 1; i < n; i++)
                for (int l = 0; l < i; l++)
                    if (dp[l][j - 1] && ((p[i] - p[l]) & ans) == ans)
                        dp[i][j] = 1;
        if (!dp[n - 1][k])
            ans ^= T;
    }
    cout << ans << endl;
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