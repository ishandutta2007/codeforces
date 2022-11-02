#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const LL inf=(LL)1e6*1e6;
priority_queue<pair<int,int>>q;
int n,m,from[100010];
LL d[100010];
bool vis[100010];
vector<pair<int,int>>g[100010];
int main()
{
    scanf("%d%d",&n,&m);
    rep(i,m)
    {
        int x,y,z;scanf("%d%d%d",&x,&y,&z);
        g[x].pb(mp(y,z));
        g[y].pb(mp(x,z));
    }
    rep(i,n)d[i]=inf;
    d[1]=0;
    q.push(mp(-d[1],1));
    for(;!q.empty();)
    {
        auto u=q.top();q.pop();
        int id=u.second;
        if(vis[id])continue;
        vis[id]=1;
        for(auto [x,y]:g[id])if(d[x]>d[id]+y)
        {
            d[x]=d[id]+y;
            from[x]=id;
            q.push(mp(-d[x],x));
        }
    }
    if(d[n]==inf)puts("-1");
    else
    {
        vector<int>ans;
        for(int x=n;x!=1;ans.pb(x),x=from[x]);
        reverse(ans.begin(),ans.end());
        printf("1");
        for(auto i:ans)printf(" %d",i);
        puts("");
    }
    return 0;
}