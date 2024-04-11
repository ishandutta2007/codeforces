#include <bits/stdc++.h>
using namespace std;

int n;

char wcz[207];

int x, y;

int wyn;

int main()
{
    scanf("%d", &n);
    scanf("%s", wcz+1);
    for (int i=1; i<=n; i++)
    {
        x=0;
        y=0;
        for (int j=i; j<=n; j++)
        {
            if (wcz[j]=='U')
            x--;
            if (wcz[j]=='D')
            x++;
            if (wcz[j]=='L')
            y--;
            if (wcz[j]=='R')
            y++;
            if (!x && !y)
            wyn++;
        }
    }
    printf("%d\n", wyn);
    return 0;
}