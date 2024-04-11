#include<bits/stdc++.h>
#define int long long 
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
int n,a[M],d[M];
int dfn[M],out[M],ti;
vector<int>e[M];
map<int,int>c,t;

void dfs(int u,int fa)
{
    dfn[u]=++ti;
    int k=c[a[u]];c[a[u]]++;
    for (int i=0;i<e[u].size();i++)
    {
        int to=e[u][i];
        if (to==fa)continue;
        int tmp=c[a[u]];
        dfs(to,u);
        if (c[a[u]]>tmp)
            d[1]++,d[dfn[to]]--,d[out[to]+1]++;
    }
    out[u]=ti;
    if (c[a[u]]-k<t[a[u]])
        d[dfn[u]]++,d[out[u]+1]--;
}

signed main()
{
    n=read();
    for (int i=1;i<=n;i++)
        a[i]=read(),t[a[i]]++;
    for (int i=1;i<n;i++)
    {
        int u=read(),v=read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);int ans=0;
    for (int i=1;i<=n;i++)
        d[i]+=d[i-1];
    for (int i=1;i<=n;i++)
        if (!d[i])ans++;
    cout<<ans<<endl;
    return 0;
}