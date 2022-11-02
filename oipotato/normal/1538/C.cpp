#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[200010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,l,r;scanf("%d%d%d",&n,&l,&r);
        rep(i,n)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        LL ans=0;
        rep(i,n)
        {
            ans+=upper_bound(a+1,a+n+1,r-a[i])-lower_bound(a+1,a+n+1,l-a[i]);
            if(l<=2*a[i]&&2*a[i]<=r)ans--;
        }
        printf("%lld\n",ans/2);
    }
    return 0;
}