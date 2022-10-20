#include <bits/stdc++.h>
#define filein freopen("inp.txt", "r", stdin)
#define fileout freopen("out.txt", "w", stdout)
#define EXTREMELY
#define LIMIT 300010

using namespace std;

int n, m, q, Root, Max, City;
vector <int> c[LIMIT];
int R[LIMIT], LP[LIMIT], ok[LIMIT];

void DFS(int u, int lv, int m)
{
    R[u] = Root;
    if(lv > Max)
    {
        Max = lv;
        City = u;
    }
    ok[u] = m + 1;
    for(int i = 0; i < (int)c[u].size(); i++)
    {
        int v = c[u][i];
        if(ok[v] <= m)
            DFS(v, lv + 1, m);
    }
}

int Getroot(int x)
{
    return (x == R[x])? x : (R[x] = Getroot(R[x]));
}

int main()
{
    //filein, fileout;
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        c[a].push_back(b);
        c[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    if(!ok[i])
    {
        Root = i;
        Max = -1;
        DFS(i, 0, 0);
        Max = -1;
        DFS(City, 0, 1);
        LP[i] = Max;
    }
    for(int i = 1; i <= q; i++)
    {
        int type, x, y;
        scanf("%d", &type);
        if(type == 1)
        {
            scanf("%d", &x);
            printf("%d\n", LP[Getroot(x)]);
        }
        else
        {
            scanf("%d%d", &x, &y);
            x = Getroot(x);
            y = Getroot(y);
            if(x == y) continue;
            int l = max(LP[x], LP[y]);
            R[x] = y;
            LP[y] = max((LP[y] + 1) / 2 + (LP[x] + 1) / 2 + 1, l);
        }
    }
    return 0;
}