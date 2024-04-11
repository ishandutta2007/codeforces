#include <cstdio>
#include <algorithm>

using namespace std;
const int ALPHA = 256;

int a[ALPHA];

int main()
{
    int n, m;
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++)
    {
        char c;
        scanf("%c", &c);
        a[c]++;
    }
    for (int i = 0; i < ALPHA; i++) for (int j = i + 1; j < ALPHA; j++) if (a[i] < a[j]) swap(a[i], a[j]);
    long long ans = 0;
    for (int i = 0; i < ALPHA; i++)
    {
        int x = min(m, a[i]);
        m -= x;
        ans += 1LL * x * x;
    }
    printf("%I64d\n", ans);
    return 0;
}