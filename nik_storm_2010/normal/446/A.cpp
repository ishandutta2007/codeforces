#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 2e5;

int f1[N], f2[N], a[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    a[0] = -2e9, a[n + 1] = +2e9;
    for (int i = 1; i <= n; i++) f1[i] = (a[i - 1] < a[i]) ? f1[i - 1] + 1 : 1;
    for (int i = n; i >= 1; i--) f2[i] = (a[i + 1] > a[i]) ? f2[i + 1] + 1 : 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i - 1] + 1 < a[i + 1]) ans = max(ans, f1[i - 1] + f2[i + 1] + 1);
        ans = max(ans, f1[i - 1] + 1);
        ans = max(ans, f2[i + 1] + 1);
    }
    printf("%d\n", ans);
    return 0;
}