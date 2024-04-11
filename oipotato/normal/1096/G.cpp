#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,s,t) for(int i = s;i <= t;i ++)
typedef long long ll;
const int mod=998244353;
const int NN=1<<20;
int qpow(int a,int b){
        int ret=1;
        while(b){
                if(b&1)ret=(ll)ret*a%mod;
                a=(ll)a*a%mod;
                b>>=1;
        }
        return ret;
}
namespace NTT{
    const int g=3;


    int x[NN<<2],y[NN<<2],wn[NN<<2];
    void init()
    {
        rep(i,0,20)wn[i]=qpow(g,(mod-1)/(1<<i));
    }

    void brc(int *F,int len)
    {
        int j=len/2;
        rep(i,1,len-2){
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
                    int u=F[k],v=(ll)E*F[k+h/2]%mod;
                    F[k]=(u+v)%mod,F[k+h/2]=((u-v)%mod+mod)%mod;
                    E=(ll)E*wn[id]%mod;
                }
            }
        }
        if(t==-1)
        {
            rep(i,1,len/2-1)swap(F[i],F[len-i]);
            ll inv=qpow(len,mod-2);
            rep(i,0,len-1)F[i]=(ll)F[i]%mod*inv%mod;
        }
    }
}
int a[NN],n,k;
int main()
{
	NTT::init();
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){int x;scanf("%d",&x);a[x]=1;}
	NTT::NTT(a,1<<20,1);
	for(int i=0;i<(1<<20);i++)a[i]=qpow(a[i],n/2);
	NTT::NTT(a,1<<20,-1);
	int ans=0;
	for(int i=0;i<=9*n/2;i++)ans=(ans+1ll*a[i]*a[i])%mod;
	printf("%d\n",ans);
	return 0;
}