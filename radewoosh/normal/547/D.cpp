#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;

vector < pair <int,int> > graf[1000007];
int p1, p2;
int wyn[1000007];
int bylo[1000007];
int bylo1[1000007];

int wiel=400000;
int l;

void dfs(int v)
{
    pair <int,int> inte;
    bylo1[v]=1;
    while(!graf[v].empty())
    {
        inte=graf[v].back();
        graf[v].pop_back();
        if (!bylo[inte.second])
        {
            bylo[inte.second]=1;
            dfs(inte.first);
            l^=1;
            wyn[inte.second]=l;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d%d", &p1, &p2);
        graf[p1].push_back(make_pair((wiel/2)+p2,i));
        graf[(wiel/2)+p2].push_back(make_pair(p1,i));
    }
    l=n;
    for (int i=1; i<=wiel; i++)
    {
        if (graf[i].size()&1)
        {
            l++;
            graf[0].push_back(make_pair(i,l));
            graf[i].push_back(make_pair(0,l));
        }
    }
    for (int i=0; i<=wiel; i++)
    {
        if (!bylo1[i] && !graf[i].empty())
        {
            l=0;
            dfs(i);
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (wyn[i])
        printf("b");
        else
        printf("r");
    }
    return 0;
}