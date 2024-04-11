#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 500010, G = 1010;
int n, q, koren;
ll a[N], d[N];
pair<ll, int> pa[G][G];

int grupa(int x)
{
    return 1 + (x - 1) / koren;
}

void sortirajgrupu(int grp, int neki)
{
    int vel = 0;
    for (int i = neki; i && grupa(i) == grp; i--) pa[grp][++vel] = {a[i], i};
    for (int i = neki + 1; i <= n && grupa(i) == grp; i++) pa[grp][++vel] = {a[i], i};
    sort(pa[grp] + 1, pa[grp] + vel + 1);
}

int main()
{
    scanf("%d %d", &n, &q);
    koren = sqrt(n);
    for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
    for (int i = 1, g = 1; g <= n; i++, g += koren) sortirajgrupu(i, g);
    while (q--)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            int p = grupa(l), q = grupa(r);
            if (p == q)
            {
                for (int i = l; i <= r; i++) a[i] += x;
                sortirajgrupu(p, l);
                continue;
            }
            for (int i = l; i <= n && grupa(i) == p; i++) a[i] += x;
            for (int i = r; i && grupa(i) == q; i--) a[i] += x;
            sortirajgrupu(p, l);
            sortirajgrupu(q, r);
            for (int i = p + 1; i < q; i++) d[i] += x;
        } else
        {
            int x, mi = 0, ma;
            scanf("%d", &x);
            for (int i = 1, g = 1; g <= n; i++, g += koren)
            {
                int gor = min(n, g + koren - 1), vel = gor - g + 1;
                int pos = lower_bound(pa[i] + 1, pa[i] + vel + 1, pair<ll, int>(x - d[i], 1)) - pa[i];
                if (pos <= vel && pa[i][pos].first == x - d[i])
                {
                    mi = pa[i][pos].second;
                    break;
                }
            }
            for (int i = (n + koren - 1) / koren, g = (i - 1) * koren + 1; i; i--, g -= koren)
            {
                int gor = min(n, g + koren - 1), vel = gor - g + 1;
                int pos = lower_bound(pa[i] + 1, pa[i] + vel + 1, pair<ll, int>(x - d[i] + 1, 1)) - pa[i] - 1;
                if (pos && pa[i][pos].first == x - d[i])
                {
                    ma = pa[i][pos].second;
                    break;
                }
            }
            if (mi) printf("%d\n", ma - mi); else
            printf("-1\n");
        }
    }
    return 0;
}