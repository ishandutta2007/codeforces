#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int MOD=998244353;
#define repp(i,s,t) for(int i = s;i <= t;i ++)
int qpow(int a,int b){
        int ret=1;
        while(b){
                if(b&1)ret=(LL)ret*a%MOD;
                a=(LL)a*a%MOD;
                b>>=1;
        }
        return ret;
}
namespace NTT{
    const int g=3;
    const int NN=100010;
    int x[NN<<2],y[NN<<2],wn[NN<<2];
    void init()
    {
        repp(i,0,20)wn[i]=qpow(g,(MOD-1)/(1<<i));
    }
    void brc(int *F,int len)
    {
        int j=len/2;
        repp(i,1,len-2){
            if(i<j)swap(F[i],F[j]);
            int k=len/2;
            while(j>=k) j-=k,k>>=1;
            if(j<k)j+=k;
        }
    }
    void NTT(int *F,int len,int t)
    {
        int id=0; brc(F,len);
        for(int h=2;h<=len;h<<=1)
        {
            id++;
            for(int j=0;j<len;j+=h)
            {
                int E=1;
                for(int k=j;k<j+h/2;k++)
                {
                    int u=F[k],v=(LL)E*F[k+h/2]%MOD;
                    F[k]=(u+v)%MOD,F[k+h/2]=((u-v)%MOD+MOD)%MOD;
                    E=(LL)E*wn[id]%MOD;
                }
            }
        }
        if(t==-1)
        {
            repp(i,1,len/2-1)swap(F[i],F[len-i]);
            LL inv=qpow(len,MOD-2);
            repp(i,0,len-1)F[i]=(LL)F[i]%MOD*inv%MOD;
        }
    }
};
const int N=100010;
int tmp1[2][2][N<<2],tmp2[2][2][N<<2],f1[2][2][N<<2],f2[2][2][N<<2],f[2][2][N],a[N],p[N],n,cnt,fac[N];
void work(int l,int r)
{
    if(l==r)
    {
        if(p[l]==1)f[1][1][l]=1;
        else f[0][0][l]=2;
        return;
    }
    int mid=(l+r)>>1;
    work(l,mid);work(mid+1,r);
    int len1=mid-l+1,len2=r-mid,M=1;
    for(;M<len1+len2;M<<=1);

    for(int i=0;i<2;i++)for(int j=0;j<M;j++)tmp1[0][i][j]=tmp2[0][i][j]=0;
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<len1;k++)(tmp1[0][i][k]+=f[i][j][l+k])%=MOD;
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<len2;k++)(tmp2[0][j][k]+=f[i][j][mid+1+k])%=MOD;
    for(int i=0;i<2;i++)NTT::NTT(tmp1[0][i],M,1),NTT::NTT(tmp2[0][i],M,1);
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<M;k++)f1[i][j][k]=1LL*tmp1[0][i][k]*tmp2[0][j][k]%MOD;
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)NTT::NTT(f1[i][j],M,-1);

    for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<M;k++)tmp1[i][j][k]=tmp2[i][j][k]=0;
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<len1;k++)
    {
        if(k==len1-1&&i&&j)tmp1[0][0][k]=(tmp1[0][0][k]+2ll*f[i][j][l+k])%MOD;
        else (tmp1[i][j][k]+=f[i][j][l+k])%=MOD;
    }
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<len2;k++)
    {
        if(k==len2-1&&i&&j)tmp2[0][0][k]=(tmp2[0][0][k]+2ll*f[i][j][mid+1+k])%MOD;
        else (tmp2[i][j][k]+=f[i][j][mid+1+k])%=MOD;
    }
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)NTT::NTT(tmp1[i][j],M,1),NTT::NTT(tmp2[i][j],M,1);
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<M;k++)
    {
        f2[i][j][k]=0;
        for(int a=0;a<2;a++)for(int b=0;b<2;b++)
        {
            int C;
            if(a&&b)C=2;else if(a||b)C=1;else C=(MOD+1)/2;
            f2[i][j][k]=(f2[i][j][k]+(LL)C*tmp1[i][a][k]%MOD*tmp2[b][j][k])%MOD;
        }
    }
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)NTT::NTT(f2[i][j],M,-1);
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)
    {
        f[i][j][l]=f1[i][j][0];
        rep(k,r-l)f[i][j][l+k]=(f1[i][j][k]+f2[i][j][k-1])%MOD;
    }
}
int main()
{
    NTT::init();
    scanf("%d",&n);
    rep(i,n)scanf("%d",&a[i]);
    for(int i=1;i<=n;i+=a[i])
    {
        int j=i+a[i]-1;
        for(int k=i;k<=j;k++)if(k>n||a[k]!=a[i]){puts("0");return 0;}
        p[++cnt]=a[i];
    }
    fac[0]=1;
    rep(i,cnt)fac[i]=1LL*fac[i-1]*i%MOD;
    work(1,cnt);
    int ans=0;
    for(int j=0;j<2;j++)for(int k=0;k<2;k++)rep(i,cnt)ans=(ans+1LL*((i&1)?1:MOD-1)*f[j][k][i]%MOD*fac[cnt-(i-1)])%MOD;
    printf("%d\n",ans);
    return 0;
}