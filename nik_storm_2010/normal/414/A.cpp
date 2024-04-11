#include <cstdio>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    if (n == 1)
    {
        if (k > 0) printf("-1"); else printf("1");
        return 0;
    }
    int ost = k - (n / 2) + 1;
    if (ost <= 0)
    {
        printf("-1");
        return 0;
    }
    printf("%d %d ", ost, 2 * ost);
    n -= 2;
    for (int i = 1000000000; n != 0; n--, i--) printf("%d ", i);
    return 0;
}