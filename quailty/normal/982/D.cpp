#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int a[MAXN],idx[MAXN],vis[MAXN];
int len[MAXN],tot;
struct DSU
{
    int fa[MAXN],lef[MAXN],rig[MAXN];
    void init(int n)
    {
        for(int i=1;i<=n;i++)
            fa[i]=lef[i]=rig[i]=i;
    }
    int find(int x)
    {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    int merge(int x,int y)
    {
        x=find(x),y=find(y);
        if(x==y)return 0;
        tot-=((--len[rig[x]-lef[x]+1])==0);
        tot-=((--len[rig[y]-lef[y]+1])==0);
        lef[y]=min(lef[x],lef[y]);
        rig[y]=max(rig[x],rig[y]);
        tot+=((len[rig[y]-lef[y]+1]++)==0);
        return fa[x]=y,1;
    }
}dsu;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),idx[i]=i;
    sort(idx+1,idx+n+1,[](int x,int y){return a[x]<a[y];});
    dsu.init(n);
    int mx=0,res=0,now=0;
    for(int i=1,j=1;i<=n;i=j)
    {
        while(j<=n && a[idx[i]]==a[idx[j]])j++;
        for(int k=i;k<j;k++)
        {
            int loc=idx[k];
            vis[loc]=1,now++,tot+=((len[1]++)==0);
            if(vis[loc-1])now-=dsu.merge(loc-1,loc);
            if(vis[loc+1])now-=dsu.merge(loc+1,loc);
        }
        if(tot==1 && now>mx)mx=now,res=a[idx[i]]+1;
    }
    return 0*printf("%d\n",res);
}