#include <bits/stdc++.h>
using namespace std;

int n;

int per[100007];

vector <int> dlu[100007];
vector <int> cykl[100007];
int dol[100007];

int bylo[100007];

int oj[100007];

int ileo;

vector < pair <int,int> > kra;

int dfs(int v, int g)
{
    if (bylo[v])
    return 0;
    bylo[v]=1;
    cykl[g].push_back(v);
    return dfs(per[v], g)+1;
}

int fin(int x)
{
    if (oj[x]!=x)
    oj[x]=fin(oj[x]);
    return oj[x];
}

void uni(int x, int y)
{
    if (fin(x)==fin(y))
    return;
    oj[fin(y)]=fin(x);
    if (cykl[x].size()>cykl[y].size())
    swap(x, y);
    for (int i=0; i<cykl[y].size(); i++)
    {
        kra.push_back(make_pair(cykl[y][i], cykl[x][i%cykl[x].size()]));
    }
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &per[i]);
        oj[i]=i;
    }
    for (int i=1; i<=n; i++)
    {
        if (!bylo[i])
        {
            dlu[dfs(i, i)].push_back(i);
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int l=1; l<dlu[i].size(); l++)
        {
            uni(dlu[i][0], dlu[i][l]);
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (dlu[i].empty())
        continue;
        for (int j=i; j<=n; j+=i)
        {
            if (dlu[j].empty() || fin(dlu[i][0])==fin(dlu[j][0]) || fin(dlu[j][0])!=dlu[j][0])
            continue;
            uni(dlu[i][0], dlu[j][0]);
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (!cykl[i].empty() && fin(i)==i)
        {
            ileo++;
        }
    }
    if (ileo>1)
    {
        printf("NO\n");
        return 0;
    }
    if (!dlu[1].empty())
    {
        printf("YES\n");
        for (int i=0; i<n-1; i++)
        {
            printf("%d %d\n", kra[i].first, kra[i].second);
        }
        return 0;
    }
    if (!dlu[2].empty())
    {
        kra.push_back(make_pair(cykl[dlu[2][0]][0], cykl[dlu[2][0]][1]));
        printf("YES\n");
        for (int i=0; i<n-1; i++)
        {
            printf("%d %d\n", kra[i].first, kra[i].second);
        }
        return 0;
    }
    printf("NO\n");
    return 0;
}