#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int Mod=1000000007;
int c[MAXN];
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
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        c[a]++;
    }
    for(int i=1;i<MAXN;i++)
        for(int j=2*i;j<MAXN;j+=i)
            c[i]=(c[i]+c[j])%Mod;
    for(int i=1;i<MAXN;i++)
        c[i]=(fp(2,c[i])+Mod-1)%Mod;
    for(int i=MAXN-1;i>=1;i--)
        for(int j=2*i;j<MAXN;j+=i)
            c[i]=(c[i]-c[j]+Mod)%Mod;
    return 0*printf("%d",c[1]);
}