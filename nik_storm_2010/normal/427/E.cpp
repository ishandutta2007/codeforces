#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int N = 2000000;

int a[N], comp[N], ps[N], n, m;
ll ans;
vector <ll> pref[N];

void check(int x, int l, int r)
{
    ll cur = 0;
    int ost = (l - 1) % m;
    cur += 2LL * (a[l] - a[l - ost]);
    l -= ost + m;
    if (l >= 1)
    {
        int o = comp[l], i = ps[l];
        cur += 2LL * (ll(i + 1) * x - pref[o][i]);
    }
    ost = (n - r) % m;
    cur += 2LL * (a[r + ost] - a[r]);
    r += ost + m;
    if (r <= n)
    {
        int o = comp[r], i = ps[r], j = pref[o].size() - 1;
        cur += 2LL * (pref[o][j] - pref[o][i - 1] - ll(j - i + 1) * x);
    }
    ans = min(ans, cur);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        int o = i % m;
        comp[i] = o;
        ps[i] = pref[o].size();
        ll cur = a[i];
        if (ps[i] != 0) cur += pref[o][ps[i] - 1];
        pref[o].push_back(cur);
    }
    ans = 5e18;
    int i = 1;
    while (i <= n)
    {
        int j = i;
        while (j <= n && a[i] == a[j]) j++;
        check(a[i], i, j - 1);
        i = j;
    }
    printf("%I64d\n", ans);
    return 0;
}