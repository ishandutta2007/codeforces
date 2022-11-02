#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
typedef pair<int,int> pii;
#define mp make_pair
const int MAXN=1000005,INF=1<<30;

int n;
vector<int> G[MAXN];
int Min[MAXN<<2|1],Max[MAXN<<2|1],ind[MAXN],rem[MAXN];
void build(int id,int l,int r)
{
    if(l==r){Min[id]=rem[l];return;}
    int mid=(l+r)>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    Min[id]=min(Min[id<<1],Min[id<<1|1]);
}
int querymin(int id,int l,int r)
{
    if(l==r)return l;
    int mid=(l+r)>>1;
    if(Min[id<<1]<Min[id<<1|1])return querymin(id<<1,l,mid);
    return querymin(id<<1|1,mid+1,r);
}
void modify(int id,int l,int r,int x,int c)
{
    if(l==r){Min[id]=c;return;}
    int mid=(l+r)>>1;
    if(x<=mid)modify(id<<1,l,mid,x,c);
    else modify(id<<1|1,mid+1,r,x,c);
    Min[id]=min(Min[id<<1],Min[id<<1|1]);
}
set<pii> del;
inline bool cmp(int x,int y){return rem[x]>rem[y];}

int main()
{
    int E,u,v;
    scanf("%d%d",&n,&E);
    for(int i=1;i<=E;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].pb(v);G[v].pb(u);
        ++ind[u];++ind[v];
    }
    for(int i=1;i<=n;i++)rem[i]=ind[i]/2;
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        u=querymin(1,1,n);
        modify(1,1,n,u,INF);
        sort(G[u].begin(),G[u].end(),cmp);
        for(int j=0;j<rem[u];j++)
        {
            v=G[u][j];
            if(!rem[v])break;
            --rem[v];
            modify(1,1,n,v,rem[v]);
            del.insert(mp(u,v));
        }
        rem[u]=0;
    }
    printf("%d\n",E-del.size());
    for(u=1;u<=n;u++)
        for(auto v:G[u])
            if(v>u && !del.count(mp(u,v)) && !del.count(mp(v,u)))
                printf("%d %d\n",u,v);
    return 0;
}