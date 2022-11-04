#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=100005;
int f[MAXN],k[MAXN];
ll t[MAXN],sum[MAXN];
multiset<ll>pre[MAXN],all;
void modifyAll(int x,int ty)
{
    if(pre[x].empty())return;
    if(ty)
    {
        all.insert(*pre[x].begin()+t[x]/(k[x]+2));
        all.insert(*--pre[x].end()+t[x]/(k[x]+2));
    }
    else
    {
        all.erase(all.lower_bound(*pre[x].begin()+t[x]/(k[x]+2)));
        all.erase(all.lower_bound(*--pre[x].end()+t[x]/(k[x]+2)));
    }
}
void modifyPre(int x,int ty)
{
    if(ty)pre[f[x]].insert(sum[x]+t[x]-t[x]/(k[x]+2)*(k[x]+1));
    else pre[f[x]].erase(pre[f[x]].lower_bound(sum[x]+t[x]-t[x]/(k[x]+2)*(k[x]+1)));
}
void build(int n)
{
    for(int i=1;i<=n;i++)
        scanf("%I64d",&t[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&f[i]);
        k[f[i]]++;
    }
    for(int i=1;i<=n;i++)
        sum[f[i]]+=t[i]/(k[i]+2);
    for(int i=1;i<=n;i++)
        modifyPre(i,1);
    for(int i=1;i<=n;i++)
        modifyAll(i,1);
}
map<int,int>vis;
void change(int x,int y)
{
    int p[7]={x,f[x],f[f[x]],f[f[f[x]]],y,f[y],f[f[y]]};
    vis.clear();
    for(int i=0;i<7;i++)
        if(!vis[p[i]])modifyAll(p[i],0),vis[p[i]]=1;
    vis.clear();
    for(int i=0;i<7;i++)
        if(!vis[p[i]])modifyPre(p[i],0),vis[p[i]]=1;
    sum[f[x]]-=t[x]/(k[x]+2);
    sum[f[f[x]]]-=t[f[x]]/(k[f[x]]+2);
    sum[f[y]]-=t[y]/(k[y]+2);
    k[f[x]]--,k[y]++;
    sum[f[f[x]]]+=t[f[x]]/(k[f[x]]+2);
    sum[y]+=t[x]/(k[x]+2);
    sum[f[y]]+=t[y]/(k[y]+2);
    f[x]=y;
    vis.clear();
    for(int i=0;i<7;i++)
        if(!vis[p[i]])modifyPre(p[i],1),vis[p[i]]=1;
    vis.clear();
    for(int i=0;i<7;i++)
        if(!vis[p[i]])modifyAll(p[i],1),vis[p[i]]=1;
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    build(n);
    while(q--)
    {
        int ty,i,j;
        scanf("%d",&ty);
        if(ty==1)
        {
            scanf("%d%d",&i,&j);
            change(i,j);
        }
        else if(ty==2)
        {
            scanf("%d",&i);
            printf("%I64d\n",sum[i]+t[i]-t[i]/(k[i]+2)*(k[i]+1)+t[f[i]]/(k[f[i]]+2));
        }
        else
            printf("%I64d %I64d\n",*all.begin(),*--all.end());
    }
    return 0;
}