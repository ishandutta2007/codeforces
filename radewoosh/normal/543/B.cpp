#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;

vector <int> graf[3007];
int p1, p2;

int odl[3007][3007];
queue <int> bfs;
int v;

int wyn;

int s1, t1, l1;
int s2, t2, l2;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d", &p1, &p2);
        graf[p1].push_back(p2);
        graf[p2].push_back(p1);
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            odl[i][j]=1000000;
        }
        odl[i][i]=0;
        bfs.push(i);
        while(!bfs.empty())
        {
            v=bfs.front();
            bfs.pop();
            for (int j=0; j<graf[v].size(); j++)
            {
                if (odl[i][graf[v][j]]==1000000)
                {
                    odl[i][graf[v][j]]=odl[i][v]+1;
                    bfs.push(graf[v][j]);
                }
            }
        }
    }
    scanf("%d%d%d", &s1, &t1, &l1);
    scanf("%d%d%d", &s2, &t2, &l2);
    if (odl[s1][t1]>l1 || odl[s2][t2]>l2)
    {
        printf("-1");
        return 0;
    }
    wyn=odl[s1][t1]+odl[s2][t2];
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (odl[s1][i]+odl[i][j]+odl[j][t1]<=l1 && odl[s2][i]+odl[i][j]+odl[j][t2]<=l2)
            {
                wyn=min(wyn, odl[s1][i]+odl[j][t1]+odl[s2][i]+odl[j][t2]+odl[i][j]);
            }
            swap(s2, t2);
            if (odl[s1][i]+odl[i][j]+odl[j][t1]<=l1 && odl[s2][i]+odl[i][j]+odl[j][t2]<=l2)
            {
                wyn=min(wyn, odl[s1][i]+odl[j][t1]+odl[s2][i]+odl[j][t2]+odl[i][j]);
            }
            swap(s2, t2);
        }
    }
    printf("%d", m-wyn);
    return 0;
}