#include <bits/stdc++.h>
using namespace std;

int n, m;

vector <int> graf[1000007];

vector <int> grafzt[1000007];
vector <int> grafzn[1000007];

int k;
int x;

int ok[1000007];

int wyn[1000007];
int odw[1000007];

vector <int> grafdo[1000007];

int bylo[1000007];
int sko[1000007];

int czy;

int wie[1000007];

int dfs(int v)
{
    bylo[v]=1;
    for (int i=0; i<grafdo[v].size(); i++)
    {
        if (odw[grafdo[v][i]])
        continue;
        if (!sko[grafdo[v][i]] || (!bylo[sko[grafdo[v][i]]] && dfs(sko[grafdo[v][i]])))
        {
            sko[grafdo[v][i]]=v;
            //printf("do %d przypinamy %d\n", v, grafdo[v][i]);
            czy=1;
            ok[v]=1;
            return 1;
        }
    }
    return 0;
}

int main()
{
    srand(time(0));
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &k);
        while(k--)
        {
            scanf("%d", &x);
            graf[i].push_back(x);
            if (x>0)
            grafzt[x].push_back(i);
            else
            grafzn[-x].push_back(i);
        }
        wie[i]=i;
    }
    for (int i=1; i<=m; i++)
    {
        if (grafzt[i].empty() && grafzn[i].empty())
        continue;
        if ( ((int) (grafzt[i].size()+grafzn[i].size()))==1)
        {
            if (!grafzt[i].empty())
            {
                ok[grafzt[i][0]]=1;
                wyn[i]=1;
                odw[i]=1;
            }
            else
            {
                ok[grafzn[i][0]]=1;
                wyn[i]=0;
                odw[i]=1;
            }
            continue;
        }
        if (grafzt[i].size()==2)
        {
            ok[grafzt[i][0]]=1;
            ok[grafzt[i][1]]=1;
            wyn[i]=1;
            odw[i]=1;
            continue;
        }
        if (grafzn[i].size()==2)
        {
            ok[grafzn[i][0]]=1;
            ok[grafzn[i][1]]=1;
            wyn[i]=0;
            odw[i]=1;
            continue;
        }
        //printf("%d jest nie ok\n", i);
        grafdo[grafzt[i][0]].push_back(i);
        grafdo[grafzn[i][0]].push_back(i);
    }
    czy=1;
    random_shuffle(wie+1, wie+1+n);
    while(czy)
    {
        for (int i=1; i<=n; i++)
        {
            bylo[i]=0;
        }
        czy=0;
        for (int i=1; i<=n; i++)
        {
            if (!ok[wie[i]] && !bylo[wie[i]])
            {
                dfs(wie[i]);
            }
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (!ok[i])
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES\n");
    for (int i=1; i<=m; i++)
    {
        if (sko[i])
        {
            //printf("%d %d   %d\n", i, sko[i], wyn[i]);
            for (int j=0; j<graf[sko[i]].size(); j++)
            {
                //printf("  %d\n", graf[sko[i]][j]);
                if (graf[sko[i]][j]==i)
                wyn[i]=1;
            }
        }
        printf("%d", wyn[i]);
    }
    return 0;
}