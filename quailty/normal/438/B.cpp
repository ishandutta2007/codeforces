#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=100005;
int v[MAXN],w[MAXN],p[MAXN];
vector<int>e[MAXN];
bool cmp(int a,int b)
{
    return v[a]>v[b];
}
ll now,cnt[MAXN];
int fa[MAXN],sz[MAXN];
void Init(int n)
{
    for(int i=1;i<=n;i++)
        fa[i]=i,sz[i]=1;
}
int Find(int x)
{
    return x==fa[x] ? x : fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
    x=Find(x),y=Find(y);
    if(x==y)return;
    now+=1LL*sz[x]*sz[y];
    sz[fa[y]=x]+=sz[y];
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)
        p[i]=i;
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    Init(n);
    for(int i=1;i<=n;i++)
    {
        w[p[i]]=1;
        for(int j=0;j<(int)e[p[i]].size();j++)
            if(w[e[p[i]][j]])Union(p[i],e[p[i]][j]);
        cnt[i]=now;
    }
    ll res=0;
    for(int i=1;i<=n;i++)
        res+=(cnt[i]-cnt[i-1])*v[p[i]];
    return 0*printf("%.10f",2.0*res/n/(n-1));
}