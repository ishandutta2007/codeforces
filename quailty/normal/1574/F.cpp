#include<bits/stdc++.h>
using namespace std;
const int MAXN=300005;
const int Mod=998244353;
vector<int> pre[MAXN],nxt[MAXN];
bool vis[MAXN];
void dfs(int u,int las,int& ok,int& siz)
{
    vis[u]=1;
    ++siz;
    ok&=(pre[u].size()<=1u);
    ok&=(nxt[u].size()<=1u);
    for(auto& v : pre[u])
    {
        if(v==las)continue;
        if(vis[v])
        {
            ok=0;
            continue;
        }
        dfs(v,u,ok,siz);
    }
    for(auto& v : nxt[u])
    {
        if(v==las)continue;
        if(vis[v])
        {
            ok=0;
            continue;
        }
        dfs(v,u,ok,siz);
    }
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
    {
        int c;
        scanf("%d",&c);
        vector<int> a(c);
        for(int j=0;j<c;j++)
            scanf("%d",&a[j]);
        for(int j=0;j+1<c;j++)
        {
            nxt[a[j]].push_back(a[j+1]);
            pre[a[j+1]].push_back(a[j]);
        }
    }
    for(int i=1;i<=k;i++)
    {
        sort(nxt[i].begin(),nxt[i].end());
        nxt[i].erase(unique(nxt[i].begin(),nxt[i].end()),nxt[i].end());
        sort(pre[i].begin(),pre[i].end());
        pre[i].erase(unique(pre[i].begin(),pre[i].end()),pre[i].end());
    }
    map<int,int> mp;
    for(int i=1;i<=k;i++)
    {
        if(vis[i])continue;
        int ok=1,siz=0;
        dfs(i,0,ok,siz);
        if(ok)mp[siz]++;
    }
    static int dp[MAXN];
    for(int i=(dp[0]=1);i<=m;i++)
        for(auto& t : mp)
        {
            int j=t.first,c=t.second;
            if(j<=i)dp[i]=(dp[i]+1LL*c*dp[i-j])%Mod;
        }
    printf("%d\n",dp[m]);
    return 0;
}