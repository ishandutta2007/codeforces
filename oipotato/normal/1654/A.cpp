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
        int n,a[1010];scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        int ans=0;
        rep(i,n-1)ans=max(ans,a[i]+a[i+1]);
        for(int i=2;i<n;i++)for(int j=i+1;j<n;j++)ans=max(ans,max(a[i]+a[j+1],a[i-1]+a[j]));
        rep(i,n-2)ans=max(ans,a[i]+a[n]);
        for(int i=3;i<=n;i++)ans=max(ans,a[i]+a[1]);
        printf("%d\n",ans);
    }
    return 0;
}