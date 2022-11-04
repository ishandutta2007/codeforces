#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
int cnt[MAXN];
vector<int>e[MAXN];
void dfs(int u,int fa,int &k,ll &res)
{
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        dfs(v,u,k,res);
        cnt[u]+=cnt[v];
        res+=min(cnt[v],2*k-cnt[v]);
    }
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=2*k;i++)
    {
        int u;
        scanf("%d",&u);
        cnt[u]=1;
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ll res=0;
    dfs(1,0,k,res);
    return 0*printf("%I64d",res);
}