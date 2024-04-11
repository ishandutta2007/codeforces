#include <bits/stdc++.h>
using namespace std;

int n;

char co[1000007][2];
int tab[1000007];

int pocz=0;


int w[1000007];

int wyn;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%s%d", co[i], &tab[i]);
    }
    for (int i=1; i<=n; i++)
    {
        if (co[i][0]=='-' && !w[tab[i]])
        {
            pocz++;
            continue;
        }
        if (co[i][0]=='+')
        {
            w[tab[i]]++;
        }
        if (co[i][0]=='-')
        {
            w[tab[i]]--;
        }
    }
    wyn=pocz;
    for (int i=1; i<=n; i++)
    {
        if (co[i][0]=='+')
        {
            pocz++;
        }
        if (co[i][0]=='-')
        {
            pocz--;
        }
        wyn=max(wyn, pocz);
    }
    printf("%d\n", wyn);
    return 0;
}