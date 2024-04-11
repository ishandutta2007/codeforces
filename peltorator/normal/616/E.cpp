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
typedef long double ld;

const ll MOD = 1000000007;

ll binpow(ll x, ll y)
{
    if (!y)
        return 1;
    ll z = binpow(x, y / 2);
    z *= z;
    z %= MOD;
    if (y % 2)
        z = (z * x) % MOD;
    return z;
}

int main()
{
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   // cout.precision(30);
    ll REV = binpow(2, MOD - 2);
   // srand(time(0));
    ll n, m;
    cin >> n >> m;
   // cout << "start:" << endl;
    while (true)
    {
        ll M = m;
        ll ans = 0;
        if (m > n)
        {
            ans = ((n % MOD) * ((m - n) % MOD)) % MOD;
            m = n;
        }
        ll t = sqrt(n);
        ll q = n / t;
        for (ll i = 1; i <= min(q, m); i++)
            ans = (ans + (n % i)) % MOD;
        ans += ((n % MOD) * (max(m - q, 0LL) % MOD)) % MOD;
        ans %= MOD;
        for (ll i = 2; i <= t; i++)
        {
            ll left = n / i;
            ll right = min(m, n / (i - 1));
            if (right < left)
                continue;
            ll cur = (((right % MOD) * ((right + 1) % MOD)) % MOD * REV) % MOD - (((left % MOD) * ((left + 1) % MOD)) % MOD * REV) % MOD;
            cur %= MOD;
            cur *= ((i - 1) % MOD);
            cur %= MOD;
            ans = (ans - cur) % MOD;
        }
        ans = ((ans % MOD) + MOD) % MOD;
        ll real = 0;
       /* for (ll i = 1; i <= M; i++)
            real = (real + (n % i)) % MOD;
        real = ((real % MOD) + MOD) % MOD;*/
        //if (ans < 0 || real != ans)
        {
            cout << ans;
            //cout << n << " " << M << " " << ans << " " << real << " " << t << " " << q;
            return 0;
        }
        n = rand() % 10000000 + 1; 
        m = rand() % 10000000 + 1;
    }
    return 0;
}