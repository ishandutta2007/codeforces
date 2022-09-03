#include <bits/stdc++.h>
#define C(i,j) (((fact[i]*revfact[j])%mod)*revfact[(i)-(j)]%mod)
using namespace std;
typedef long long LL;
const int maxn=100005;
const LL mod=1000000007;
LL fact[maxn],revfact[maxn],pow10[maxn],res;
char s[maxn];
int n,k,sum;

LL modpow(LL x,int y)
{
    LL ret=1;
    while(y)
    {
        if(y&1)
            ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    fact[0]=1;
    pow10[0]=1;
    revfact[0]=1;
    for(int i=1;i<=n;i++)
    {
        fact[i]=fact[i-1]*i%mod;
        revfact[i]=modpow(fact[i],mod-2);
        pow10[i]=pow10[i-1]*10%mod;
        sum+=s[i]-'0';
    }
    LL ans;
    for(int i=0;i<n-k;++i)
    {
        sum-=s[n-i]-'0';
        ans=(sum*C(n-i-2,k-1)+(s[n-i]-'0')*C(n-i-1,k))%mod;
        res=(res+pow10[i]*ans)%mod;
    }
    printf("%I64d\n",res);
    return 0;
}