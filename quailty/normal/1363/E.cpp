#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN=200005;
const int INF=0x3f3f3f3f;

int a[MAXN],b[MAXN],c[MAXN];
vector<int> e[MAXN];
pair<int,int> dfs(int u,int f,int mi,ll &res)
{
    int trans[2]={0,0};
    for(auto &v:e[u])
    {
        if(v==f)continue;
        auto t=dfs(v,u,min(mi,a[u]),res);
        trans[0]+=t.first,trans[1]+=t.second;
    }
    if(b[u]^c[u])trans[b[u]]++;
    if(a[u]<mi)
    {
        int op=min(trans[0],trans[1]);
        res+=2LL*op*a[u];
        trans[0]-=op,trans[1]-=op;
    }
    return {trans[0],trans[1]};
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ll res=0;
    auto t=dfs(1,0,INF,res);
    if(t.first==0 && t.second==0)
        printf("%lld\n",res);
    else printf("-1\n");
    return 0;
}