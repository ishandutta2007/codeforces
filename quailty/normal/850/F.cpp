#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int Mod=1000000007;
int a[MAXN],f[MAXN];
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
void build(int S)
{
    int t=0;
    for(int i=1;i<MAXN;i++)
    {
        t=(t+fp(S-i+1,Mod-2))%Mod;
        f[i]=(1LL*(S-1)*(S-i)%Mod*t%Mod+Mod)%Mod;
    }
}
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    build(sum);
    int res=0;
    for(int i=1;i<=n;i++)
        res=(res+f[a[i]])%Mod;
    return 0*printf("%d\n",res);
}