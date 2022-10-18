#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 200001, M = 37;

ll a[MAXN];

ll g(ll bit, ll l1, ll r1, ll l2, ll r2)
{
    if (l1 == r1 && l2 == r2)
        return (a[l1] ^ a[l2]);
    if (l1 > r1 || l2 > r2)
        return 1e18 + 7;
    if (bit < 0)
        return 0;
    ll m1 = l1;
    while (m1 <= r1 && (a[m1] & (1LL << bit)) == 0)
        m1++;
    m1--;
    ll m2 = l2;
    while (m2 <= r2 && (a[m2] & (1LL << bit)) == 0)
        m2++;
    m2--;
    //return min(min(g(bit - 1, l1, m1, l2, m2), g(bit - 1, l1, m1, m2 + 1, r2)), 
      //         min(g(bit - 1, m1 + 1, r1, l2, m2), g(bit - 1, m1 + 1, r1, m2 + 1, r2)));
    ll ans = min(g(bit - 1, l1, m1, l2, m2), g(bit - 1, m1 + 1, r1, m2 + 1, r2));
    if (ans > 1e9 + 3)
        ans = min(ans, min(g(bit - 1, l1, m1, m2 + 1, r2), g(bit - 1, m1 + 1, r1, l2, m2)));
    return ans;
}

ll f(ll bit, ll l, ll r)
{
    if (r < l || bit < 0)
        return 0;
    ll m = l;
    while (m <= r && (a[m] & (1LL << bit)) == 0)
        m++;
    m--;
    ll ans = f(bit - 1, l, m) + f(bit - 1, m + 1, r);
    if (m >= l && m < r)
        ans += g(bit, l, m, m + 1, r);
    return ans;
}

int b[MAXN];

int main()
{
    //freopen("in.txt", "r", stdin);
 //   cout.precision(100);
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> b[i];
    sort(b, b + n);
    int t = 0;
    for (int i = 0; i < n; i++)
        if (i == 0 || b[i] != b[i - 1])
            a[t] = b[i], t++;
    n = t;
    cout << f(33, 0, n - 1);
    return 0;
}