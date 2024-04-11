#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int k1 = 0, k2 = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x == 100) k1++; else k2++;
    }
    for (int i = 0; i <= k1; i++) for (int j = 0; j <= k2; j++) if (i * 100 + j * 200 == (k1 - i) * 100 + (k2 - j) * 200)
    {
        puts("YES");
        return 0;
    }
    puts("NO");
    return 0;
}