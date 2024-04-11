#include <cstdio>

using namespace std;

int main()
{
    int n, s;
    scanf("%d %d", &n, &s);
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a > s || (a == s && b != 0)) continue;
        if (b == 0) b = 100;
        if (ans < 100 - b) ans = 100 - b;
    }
    printf("%d\n", ans);
    return 0;
}