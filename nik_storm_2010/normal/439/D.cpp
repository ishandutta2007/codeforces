#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 200000;

int a[N], b[N], n, m;

ll ans(int x)
{
    ll res = 0;
    for (int i = 0; i < n; i++) res += max(0, x - a[i]);
    for (int i = 0; i < m; i++) res += max(0, b[i] - x);
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    int aa = +2e9, bb = -2e9;
    for (int i = 0; i < n; i++) aa = min(aa, a[i]);
    for (int i = 0; i < m; i++) bb = max(bb, b[i]);
    if (aa >= bb)
    {
        puts("0");
        return 0;
    }
    int l = 0, r = 1e9;
    while (r - l > 3)
    {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (ans(m1) <= ans(m2)) r = m2; else l = m1;
    }
    ll good = 1e18;
    for (int i = l; i <= r; i++) good = min(good, ans(i));
    printf("%I64d\n", good);
    return 0;
}