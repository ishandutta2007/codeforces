#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
int a[MAXN],p[MAXN],fa[MAXN],vis[MAXN];
ll cnt[MAXN],res[MAXN],ans;
void Init(int n)
{
    for(int i=1;i<=n;i++)
        cnt[i]=a[fa[i]=i];
}
int Find(int x)
{
    return fa[x]==x ? x : fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
    x=Find(x),y=Find(y);
    if(x==y)return;
    ans=max(ans,cnt[fa[x]=y]+=cnt[x]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    Init(n);
    for(int i=n;i>=1;i--)
    {
        res[i]=ans;
        int x=p[i];
        ans=max(ans,cnt[x]);
        vis[x]=1;
        if(x>1 && vis[x-1])Union(x,x-1);
        if(x<n && vis[x+1])Union(x,x+1);
    }
    for(int i=1;i<=n;i++)
        printf("%I64d\n",res[i]);
    return 0;
}