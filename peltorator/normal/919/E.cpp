#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef double ld;

ll p;

ll binpow(ll x, ll y)
{
    if (!y)
        return 1;
    if ((y & 1))
        return (binpow(x, y - 1) * x) % p;
    return binpow((x * x) % p, (y >> 1));
}

ll rev(ll k)
{
    return binpow(k, p - 2);
}

ll rev(ll a, ll m)
{
    if (a == 1)
        return 1;
    return (1 - rev(m % a, a) * m) / a + m;
}

int main()
{
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    ll a, b;
    ll x;
    cin >> a >> b >> p >> x;
    ll ans = 0;
    ll reva = rev(a);
    ll cur = 1, revcur = 1;
    ll revp = 1;
    ll revp1 = rev(p - 1);
    ll MOD = p * (p - 1);
    ll q = x / MOD;
    ll tau = q * MOD;
    for (ll i = 0; i <= p - 2; i++)
    {
        ll t = (revcur * b) % p;
        ll n = ((t * (p - 1) % MOD) * revp1 + (i * p % MOD) * revp) % MOD;
        ans += q;
        if (tau + n <= x)
            ans++;
        cur = (cur * a) % p;
        revcur = (revcur * reva) % p;
    }
    cout << ans;
    return 0;
}