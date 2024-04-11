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
        LL l,r;scanf("%lld%lld",&l,&r);
        if(l&1)l++;
        if(r-l<2)puts("-1");else printf("%lld %lld %lld\n",l,l+1,l+2);
    }
    return 0;
}