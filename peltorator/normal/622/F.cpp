#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef double ld;

#define fastRead cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int N = 1000004;
const ll MOD = 1e9 + 7;

ll fact[N], ans[N];

unordered_map<int, int> rev;

ll binpow(ll x, int st)
{
    ll ans = 1;
    for (int i = 30; i >= 0; i--)
    {
        ans *= ans;
        if (ans > MOD)
            ans %= MOD;
        if ((st & (1 << i)))
        {
            ans *= x;
            if (ans > MOD)
                ans %= MOD;
        }
    }
    return ans;
}

void gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    ll x1, y1;
    gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (ll)(a / b) * x;

}

ll revers(ll i)
{
    ll x, y;
    gcd(MOD, i, x, y);
    return y % MOD;
    /*int t = rev[i];
    if (t != 0)
        return rev[i];*/
    //return binpow(i, MOD - 2);
    //rev[i] = t;
  //  return t;
}

int main()
{
   // freopen("in.txt", "r", stdin);
    fastRead;
    ll n, k;
    cin >> n >> k;
    ans[0] = 0;
    for (ll i = 1; i <= k + 1; i++)
        ans[i] = (ans[i - 1] + binpow(i, k)) % MOD;
    if (n <= k + 1)
    {
        cout << ans[n] << endl;
        return 0;
    }
    ll up = 1;
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
   // for (int i = 0; i < N; i++)
    //    rev[fact[i]] = binpow(fact[i], MOD - 2);
    for (ll i = 0; i <= k + 1; i++)
        up = (up * (n - i)) % MOD;
   // for (ll i = 1; i < N; i++)
      //  rev[i] = binpow(i, MOD - 2);
    ll res = 0;
    for (ll i = 0; i <= k + 1; i++)
    {
        ll cur = (up * revers(n - i)) % MOD;
        cur = (cur * ans[i]) % MOD;
        cur = (cur * revers(fact[i])) % MOD;
        cur = (cur * revers(fact[k + 1 - i])) % MOD;
        if ((k + 1 - i) % 2 == 1)
            cur *= -1;
        res = (res + cur) % MOD;
    }
    cout << (res % MOD + MOD) % MOD;
    return 0;
}