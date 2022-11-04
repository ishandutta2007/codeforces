#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
vector<pair<int,int> >e[MAXN];
bool vis[MAXN];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int u,v,l;
        scanf("%d%d%d",&u,&v,&l);
        e[u].push_back(make_pair(v,l));
        e[v].push_back(make_pair(u,l));
    }
    for(int i=1;i<=k;i++)
    {
        int a;
        scanf("%d",&a);
        vis[a]=1;
    }
    int res=INF;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])continue;
        for(int j=0;j<(int)e[i].size();j++)
            if(!vis[e[i][j].first])res=min(res,e[i][j].second);
    }
    printf("%d",(res<INF ? res : -1));
    return 0;
}