#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
const int INF=0x3f3f3f3f;
vector<int> e[MAXN];
pair<int,int> dp[MAXN][3];
void dfs1(int u,int fa)
{
    dp[u][0]={0,u};
    for(int i=1;i<3;i++)
        dp[u][i]={-INF,0};
    for(auto &v:e[u])
    {
        if(v==fa)continue;
        dfs1(v,u);
        pair<int,int> tmp=dp[v][0];
        tmp.first++;
        for(int i=0;i<3;i++)
            if(dp[u][i]<tmp)
                swap(tmp,dp[u][i]);
    }
}
pair<int,int> up[MAXN];
void dfs2(int u,int fa)
{
    for(auto &v:e[u])
    {
        if(v==fa)continue;
        up[v]=up[u],up[v].first++;
        pair<int,int> tmp=dp[u][dp[v][0].second==dp[u][0].second];
        tmp.first++,up[v]=max(up[v],tmp);
        dfs2(v,u);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    int rt=1;
    while(e[rt].size()==1)rt++;
    dfs1(rt,0);
    up[rt]={0,rt};
    dfs2(rt,0);
    int res=0,a=0,b=0,c=0;
    for(int u=1;u<=n;u++)
    {
        if(!dp[u][1].second)continue;
        int now=dp[u][0].first+dp[u][1].first+up[u].first;
        int ta=dp[u][0].second,tb=dp[u][1].second,tc=up[u].second;
        if(now>res && ta!=tb && ta!=tc && tb!=tc)
            res=now,a=ta,b=tb,c=tc;
        if(!dp[u][2].second)continue;
        now=dp[u][0].first+dp[u][1].first+dp[u][2].first;
        ta=dp[u][0].second,tb=dp[u][1].second,tc=dp[u][2].second;
        if(now>res && ta!=tb && ta!=tc && tb!=tc)
            res=now,a=ta,b=tb,c=tc;
    }
    printf("%d\n%d %d %d\n",res,a,b,c);
    return 0;
}