#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int Mod=1000000007;
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
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%lld\n",1LL*fp(2*(n+1),m)*(n-m+1)%Mod*fp(n+1,Mod-2)%Mod);
    return 0;
}