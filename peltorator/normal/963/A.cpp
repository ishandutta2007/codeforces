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

const ll MOD = 1e9 + 9;

ll binpow(ll a, ll b)
{
    if (!b)
        return 1;
    if (b % 2)
        return (a * binpow(a, b - 1)) % MOD;
    return binpow((a * a) % MOD, b / 2);
}

ll rev(ll k)
{
    return binpow(k, MOD - 2);
}

int solve()
{
    ios::sync_with_stdio(0);
    ll n;
    if (!(cin >> n))
    {
        return 1;
    }
    ll a, b, k;
    cin >> a >> b >> k;
    vector<ll> s(k);
    string st;
    cin >> st;
    for (int i = 0; i < k; i++)
        if (st[i] == '-')
            s[i] = -1;
        else
            s[i] = 1;
   // if (k * k > n)
    {
        ll ans = 0;
        ll cnt = 0;
        for (int i = 0; i < k; i++)
            cnt = (cnt + s[i % k] * binpow(a, n - i) * binpow(b, i)) % MOD;
        ll bb = binpow(b, k);
        ll aa = rev(binpow(a, k));
        ll x = (aa * bb) % MOD;
        x += MOD;
        x %= MOD;
        ll t = (n + 1) / k;
        ans = (x == 1 ? t * cnt : ((((cnt * (binpow(x, t) - 1LL)) % MOD) * rev(x - 1)))) % MOD;
        ll i = n / k;
        i *= k;
        i -= 5 * k;
        i = max(i, 0LL);
        for (;; i += k)
        {
            if (i + k - 1 > n)
            {
                for (int j = i; j <= n; j++)
                    ans = (ans + s[j % k] * binpow(a, n - j) * binpow(b, j)) % MOD;
                break;
            }
          //  ans = (ans + cnt) % MOD;
           // cnt = (cnt * bb) % MOD;
            //cnt = (cnt * aa) % MOD;
        }
        ans %= MOD;
        ans += MOD;
        ans %= MOD;
        cout << ans << endl;
        return 0;
    }
    
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