#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int cal(LL x)
{
    int res=0;
    for(;x;res+=x%10,x/=10);
    return res;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        LL n;scanf("%lld",&n);
        for(;__gcd(n,(LL)cal(n))==1;n++);
        printf("%lld\n",n);
    }
    return 0;
}