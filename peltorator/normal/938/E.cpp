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

#define deb(a) cerr << #a << " = " << (a) << "\n"
#define deb2(a, b) deb(a); deb(b)
#define deb3(a, b, c) deb(a); deb(b); deb(c)
#define deb4(a, b, c, d) deb(a); deb(b); deb(c); deb(d)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1000001;
const ll MOD = 1e9 + 7;

ll fact[N];
int a[N];

ll binpow(ll x, ll y)
{
    if (!y)
        return 1;
    if (y & 1)
        return (x * binpow(x, y - 1)) % MOD;
    return binpow((x * x) % MOD, y / 2);
}

int main()
{
  //  freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int n;
  //  cin >> n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
//        cin >> a[i];
        scanf("%d", &a[i]);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = ((ll)i * fact[i - 1]) % MOD;
    ll ans = 0;
    int k = 0;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        while (a[k] < a[i])
            k++;
        if (a[i] == a[n - 1])
            break;
        ans = (ans + ((ll)a[i] * fact[n] % MOD) * binpow(n - k, MOD - 2)) % MOD;
    }
    cout << (ans % MOD + MOD) % MOD;
    return 0;
}