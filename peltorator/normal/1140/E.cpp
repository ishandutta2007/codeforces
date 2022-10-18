#ifdef ONPC
    # define _GLIBCXX_DEBUG
#endif
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
#include <iomanip>

#ifdef ONPC
    #define deb(a) cerr << "      " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

#define sz(a) (a).size()

using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

const ll MOD = 998244353;
const int N = 2e5, T = 2;

ll dp[N][T];


ll f(vector<int> a, ll k)
{
    ll ans = 1;
    int n = a.size();
    for (int i = 1; i < n; i++)
        if (a[i] != -1 && a[i] == a[i - 1])
            return 0;
    int it = 0;
    while (it < n && a[it] == -1)
        it++;
    if (it == n)
    {
        ans = k;
        for (int i = 1; i < n; i++)
            ans = ans * (k - 1) % MOD;
        return ans;
    }
    for (int i = 0; i < it; i++)
        ans = ans * (k - 1) % MOD;
    int it2 = n - 1;
    while (it2 >= 0 && a[it2] == -1)
        it2--, ans = ans * (k - 1) % MOD;
    vector<int> pos;
    for (int i = 0; i < n; i++)
        if (a[i] != -1)
            pos.push_back(i);
    for (int i = 1; i < (int)pos.size(); i++)
    {
        int len = pos[i] - pos[i - 1] - 1;
        if (a[pos[i - 1]] == a[pos[i]])
            ans = ans * dp[len][1] % MOD;
        else
            ans = ans * dp[len][0] % MOD;
    }
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
    return ans;
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    ll k;
    cin >> k;
    dp[0][1] = 0;
    dp[0][0] = 1;
    dp[1][1] = k - 1;
    dp[1][0] = k - 2;
    for (int l = 2; l < N; l++)
    {
        dp[l][1] = dp[l - 1][0] * (k - 1) % MOD;
        //dp[l][1] = ((k - 1) * dp[l - 2][1] + (k - 1) * (k - 2) % MOD * dp[l - 2][0]) % MOD;
        dp[l][0] = (dp[l - 1][1] + (k - 2) * dp[l - 1][0]) % MOD;//(k - 1) * dp[l - 2][0] + (k - 2) * (k - 3) % MOD * dp[l - 2][0]) % MOD;
    }
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i % 2)
            a.push_back(x);
        else
            b.push_back(x);
    }
    cout << f(a, k) * f(b, k) % MOD << endl;
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TI = 1e9;
    //cin >> TI;
    while (TI--)
    {
        if (solve())
            break;
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}