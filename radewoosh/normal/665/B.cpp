#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int tab[1007];

int wyn;

int x;

int y;

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i=1; i<=k; i++)
    scanf("%d", &tab[i]);
    for (int i=1; i<=n*m; i++)
    {
        scanf("%d", &x);
        for (int i=1; i<=k; i++)
        {
            if (tab[i]==x)
            {
                y=i;
            }
        }
        while(y>1)
        {
            swap(tab[y], tab[y-1]);
            y--;
            wyn++;
        }
        wyn++;
    }
    printf("%d\n", wyn);
    return 0;
}