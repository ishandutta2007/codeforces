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
        LL n;scanf("%lld",&n);
        int ans=0;
        for(;n%2==0;ans++,n/=2);
        for(;n%3==0;ans+=2,n/=3);
        for(;n%5==0;ans+=3,n/=5);
        if(n>1)puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}