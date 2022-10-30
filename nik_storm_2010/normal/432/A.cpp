#include <cstdio>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    k = 5 - k;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x <= k) cnt++;
    }
    printf("%d\n", cnt / 3);
    return 0;
}