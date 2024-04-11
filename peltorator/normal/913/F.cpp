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
#include <complex>
#include <unordered_map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const ll MOD = 998244353;

ll binpow(ll x, ll y)
{
    if (!y)
        return 1;
    if (y % 2)
        return (x * binpow(x, y - 1)) % MOD;
    return binpow((x * x) % MOD, y / 2);
}

ll revers(ll x)
{
    return binpow(x % MOD, MOD - 2);
}

const int N = 2005;

ll cp[N][N];
ll s[N];
ll ppows[N];
ll qpows[N];
ll ans[N];

int main()
{
 //   freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    ll a, b;
    cin >> a >> b;
    ll p = (a * revers(b)) % MOD;

    ppows[0] = qpows[0] = 1;
    for (int i = 1; i < N; i++)
        ppows[i] = (ppows[i - 1] * p) % MOD, qpows[i] = (qpows[i - 1] * (1 - p + MOD)) % MOD;

    for (int i = 0; i < N; i++)
        cp[0][i] = 1;
    s[0] = s[1] = 1;
    ans[0] = ans[1] = 0;

    for (int i = 1; i < N; i++)
        for (int k = i; k < N; k++)
            cp[i][k] = (ppows[k - i] * cp[i - 1][k - 1] + qpows[i] * cp[i][k - 1]) % MOD;

    for (int k = 1; k < N; k++)
    {
        s[k] = 1;
        for (int i = 1; i < k; i++)
            s[k] = (s[k] - s[i] * cp[i][k]) % MOD;
    }

    for (int k = 2; k < N; k++)
    {
        ll cur = 0;
        for (int i = 1; i <= k; i++)
            cur = (cur + (s[i] * cp[i][k] % MOD) * (i * (i - 1) / 2 + i * (k - i) + ans[k - i] + ans[i])) % MOD;
        ans[k] = (cur * revers(1 - s[k] * cp[k][k])) % MOD;
    }
    cout << (ans[n] % MOD + MOD) % MOD;
}