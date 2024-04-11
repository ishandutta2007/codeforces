#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
const int V=200100;
struct Edge{int num,ne,id;}e[2*V];
int p[V],K;
void add(int x,int y)
{
    e[K].num=y;e[K].id=1;
    e[K].ne=p[x];p[x]=K++;
    e[K].num=x;e[K].id=0;
    e[K].ne=p[y];p[y]=K++;
}
int ct[V][3],pr[V];
void dfs(int u,int fa)
{
    ct[u][0]=0;
    ct[u][2]=0;
    for(int i=p[u];i!=-1;i=e[i].ne)
    {
        int v=e[i].num;
        if(v==fa)continue;
        pr[v]=i;
        dfs(v,u);
        if(e[i].id==0)ct[u][0]++;
        ct[u][0]+=ct[v][0];
        ct[u][2]+=ct[v][2]+1;
    }
}
void dfs1(int u,int fa)
{
    ct[u][1]=0;
    if(fa!=-1)
    {
        ct[u][1]=ct[fa][1];
        ct[u][1]+=ct[fa][0]-ct[u][0];
        if(e[pr[u]].id==1)ct[u][1]++;
        else ct[u][1]--;
    }
    for(int i=p[u];i!=-1;i=e[i].ne)
    {
        int v=e[i].num;
        if(v==fa)continue;
        dfs1(v,u);
    }
}
int n,x,y;
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)p[i]=-1;K=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            add(x,y);
        }
        dfs(1,-1);dfs1(1,-1);
        int mi=100000000;
        for(int i=1;i<=n;i++)
        mi=min(mi,ct[i][0]+ct[i][1]);
        //for(int i=1;i<=n;i++)printf("%d %d %d %d\n",i,ct[i][0],ct[i][1],ct[i][2]);
        printf("%d\n",mi);
        bool f=false;
        for(int i=1;i<=n;i++)
        if(ct[i][0]+ct[i][1]==mi)
        {
            if(f)printf(" ");
            else f=true;
            printf("%d",i);
        }puts("");
    }
}