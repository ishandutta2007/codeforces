#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5000005;
const ll Mod=1000000007;
int p[MAXN],mi[MAXN];
void sieve()
{
    for(int i=2;i<MAXN;i++)
    {
        if(!mi[i])p[++p[0]]=i,mi[i]=i;
        for(int j=1;j<=p[0] && i*p[j]<MAXN;j++)
        {
            mi[i*p[j]]=p[j];
            if(i%p[j]==0)break;
        }
    }
}
ll dp[MAXN];
int main()
{
    sieve();
    for(int i=2;i<MAXN;i++)
        dp[i]=1LL*i*(mi[i]-1)/2+dp[i/mi[i]];
    ll res=0,buf=1;
    int t,l,r;
    scanf("%d%d%d",&t,&l,&r);
    for(int i=l;i<=r;i++)
        res=(res+dp[i]%Mod*buf)%Mod,buf=buf*t%Mod;
    return 0*printf("%lld\n",res);
}