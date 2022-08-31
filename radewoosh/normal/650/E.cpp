#include <bits/stdc++.h>
using namespace std;

int n;

pair <int,int> kra1[1000007];
vector <int> graf1[1000007];

pair <int,int> kra2[1000007];
vector <int> graf2[1000007];

int oj1[1000007];
int oj2[1000007];

map < pair <int,int> , int > mapa;
map < pair <int,int> , int > raz;
map < pair <int,int> , int > dwa;

int u;

int wyn;

vector < pair <int,int> > wyn1;
vector < pair <int,int> > wyn2;

void dfs1(int v)
{
    for (int i=0; i<graf1[v].size(); i++)
    {
        if (graf1[v][i]==oj1[v])
        continue;
        oj1[graf1[v][i]]=v;
        dfs1(graf1[v][i]);
    }
}

void dfs2(int v)
{
    for (int i=0; i<graf2[v].size(); i++)
    {
        if (graf2[v][i]==oj2[v])
        continue;
        oj2[graf2[v][i]]=v;
        dfs2(graf2[v][i]);
    }
}

void dfs3(int v)
{
    for (int i=0; i<graf1[v].size(); i++)
    {
        if (graf1[v][i]==oj1[v])
        continue;
        dfs3(graf1[v][i]);
        wyn1.push_back(make_pair(v, graf1[v][i]));
        wyn2.push_back(make_pair(oj2[graf1[v][i]], graf1[v][i]));
    }
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<n; i++)
    {
        scanf("%d%d", &kra1[i].first, &kra1[i].second);
        graf1[kra1[i].first].push_back(kra1[i].second);
        graf1[kra1[i].second].push_back(kra1[i].first);
    }
    for (int i=1; i<n; i++)
    {
        scanf("%d%d", &kra2[i].first, &kra2[i].second);
        graf2[kra2[i].first].push_back(kra2[i].second);
        graf2[kra2[i].second].push_back(kra2[i].first);
        mapa[kra2[i]]=1;
        swap(kra2[i].first, kra2[i].second);
        mapa[kra2[i]]=1;
    }
    dfs1(1);
    dfs2(1);
    dfs3(1);
    for (int i=0; i<wyn1.size(); i++)
    {
        if (wyn1[i].first>wyn1[i].second)
        swap(wyn1[i].first, wyn1[i].second);
        if (wyn2[i].first>wyn2[i].second)
        swap(wyn2[i].first, wyn2[i].second);
        raz[wyn1[i]]=i+1;
        dwa[wyn2[i]]=i+1;
    }
    for (int i=0; i<wyn1.size(); i++)
    {
        if (!dwa[wyn1[i]])
        {
            wyn++;
        }
    }
    printf("%d\n", wyn);
    for (int i=0; i<wyn1.size(); i++)
    {
        if (!dwa[wyn1[i]])
        {
            u=i;
            while(raz[wyn2[u]])
            u=raz[wyn2[u]]-1;
            printf("%d %d %d %d\n", wyn1[i].first, wyn1[i].second, wyn2[u].first, wyn2[u].second);
        }
    }
    return 0;
}