#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <memory.h>
#include <map>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <deque>

#define deb(a) cerr << "Debug: " << #a << " = " << (a) << "\n"
#define deb2(a, b) deb(a); deb(b)
#define deb3(a, b, c) deb(a); deb(b); deb(c)
#define deb4(a, b, c, d) deb(a); deb(b); deb(c); deb(d)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int N = 100001;

ll u[N];

ll a[N], b[N];

ll binpow(ll x, ll y)
{
    if (!y)
        return 1;
    if (y % 2)
        return (binpow(x, y - 1) * x) % MOD;
    return binpow((x * x) % MOD, y / 2);
}

int main()
{
  //  freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    for (int i = 1; i < N; i++)
    {
        bool ok = true;
        int ii = i;
        int cnt = 0;
        for (int j = 2; j * j <= i; j++)
            if (i % j == 0)
            {
                if (i % (j * j) == 0)
                {
                    ok = false;
                    break;
                }
                cnt++;
                i /= j;
            }
        if (i > 1)
            cnt++;
        i = ii;
        if (ok)
        {
            if (cnt % 2)
                u[i] = -1;
            else
                u[i] = 1;
        }
        else
            u[i] = 0;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
                b[i] += a[j];
    ll ans = 0;
    for (int i = 1; i < N; i++)
        ans = (ans + u[i] * (binpow(2, b[i]) - 1)) % MOD;
    cout << (( ans) % MOD + MOD) % MOD;
    return 0;
}