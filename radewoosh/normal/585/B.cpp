#include <bits/stdc++.h>
using namespace std;

int t;

int n, k;

int m;

char tab[4][307];
int bylo[4][307];

int czys[5][307];

int czy;

pair <int,int> s;

void dfs(int u, int v)
{
    if (bylo[u][v])
    return;
    bylo[u][v]=1;
    if (v>3*n)
    {
        czy=1;
        return;
    }
    if (!czys[u][v+1] && !czys[u][v+2] && !czys[u][v+3])
    {
        dfs(u, v+3);
    }
    if (u<3 && !czys[u][v+1] && !czys[u+1][v+1] && !czys[u+1][v+2] && !czys[u+1][v+3])
    {
        dfs(u+1, v+3);
    }
    if (u>1 && !czys[u][v+1] && !czys[u-1][v+1] && !czys[u-1][v+2] && !czys[u-1][v+3])
    {
        dfs(u-1, v+3);
    }
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        for (int i=1; i<=3; i++)
        {
            scanf("%s", tab[i]+1);
        }
        m=3*n+5;
        czy=0;
        for (int i=1; i<=3; i++)
        {
            for (int j=1; j<=m; j++)
            {
                bylo[i][j]=0;
                czys[i][j]=0;
            }
        }
        for (int i=1; i<=3; i++)
        {
            for (int j=1; j<=n; j++)
            {
                czys[i][j]=(int) (tab[i][j]>='A' && tab[i][j]<='Z');
            }
        }
        if (tab[1][1]=='s')
        s=make_pair(1, 1);
        if (tab[2][1]=='s')
        s=make_pair(2, 1);
        if (tab[3][1]=='s')
        s=make_pair(3, 1);
        dfs(s.first, s.second);
        if (czy)
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}