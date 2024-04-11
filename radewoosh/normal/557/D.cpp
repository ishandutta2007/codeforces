#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

vector <int> graf[1000007];
int p1, p2;

long long wyn[5];

long long wiel[3];

int bylo[1000007];

long long poj, dwu;

void dfs(int v, int odl)
{
    bylo[v]=odl;
    wiel[odl]++;
    for (int i=0; i<graf[v].size(); i++)
    {
        if (bylo[graf[v][i]]>=0)
        {
            if (bylo[graf[v][i]]==odl)
            {
                wyn[0]=1;
            }
            continue;
        }
        dfs(graf[v][i], odl^1);
    }
}

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
        bylo[i]=-1;
    }
    for (int i=1; i<=n; i++)
    {
        if (bylo[i]<0)
        {
            wiel[0]=0;
            wiel[1]=0;
            dfs(i, 0);
            if (!wiel[1])
            {
                poj++;
                continue;
            }
            if (wiel[0]==1 && wiel[1]==1)
            {
                dwu++;
                continue;
            }
            wyn[1]+=(wiel[0]*(wiel[0]-1))/2 + (wiel[1]*(wiel[1]-1))/2;
        }
    }
    wyn[2]=dwu*(n-2);
    wyn[3]=(poj*(poj-1)*(poj-2))/6;
    for (int i=0; i<=3; i++)
    {
        if (wyn[i])
        {
            printf("%d %lld", i, wyn[i]);
            return 0;
        }
    }
    return 0;
}