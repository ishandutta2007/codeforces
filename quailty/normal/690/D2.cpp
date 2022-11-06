#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int Mod=1000003;
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
int fac[Mod];
int bincoff(int n,int k)
{
    if(k>n)return 0;
    return 1LL*fac[n]*fp(fac[k],Mod-2)%Mod*fp(fac[n-k],Mod-2)%Mod;
}
int main()
{
    for(int i=(fac[0]=1);i<=1000000;i++)
        fac[i]=1LL*i*fac[i-1]%Mod;
    int n,C;
    scanf("%d%d",&n,&C);
    int res=0;
    for(int i=C;i<=n+C-1;i++)
        res=(res+bincoff(i,C-1))%Mod;
    return 0*printf("%d\n",res);
}