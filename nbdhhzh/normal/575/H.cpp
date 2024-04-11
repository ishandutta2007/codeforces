#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long n,jc[2000010],i;
long long powmod(long long x,long long y)
{
    long long ans=1;
    for(;y;y>>=1,x=x*x%mod)
        if(y&1)ans=ans*x%mod;
    return ans;
}
int main()
{
    scanf("%I64d",&n);jc[0]=1;
    for(i=1;i<=n+1<<1;i++)
        jc[i]=jc[i-1]*i%mod;
    printf("%I64d\n",(jc[n+1<<1]*powmod(jc[n+1],mod-2)%mod*powmod(jc[n+1],mod-2)+mod-1)%mod);
}