#include <cstdio>

using namespace std;

int main()
{
    int n, i, ans;

    scanf("%d", &n);
    ans = n / 2 + 1;

    printf("%d", ans);

    for (i = 1; i <= ans; ++i) printf("\n%d 1", i);
    for (i = 2; i <= n - ans + 1; ++i) printf("\n%d %d", ans, i);

    return 0;
}