#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[200010],b[200010],c[200010];
int main()
{
    int n;scanf("%d",&n);
    rep(i,n)scanf("%d",&a[i]);
    rep(i,n)scanf("%d",&b[i]);
    rep(i,n)c[i]=b[i]-a[i];
    sort(c+1,c+n+1);
    LL ans=0;
    rep(i,n)
    {
        ans+=lower_bound(c+1,c+n+1,a[i]-b[i])-c-1;
        if(a[i]>b[i])ans--;
    }
    printf("%lld\n",ans/2);
    return 0;
}