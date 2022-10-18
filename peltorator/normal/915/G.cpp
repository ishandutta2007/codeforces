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

const ll MOD = 1e9 + 7;

ll binpow(ll x, ll y)
{
    if (!y)
        return 1;
    if (y % 2)
        return (x * binpow(x, y - 1) % MOD);
    return binpow(x * x % MOD, y / 2);
}

const int N = 2000001;

ll a[N];
vector<int> b[N];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 2; i <= k; i++)
        for (int j = i; j <= k; j += i)
            b[j].push_back(i);
    ll ans = 0;
    a[1] = 1;
    ll cur = 0;
    for (int i = 2; i <= k; i++)
    {
        if (b[i].size())
            for (int j : b[i])
            {
                int k = i / j;
                cur += a[k] - a[k - 1];
            }
        a[i] = binpow(i, n) - cur;
        a[i] %= MOD;
        a[i] += MOD;
        a[i] %= MOD;
    }
    for (int i = 1; i <= k; i++)
        ans = (ans + (a[i] ^ i)) % MOD;
    cout << ans;
    return 0;
}