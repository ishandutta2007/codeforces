#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int main()
{
    int T;
    // for(scanf("%d",&T);T--;)
    {
        int n;LL k,x;scanf("%d%lld%lld",&n,&k,&x);
        LL a[200010],p[200010];
        rep(i,n)scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        rep(i,n-1)p[i]=max(0ll,(a[i+1]-a[i]-1)/x);
        sort(p+1,p+n);
        int ans=n;
        rep(i,n-1)if(k>=p[i])k-=p[i],ans--;
        printf("%d\n",ans);
    }
    return 0;
}