#include <cstdio>
#include <cstring>
#include <memory.h>
#include <algorithm>

using namespace std;
const int N = 5000 + 10;

int lcp[N][N], minua[N], minub[N];
char s1[N], s2[N];

void calculate(char (&a)[N], char (&b)[N])
{
    memset(lcp, 0, sizeof(lcp));
    int d1 = strlen(a), d2 = strlen(b);
    for (int i = d1 - 1; i >= 0; i--) for (int j = d2 - 1; j >= 0; j--) if (a[i] == b[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
}

int main()
{
    scanf("%s", &s1);
    scanf("%s", &s2);
    int d1 = strlen(s1), d2 = strlen(s2);
    calculate(s1, s1);
    for (int i = 0; i < d1; i++)
    {
        minua[i] = 0;
        for (int j = 0; j < d1; j++) if (i != j) minua[i] = max(minua[i], lcp[i][j]);
        minua[i]++;
    }
    calculate(s2, s2);
    for (int i = 0; i < d2; i++)
    {
        minub[i] = 0;
        for (int j = 0; j < d2; j++) if (i != j) minub[i] = max(minub[i], lcp[i][j]);
        minub[i]++;
    }
    calculate(s1, s2);
    int ans = 2e9;
    for (int i = 0; i < d1; i++) for (int j = 0; j < d2; j++) if (lcp[i][j] >= max(minua[i], minub[j])) ans = min(ans, max(minua[i], minub[j]));
    if (ans == 2e9) puts("-1"); else printf("%d\n", ans);
    return 0;
}