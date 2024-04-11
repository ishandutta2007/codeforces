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

const int L = 17;
const int N = (1 << L);
const ll MOD = 1e9 + 7;

/*ll fib[N];
ll cnt[N];
ll cntab[N];
ll cntc[N];*/
vector<ll> fib, cnt, cntab, cntc, cntde;

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

void adamar(vector<ll> &a, int l, int r)
{
    if (l + 1 >= r)
        return;
    int mid = (r + l) / 2;
    adamar(a, l, mid);
    adamar(a, mid, r);
    for (int i = l; i < mid; i++)
    {
        ll u = a[i], v = a[i + mid - l];
        a[i] = (u + v) % MOD;
        a[i + mid - l] = (u - v) % MOD;
    }
}

void andamar(vector<ll> &a, int l, int r)
{
    if (l + 1 >= r)
        return;
    int mid = (r + l) / 2;
    andamar(a, l, mid);
    andamar(a, mid, r);
    for (int i = l; i < mid; i++)
        a[i] = (a[i] + a[i + mid - l]) % MOD;
}

void revandamar(vector<ll> &a, int l, int r)
{
    if (l + 1 >= r)
        return;
    int mid = (r + l) / 2;
    revandamar(a, l, mid);
    revandamar(a, mid, r);
    for (int i = l; i < mid; i++)
        a[i] = (a[i] - a[i + mid - l]) % MOD;
}

int main()
{
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    fib.assign(N, 0);
    cnt.assign(N, 0);
    cntab.assign(N, 0);
    cntc.assign(N, 0);
    cntde.assign(N, 0);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ++cnt[x];
    }
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < N; ++i)
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j > 0; j = ((j - 1) & i))
            cntab[i] = (cntab[i] + cnt[j] * cnt[i ^ j]) % MOD;
        cntab[i] = (cntab[i] + cnt[0] * cnt[i]) % MOD;
        cntab[i] %= MOD;
    }
    for (int i = 0; i < N; ++i)
        cntc[i] = cnt[i];
    adamar(cnt, 0, N);
    for (int i = 0; i < N; ++i)
        cntde[i] = (cnt[i] * cnt[i]) % MOD;
    adamar(cntde, 0, N);
    for (int i = 0; i < N; ++i)
        cntde[i] = (cntde[i] * revers(N)) % MOD;
    for (int i = 0; i < N; i++)
    {
        cntab[i] = (cntab[i] * fib[i]) % MOD;
        cntc[i] = (cntc[i] * fib[i]) % MOD;
        cntde[i] = (cntde[i] * fib[i]) % MOD;
    }
    andamar(cntab, 0, N);
    andamar(cntc, 0, N);
    andamar(cntde, 0, N);
    for (int i = 0; i < N; ++i)
        cntc[i] = ((cntc[i] * cntab[i]) % MOD * cntde[i]) % MOD;
    revandamar(cntc, 0, N);
    ll ans = 0;
    for (int i = 0; i < L; ++i)
        ans = (ans + cntc[(1 << i)]) % MOD;
    cout << (ans % MOD + MOD) % MOD;
    return 0;
}