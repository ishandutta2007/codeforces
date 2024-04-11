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
    // for(scanf("%d",&T);T--;)
    {
        LL x;scanf("%lld",&x);
        LL ans=x;
        rep(i,1000000)
        if(x%i==0)
        {
            LL a=i,b=x/i;
            if(__gcd(a,b)==1)ans=min(ans,max(a,b));
        }
        printf("%lld %lld\n",ans,x/ans);
    }
    return 0;
}