#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=500005;
vector<int>e[MAXN];
vector<pair<int,int> >ph[MAXN];
int a[MAXN];
int time_tag,in[MAXN],out[MAXN];
char s[MAXN];
void dfs(int u,int dep)
{
    in[u]=++time_tag;
    ph[dep].push_back(make_pair(time_tag,ph[dep].back().second^a[u]));
    for(int i=0;i<(int)e[u].size();i++)
        dfs(e[u][i],dep+1);
    out[u]=time_tag;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int p;
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&p);
        e[p].push_back(i);
    }
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
        a[i]=(1<<(s[i]-'a'));
    for(int i=1;i<=n;i++)
        ph[i].push_back(make_pair(0,0));
    dfs(1,1);
    while(m--)
    {
        int v,h;
        scanf("%d%d",&v,&h);
        int l=lower_bound(ph[h].begin(),ph[h].end(),make_pair(in[v],-1))-ph[h].begin();
        int r=lower_bound(ph[h].begin(),ph[h].end(),make_pair(out[v]+1,-1))-ph[h].begin()-1;
        int t=ph[h][r].second^ph[h][l-1].second;
        if(t==(t&(-t)))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}