#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

typedef long long ll;

int n,a[N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    ll ans=0;
    for(int i=1;i<=n;i+=2)
    {
        ll sum=0,mn=1e18;
        for(int j=i+1;j<=n;j+=2)
        {
            sum+=a[j-1];
            //sum - pj - a[i] < 0
            //pj <= a[j]
            //pj <= sum
            //sum-a[i]+1,sum
            ll L=max(sum-a[i]-mn,1ll),R=min(1ll*a[j],sum);
            // L=max(L,mn);
            if(L<=R)
                ans+=(R-L+1);
            sum-=a[j];
            mn=min(mn,sum-a[i]);
            if(sum<0)
                break;
        }
    }
    printf("%lld\n",ans);
}