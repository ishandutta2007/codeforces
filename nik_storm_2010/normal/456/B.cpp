#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char s[300000];
    scanf("%s", s);
    int step = 0, power = 1;
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        step += power * (s[i] - '0');
        power *= 10;
        if (power == 100) break;
    }
    int ans = 0, c1 = 1, c2 = 1, c3 = 1, c4 = 1;
    for (int i = 1; i <= step; i++)
    {
        c1 = (c1 * 1) % 5;
        c2 = (c2 * 2) % 5;
        c3 = (c3 * 3) % 5;
        c4 = (c4 * 4) % 5;
    }
    printf("%d\n", (c1 + c2 + c3 + c4) % 5);
    return 0;
}