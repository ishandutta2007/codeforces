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

const ll MOD = 998244353;

ll binpow(ll x, ll n)
{
    if (!n)
        return 1;
    if (n % 2)
        return (x * binpow(x, n - 1)) % MOD;
    return binpow((x * x) % MOD, n / 2);
}

const int N = 2000001;

ll fact[N];

ll c(ll n, ll k)
{
    ll ans = fact[n] * binpow(fact[k], MOD - 2);
    ans %= MOD;
    ans *= binpow(fact[n - k], MOD - 2);
    ans %= MOD;
    return ans;
}

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
    {
        return 1;
    }
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * (ll)i) % MOD;
    ll res = 0;
    for (ll k = 1; k <= n; k++)
    {
        res = (res + ((ll)(k % 2 ? 3 : -3) * ((binpow(binpow(3, n - k) - 1, n) - binpow(binpow(3, n - k), n)) * c(n, k))) % MOD) % MOD;
    }
    res += (binpow(binpow(3, n), n) - binpow(binpow(3, n) - 3LL, n)) * 2;
    res %= MOD;
    res += MOD;
    res %= MOD;
    cout << res << endl;
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