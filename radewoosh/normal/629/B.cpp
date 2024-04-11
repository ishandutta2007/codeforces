#include <bits/stdc++.h>
using namespace std;

int n;

char wcz[17];

int a, b;

int ilej[1007];
int iled[1007];

int wyn;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%s", wcz);
        scanf("%d%d", &a, &b);
        if (wcz[0]=='M')
        {
            for (int j=a; j<=b; j++)
            {
                ilej[j]++;
            }
        }
        else
        {
            for (int j=a; j<=b; j++)
            {
                iled[j]++;
            }
        }
    }
    for (int i=1; i<=1000; i++)
    wyn=max(wyn, min(ilej[i], iled[i]));
    printf("%d\n", wyn*2);
    return 0;
}