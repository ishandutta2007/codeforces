#include <cstdio>

using namespace std;

int main()
{
    int n, c, ans = 0;
    scanf("%d", &n);
    bool was = false;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c);
        if (c == 1) ans++, was = true; else
        {
            if (was) ans++;
            was = false;
        }
    }
    if (c == 0 && ans != 0) ans--;
    printf("%d\n", ans);
    return 0;
}