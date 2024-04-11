#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
int a[MAXN],ord[MAXN],vis[MAXN];
struct DSU
{
    int fa[MAXN];
    ll ml[MAXN],mr[MAXN],mx[MAXN],s[MAXN];
    void init(int n)
    {
        for(int i=1;i<=n;i++)
            fa[i]=i,ml[i]=mr[i]=mx[i]=s[i]=a[i];
    }
    int find(int x)
    {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    void merge(int x,int y)
    {
        x=find(x),y=find(y);
        if(x==y)return;
        fa[x]=y;
        mx[y]=max({mx[x],mx[y],max(0LL,mr[x])+ml[y],mr[x]+max(0LL,ml[y])});
        mr[y]=max(mr[y],max(0LL,mr[x])+s[y]);
        ml[y]=max(ml[x],max(0LL,ml[y])+s[x]);
        s[y]+=s[x];
    }
}dsu;
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),ord[i]=i,vis[i]=0;
    sort(ord+1,ord+n+1,[](int x,int y){return a[x]<a[y];});
    dsu.init(n);
    for(int ii=1;ii<=n;ii++)
    {
        int i=ord[ii];
        vis[i]=1;
        if(i>1 && vis[i-1])dsu.merge(i-1,i);
        if(i<n && vis[i+1])dsu.merge(i,i+1);
        if(a[i]<dsu.mx[dsu.find(i)])return 0*printf("NO\n");
    }
    return 0*printf("YES\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}