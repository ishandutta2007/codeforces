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
typedef vector<vector<ll> > vvl;

const int N = 100;
const ll MOD = 1e9 + 7;

ll a[N];

vvl v, neytr;

int f(ll x)
{
    if (!x)
        return 0;
    return f(x / 2LL) + (x & 1);
}

vvl prod(vvl a, vvl b)
{
    int n = a.size();
    vvl c(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
    return c;
}

vvl binpow(vvl a, ll y)
{
    if (!y)
        return neytr;
    if (y % 2)
        return prod(binpow(a, y - 1), a);
    a = binpow(a, y / 2LL);
    return prod(a, a);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    k = k - 1;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    v.assign(n, vector<ll>(n, 0));
    neytr = v;
    for (int i = 0; i < n; i++)
        neytr[i][i] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (f((a[i] ^ a[j])) % 3 == 0)
                v[i][j] = 1;
    v = binpow(v, k);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = (ans + v[i][j]) % MOD;
    cout << ans;
    return 0;
}