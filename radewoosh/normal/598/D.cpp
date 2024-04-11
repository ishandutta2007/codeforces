#include <bits/stdc++.h>
using namespace std;

int n, m, k;

char wcz[1007];

int tab[1007][1007];

int wyn[1007][1007];
pair <int,int> oj[1007][1007];

int x, y;

pair <int,int> fin(pair <int,int> v)
{
    if (v!=oj[v.first][v.second])
    oj[v.first][v.second]=fin(oj[v.first][v.second]);
    return oj[v.first][v.second];
}

void uni(pair <int,int> v, pair <int,int> u)
{
    if (fin(v)==fin(u))
    return;
    v=fin(v);
    u=fin(u);
    wyn[u.first][u.second]+=wyn[v.first][v.second];
    oj[v.first][v.second]=u;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i=1; i<=n; i++)
    {
        scanf("%s", wcz+1);
        for (int j=1; j<=m; j++)
        {
            oj[i][j]=make_pair(i, j);
            tab[i][j]=(wcz[j]=='.');
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (tab[i][j])
            {
                wyn[i][j]+=(!tab[i-1][j]);
                wyn[i][j]+=(!tab[i+1][j]);
                wyn[i][j]+=(!tab[i][j-1]);
                wyn[i][j]+=(!tab[i][j+1]);
            }
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (tab[i][j])
            {
                if (tab[i+1][j])
                {
                    uni(make_pair(i, j), make_pair(i+1, j));
                }
                if (tab[i-1][j])
                {
                    uni(make_pair(i, j), make_pair(i-1, j));
                }
                if (tab[i][j+1])
                {
                    uni(make_pair(i, j), make_pair(i, j+1));
                }
                if (tab[i][j-1])
                {
                    uni(make_pair(i, j), make_pair(i, j-1));
                }
            }
        }
    }
    while(k--)
    {
        scanf("%d%d", &x, &y);
        printf("%d\n", wyn[fin(make_pair(x, y)).first][fin(make_pair(x, y)).second]);
    }
    return 0;
}