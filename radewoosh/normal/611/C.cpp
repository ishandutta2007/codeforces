#include <bits/stdc++.h>
using namespace std;

int n, m;

char wcz[1007][1007];

int tab[1007][1007];

int sum[1007][1007];

int q;

int a, b, c, d;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        scanf("%s", wcz[i]+1);
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (wcz[i][j]=='.' && wcz[i+1][j]=='.')
            {
                tab[i*2][j*2-1]=1;
            }
            if (wcz[i][j]=='.' && wcz[i][j+1]=='.')
            {
                tab[i*2-1][j*2]=1;
            }
        }
    }
    for (int i=1; i<=n*2; i++)
    {
        for (int j=1; j<=m*2; j++)
        {
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+tab[i][j];
        }
    }
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        a=a*2-2;
        b=b*2-2;
        c=c*2-1;
        d=d*2-1;
        //printf("%d %d %d %d\n", a, b, c, d);
        printf("%d\n", sum[c][d]-sum[a][d]-sum[c][b]+sum[a][b]);
    }
    return 0;
}