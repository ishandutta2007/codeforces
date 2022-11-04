#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
vector<int> e[MAXN];
int dep[MAXN],res[MAXN];
map<int,int> mp[MAXN];
void dfs(int u,int f)
{
    dep[u]=dep[f]+1;
    mp[u][dep[u]]++;
    res[u]=dep[u];
    for(auto &v:e[u])
    {
        if(v==f)continue;
        dfs(v,u);
        if(mp[u].size()<mp[v].size())
            mp[u].swap(mp[v]),res[u]=res[v];
        for(auto &t:mp[v])
        {
            mp[u][t.first]+=t.second;
            if(mp[u][t.first]+(t.first<res[u])>mp[u][res[u]])
                res[u]=t.first;
        }
        mp[v].clear();
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        printf("%d\n",res[i]-dep[i]);
    return 0;
}