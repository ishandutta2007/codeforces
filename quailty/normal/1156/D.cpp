#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
vector<pair<int,int> > e[MAXN];
int up[MAXN][2],dw[MAXN][2];
ll res;
void dfs(int u,int fa)
{
    up[u][0]=dw[u][1]=1;
    for(auto &t:e[u])
    {
        int v=t.first,c=t.second;
        if(v==fa)continue;
        dfs(v,u);
        if(c==0)
        {
            res+=1LL*up[u][0]*(dw[v][0]+dw[v][1]);
            res+=1LL*(dw[u][0]+dw[u][1])*up[v][0];
            up[u][0]+=up[v][0];
            dw[u][0]+=dw[v][0]+dw[v][1];
        }
        else
        {
            res+=1LL*(up[u][0]+up[u][1])*dw[v][1];
            res+=1LL*dw[u][1]*(up[v][0]+up[v][1]);
            up[u][1]+=up[v][0]+up[v][1];
            dw[u][1]+=dw[v][1];
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        e[x].push_back({y,c});
        e[y].push_back({x,c});
    }
    dfs(1,0);
    printf("%lld\n",res);
    return 0;
}