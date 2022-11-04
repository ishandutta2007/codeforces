#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1000005;
const int Mod=1000000007;
int np[MAXN],phi[MAXN];
struct node
{
    int nxt,val;
}f[MAXN*20];
int head[MAXN],tot;
void add(int u,int v)
{
    f[tot].val=v;
    f[tot].nxt=head[u];
    head[u]=tot++;
}
int pre[3][MAXN];
int cal(int n)
{
    int res=0;
    for(int i=head[n];~i;i=f[i].nxt)
        res=(res+1LL*f[i].val*phi[n/f[i].val])%Mod;
    return res;
}
void build()
{
    memset(head,-1,sizeof(head));
    for(int i=1;i<=1000000;i++)phi[i]=i;
    for(int i=1;i<=1000000;i++)
        for(int j=i;j<=1000000;j+=i)add(j,i);
    for(int i=2;i<=1000000;i++)
        if(!np[i])for(int j=i;j<=1000000;j+=i)
        {
            (phi[j]/=i)*=i-1;
            np[j]=1;
        }
    for(int i=1;i<=1000000;i++)
    {
        int tmp=(1LL*i*(i+1)*(2*i+1)/3-3LL*i*i+2*cal(i))%Mod;
        pre[0][i]=(pre[0][i-1]+tmp)%Mod;
        pre[1][i]=(pre[1][i-1]+1LL*i*tmp)%Mod;
        pre[2][i]=(pre[2][i-1]+1LL*i*i%Mod*tmp)%Mod;
    }
}
int main()
{
    build();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int res=1LL*(n+1)*(m+1)%Mod*pre[0][min(n,m)]%Mod;
        res-=1LL*(n+m+2)*pre[1][min(n,m)]%Mod;
        res+=pre[2][min(n,m)];
        printf("%d\n",(res%Mod+Mod)%Mod);
    }
    return 0;
}