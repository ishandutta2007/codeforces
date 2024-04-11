#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 2e5;

bool used[N];
int a[N], n;
ll k;

ll points(int x)
{
    ll res = 0;
    for (int i = 1; i <= n; i++) res += min(x, a[i]);
    return res;
}

int main()
{
    scanf("%d %I64d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    ll sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i];
    if (sum < k)
    {
        puts("-1");
        return 0;
    }
    int l = 0, r = 1e9 + 5;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (points(m) <= k) l = m; else r = m;
    }
    k -= points(l);
    for (int i = 1; i <= n; i++) a[i] = max(0, a[i] - l);
    int nom = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0) continue;
        if (k == 0) printf("%d ", i); else
        {
            k--;
            a[i]--;
            if (k == 0) nom = i;
        }
    }
    for (int i = 1; i <= nom; i++) if (a[i] != 0) printf("%d ", i);
    return 0;
}