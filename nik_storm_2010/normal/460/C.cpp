#include <cstdio>
#include <memory.h>

using namespace std;
const int N = 3e5;

int a[N], add[N], n, m, w;

bool check(int need)
{
    memset(add, 0, sizeof(add));
    long long sum = 0, mod = 0;
    for (int i = 1; i <= n; i++)
    {
        mod += add[i];
        long long x = a[i] + mod;
        if (x >= need) continue;
        mod += need - x, sum += need - x;
        add[i + w] += x - need;
    }
    return (sum <= m);
}

int main()
{
    scanf("%d %d %d", &n, &m, &w);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int left = 0, right = 2e9;
    while (right - left > 1)
    {
        int middle = (0LL + left + right) / 2;
        if (check(middle)) left = middle; else right = middle;
    }
    printf("%d\n", left);
    return 0;
}