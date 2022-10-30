#include<cstdio>

using namespace std;
const int N = 20;

char s[N];

bool check(int x)
{
    if (12 % x != 0) return false;
    int g = 12 / x;
    for (int y = 0; y < g; y++)
    {
        int i = y;
        while (i < 12 && s[i] == 'X') i += g;
        if (i >= 12) return true;
    }
    return false;
}

int main()
{
    int tests;
    scanf("%d", &tests);
    for (int i = 0; i < tests; i++)
    {
        scanf("%s", &s);
        int ans = 0;
        for (int a = 1; a <= 12; a++) if (check(a)) ans++;
        printf("%d ", ans);
        for (int a = 1; a <= 12; a++) if (check(a)) printf("%dx%d ", a, 12 / a);
        printf("\n");
    }
    return 0;
}