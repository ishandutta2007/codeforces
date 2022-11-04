#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=300005;
vector<int> e[MAXN];
int in[MAXN],out[MAXN],time_tag;
void dfs(int u,int f)
{
    in[u]=++time_tag;
    for(auto &v:e[u])
        if(v!=f)dfs(v,u);
    out[u]=time_tag;
}
int main()
{
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1,0);
    ll res=1LL*n*n-n;
    if(in[y]>=in[x] && in[y]<=out[x])swap(x,y);
    if(in[x]>=in[y] && in[x]<=out[y])
    {
        for(auto &z:e[y])if(in[z]>=in[y] && in[z]<=out[y] && in[x]>=in[z] && in[x]<=out[z])
            res-=1LL*(out[x]-in[x]+1)*(n-out[z]+in[z]-1);
    }
    else res-=1LL*(out[x]-in[x]+1)*(out[y]-in[y]+1);
    printf("%lld\n",res);
    return 0;
}