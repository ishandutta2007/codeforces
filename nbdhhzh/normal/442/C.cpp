#include<cstdio>
#include<algorithm>
#define N 500010
using namespace std;
int n,i,sg[N],xg[N],a[N],f[N],u,use[N];
long long ans;
bool cmp(int x,int y){return a[x]<a[y];}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sg[i]=i-1;xg[i]=i+1;
        scanf("%d",&a[i]),f[i]=i;
    }sort(f+1,f+n+1,cmp);
    for(i=1;i<=n;i++)
    {
        u=f[i];
        if(a[sg[u]]>=a[u]&&a[xg[u]]>=a[u])
        {
            use[u]=1;
            ans+=min(a[sg[u]],a[xg[u]]);
            xg[sg[u]]=xg[u];sg[xg[u]]=sg[u];
        }
    }for(i=n;i>=1;i--)
    {
        u=f[i];if(use[u])continue;
        ans+=min(a[sg[u]],a[xg[u]]);
    }printf("%I64d\n",ans);
}