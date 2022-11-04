#include <bits/stdc++.h>
using namespace std;
const int MAXN=500005;
const int Mod=998244353;
int fp(int a,int k)
{
    int res=1;
    while(k)
    {
        if(k&1)res=1LL*res*a%Mod;
        a=1LL*a*a%Mod;
        k>>=1;
    }
    return res;
}
int fac[MAXN],inv[MAXN];
int C(int n,int k)
{
    return 1LL*fac[n]*inv[k]%Mod*inv[n-k]%Mod;
}
int main()
{
    for(int i=(fac[0]=1);i<MAXN;i++)
        fac[i]=1LL*i*fac[i-1]%Mod;
    for(int i=0;i<MAXN;i++)
        inv[i]=fp(fac[i],Mod-2);
    int n,k,res=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int t=(n/i)-1;
        if(t<k-1)break;
        res=(res+C(t,k-1))%Mod;
    }
    return 0*printf("%d\n",res);
}