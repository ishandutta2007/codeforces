#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
vector<int> e[MAXN];
struct BIT
{
    int n,c[MAXN];
    void init(int _n)
    {
        n=_n;
        for(int i=1;i<=n;i++)c[i]=0;
    }
    void update(int p,int v)
    {
        for(int i=p;i<=n;i+=i&-i)c[i]+=v;
    }
    int query(int p)
    {
        int res=0;
        for(int i=p;i>0;i-=i&-i)res+=c[i];
        return res;
    }
}bit;
int fa[MAXN],in[MAXN],out[MAXN],time_tag;
void dfs(int u,int f,int d)
{
    fa[u]=f,in[u]=++time_tag;
    bit.update(in[u],d);
    bit.update(in[u]+1,-d);
    for(auto &v:e[u])
        if(v!=f)dfs(v,u,d+1);
    out[u]=time_tag;
}
int usd[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    bit.init(n);
    dfs(n,0,1);
    vector<int> res;
    for(int i=n,j=0;i>=1;i--)
    {
        if(usd[i])continue;
        int t=bit.query(in[i]);
        if(j+t<=n-k)
        {
            for(int t=i;t && !usd[t];t=fa[t])
            {
                usd[t]=1,j++;
                bit.update(in[t],-1);
                bit.update(out[t]+1,1);
            }
        }
        else res.push_back(i);
    }
    reverse(res.begin(),res.end());
    assert((int)res.size()==k);
    for(int i=0;i<k;i++)
        printf("%d%c",res[i]," \n"[i==k-1]);
    return 0;
}