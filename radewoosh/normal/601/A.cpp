#include <bits/stdc++.h>
using namespace std;

int n, m;

int p1, p2;
int mac[407][407];

int odl[407];
int bylo[407];

int musi;

queue <int> bfs;

int u;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d", &p1, &p2);
        mac[p1][p2]=1;
        mac[p2][p1]=1;
    }
    for (int i=1; i<=n; i++)
    {
        odl[i]=-1;
    }
    musi=(mac[1][n])^1;
    bfs.push(1);
    odl[1]=0;
    bylo[1]=1;
    while(!bfs.empty())
    {
        u=bfs.front();
        bfs.pop();
        for (int i=1; i<=n; i++)
        {
            if (mac[u][i]==musi && !bylo[i])
            {
                odl[i]=odl[u]+1;
                bfs.push(i);
                bylo[i]=1;
            }
        }
    }
    printf("%d\n", odl[n]);
    return 0;
}