#include <bits/stdc++.h>
using namespace std;

int n;

int tab[107][107];

int wyn[107];

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            scanf("%d", &tab[i][j]);
        }
    }
    for (int i=1; i<=n; i++)
    {
        int gdzie=0;
        for (int j=1; j<=n; j++)
        {
            int czy=1;
            if (wyn[j])
            czy=0;
            for (int k=1; k<=n; k++)
            {
                if (wyn[k] || j==k)
                continue;
                if (tab[j][k]>i)
                czy=0;
            }
            if (czy)
            gdzie=j;
        }
        wyn[gdzie]=i;
    }
    for (int i=1; i<=n; i++)
    {
        printf("%d ", wyn[i]);
    }
    printf("\n");
    return 0;
}