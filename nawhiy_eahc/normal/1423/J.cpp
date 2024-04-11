#include<bits/stdc++.h>
#define int long long
using namespace std;
int t, n, i, j, k, a, b, A[1000010], mod=1e9+7;
main()
{
    for(scanf("%lld", &t);t--;)
    {
        scanf("%lld", &n);
        a=n/2;
        a++;
        int ans=0;
        if(a%2==0)
        {
            ans=((a/2)%mod)*((a/2+1)%mod);
            ans%=mod;
        }
        else
        {
            ans=(((a/2)%mod)*((a/2+1)%mod))+a/2+1;
            ans%=mod;
        }
        printf("%lld\n", ans);
    }
}