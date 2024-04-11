#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,k,a[200010],w[200010];
        scanf("%d%d",&n,&k);
        rep(i,n)scanf("%d",&a[i]);
        rep(i,k)scanf("%d",&w[i]);
        sort(a+1,a+n+1);
        sort(w+1,w+k+1,greater<int>());
        LL ans=0;
        rep(i,k)ans+=a[n-i+1];
        int l=1,r=n;
        rep(i,k)if(w[i]>1)ans+=a[l],l+=w[i]-1;else ans+=a[r],r--;
        printf("%lld\n",ans);
    }
    return 0;
}