#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=20;
const int MAXM=100005;
const ll Mod=1000000007;
char s[MAXN+5][MAXM+5];
ll a[MAXM],f[1<<MAXN],g[1<<MAXN];
void fwt(ll f[],int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<n);j++)
        {
            if(j&(1<<i))continue;
            int u=f[j],v=f[j|(1<<i)];
            f[j]=(u+v)%Mod,f[j|(1<<i)]=(u-v+Mod)%Mod;
        }
}
ll fp(ll a,ll k)
{
    ll res=1;
    while(k)
    {
        if(k&1)res=res*a%Mod;
        a=a*a%Mod;
        k>>=1;
    }
    return res;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            a[j]|=(s[i][j]-'0')<<i;
    for(int i=0;i<m;i++)
        f[a[i]]=f[a[i]]+1;
    for(int i=0;i<(1<<n);i++)
    {
        int cnt=0;
        for(int j=0;j<n;j++)
            if(i&(1<<j))cnt++;
        g[i]=min(cnt,n-cnt);
    }
    fwt(f,n);
    fwt(g,n);
    for(int i=0;i<(1<<n);i++)
        f[i]=f[i]*g[i]%Mod;
    fwt(f,n);
    ll res=n*m,buf=fp(1<<n,Mod-2);
    for(int i=0;i<(1<<n);i++)
        res=min(res,f[i]*buf%Mod);
    printf("%I64d\n",res);
    return 0;
}