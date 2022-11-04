#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int Mod=1000000007;
struct fac
{
    int num,nxt;
}f[15000005];
int h[1000005],cnt;
void add_fac(int u,int v)
{
    f[cnt].num=v;
    f[cnt].nxt=h[u];
    h[u]=cnt++;
}
void build_fac()
{
    memset(h,-1,sizeof(h));
    for(int i=1;i<=1000000;i++)
        for(int j=i;j<=1000000;j+=i)
            add_fac(j,i);
}
int phi[1000005];
void build_phi()
{
    phi[1]=1;
    for(int i=2;i<=1000000;i++)
        if(!phi[i])
        {
            for(int j=i;j<=1000000;j+=i)
            {
                if(!phi[j])phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
        }
}
int fac[1000005],inv[1000005];
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
void build_coe()
{
    fac[0]=1;
    for(int i=1;i<=1000000;i++)
        fac[i]=1LL*i*fac[i-1]%Mod;
    for(int i=0;i<=1000000;i++)
        inv[i]=fp(fac[i],Mod-2);
}
int coe(int n,int k)
{
    if(k>n)return 0;
    return 1LL*fac[n]*inv[n-k]%Mod*inv[k]%Mod;
}
int cc[1000005];
int main()
{
    build_fac();
    build_phi();
    build_coe();
    int n,k,q;
    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        cc[a]++;
    }
    for(int i=1;i<=1000000;i++)
        for(int j=2*i;j<=1000000;j+=i)
            cc[i]=(cc[i]+cc[j])%Mod;
    int res=0;
    for(int i=1;i<=1000000;i++)
        res=(res+1LL*phi[i]*coe(cc[i],k))%Mod;
    for(int i=1;i<=q;i++)
    {
        int c;
        scanf("%d",&c);
        for(int j=h[c];~j;j=f[j].nxt)
        {
            int t=f[j].num;
            res=(res-1LL*phi[t]*coe(cc[t],k)%Mod+Mod)%Mod;
            cc[t]++;
            res=(res+1LL*phi[t]*coe(cc[t],k))%Mod;
        }
        printf("%d\n",res);
    }
    return 0;
}