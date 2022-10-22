#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

typedef long long ll;

int T,n,k,a[N];

ll s[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        if(k<=n)
        {
            ll ans=0;
            for(int i=1;i<=n;i++)
                s[i]=s[i-1]+a[i];
            for(int i=k;i<=n;i++)
                ans=max(ans,s[i]-s[i-k]);
            ans+=1ll*k*(k-1)/2;
            printf("%lld\n",ans);
        }
        else
        {
            ll ans=0;
            for(int i=1;i<=n;i++)
                ans+=a[i];
            ans+=1ll*k*n-1ll*n*(n+1)/2;
            printf("%lld\n",ans);
        }
    }
}