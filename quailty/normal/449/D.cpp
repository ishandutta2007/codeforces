#include<cstdio>
#include<cstring>
#include<cstdlib>
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
void fwt(int f[],int n,int ty)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<n);j++)
        {
            if(j&(1<<i))continue;
            if((f[j|(1<<i)]+=ty*f[j])>=Mod)f[j|(1<<i)]-=Mod;
            if(f[j|(1<<i)]<0)f[j|(1<<i)]+=Mod;
        }
}
int f[1<<20];
int main()
{
    int n;
    scanf("%d",&n);
    int all=(1<<20)-1;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        f[a^all]++;
    }
    fwt(f,20,1);
    for(int i=0;i<(1<<20);i++)
        f[i]=fp(2,f[i]);
    fwt(f,20,-1);
    return 0*printf("%d",f[(1<<20)-1]);
}