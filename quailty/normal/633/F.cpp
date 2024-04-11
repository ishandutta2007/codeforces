#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=100005;
ll a[MAXN],dpl[MAXN][3],dpv[MAXN][2];
vector<int>e[MAXN];
void dfs1(int u,int fa)
{
    bool leaf=1;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        leaf=0;
        dfs1(v,u);
        for(int j=0;j<3;j++)
            if(dpl[v][0]+a[u]>dpl[u][j])
            {
                for(int k=2;k>j;k--)
                    dpl[u][k]=dpl[u][k-1];
                dpl[u][j]=dpl[v][0]+a[u];
                break;
            }
        ll len=max(dpv[v][0],dpl[v][0]+max(dpl[v][1]-a[v],0LL));
        for(int j=0;j<2;j++)
            if(len>dpv[u][j])
            {
                for(int k=1;k>j;k--)
                    dpv[u][k]=dpv[u][k-1];
                dpv[u][j]=len;
                break;
            }
    }
    if(leaf)dpl[u][0]=a[u];
}
void dfs2(int u,int fa,ll nw,ll mx,ll &res)
{
    res=max(res,max(dpv[u][0],dpl[u][0]+max(dpl[u][1]-a[u],0LL))+mx);
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        int loc[2]={2,1};
        for(int j=0;j<2;j++)if(dpl[v][0]+a[u]==dpl[u][j])loc[0]=j;
        if(max(dpv[v][0],dpl[v][0]+max(dpl[v][1]-a[v],0LL))==dpv[u][0])loc[1]=0;
        ll t_nw=max(nw+a[u],(loc[0] ? dpl[u][0] : dpl[u][1]));
        ll t_mx=max(t_mx,nw+a[u]);
        t_mx=max(mx,nw+(loc[0] ? dpl[u][0] : dpl[u][1]));
        t_mx=max(t_mx,(loc[1] ? dpv[u][0] : dpv[u][1]));
        t_mx=max(t_mx,dpl[u][0]+dpl[u][1]+dpl[u][2]-dpl[u][loc[0]]-a[u]);
        dfs2(v,u,t_nw,t_mx,res);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1,0);
    ll res=0;
    dfs2(1,0,0,0,res);
    printf("%I64d",res);
    return 0;
}