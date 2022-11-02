#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
typedef long long LL;
const int mod = 998244353;
int qpow(int a,int b){
        int ret=1;
        while(b){
                if(b&1)ret=(LL)ret*a%mod;
                a=(LL)a*a%mod;
                b>>=1;
        }
        return ret;
}
namespace NTT{
    const int g=3;
    const int NN=250010;
	#define rep(i,s,t) for(int i = s;i <= t;i ++)
    int wn[NN<<2];
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
                    int u=F[k],v=(LL)E*F[k+h/2]%mod;
                    F[k]=(u+v)%mod,F[k+h/2]=((u-v)%mod+mod)%mod;
                    E=(LL)E*wn[id]%mod;
                }
            }
        }
        if(t==-1)
        {
            rep(i,1,len/2-1)swap(F[i],F[len-i]);
            LL inv=qpow(len,mod-2);
            rep(i,0,len-1)F[i]=(LL)F[i]%mod*inv%mod;
        }
    }
    void multiply(int *a,int len1,int *b,int len2)
    {
        int len=1;
        while(len<len1+len2)len<<=1;
        rep(i,len1,len-1)a[i]=0;
        rep(i,len2,len-1)b[i]=0;
        NTT(a,len,1); NTT(b,len,1);
        rep(i,0,len-1)a[i]=(LL)a[i]*b[i]%mod;
        NTT(a,len,-1);
    }
}
#define rep(i,n) for(int i=1;i<=n;i++)
const int N=250010;
int n,deg[N],fac[N];
int ans[N<<1],tmp1[N<<2],tmp2[N<<2];
void work(int l,int r,int st)
{
	if(l==r){ans[st]=1;ans[st+1]=deg[l];return;}
	int mid=(l+r)>>1,st2=st+(mid-l+1)+1;
	work(l,mid,st);
	work(mid+1,r,st2);
	int len1=mid-l+2,len2=r-mid+1;
	for(int i=0;i<len1;i++)tmp1[i]=ans[st+i];
	for(int i=0;i<len2;i++)tmp2[i]=ans[st2+i];
	NTT::multiply(tmp1,len1,tmp2,len2);
	int len=r-l+2;
	for(int i=0;i<len;i++)ans[st+i]=tmp1[i];
}
int main()
{
	NTT::init();
	scanf("%d",&n);
	fac[0]=1;
	rep(i,n)fac[i]=(LL)fac[i-1]*i%mod;
	rep(i,n-1){int x,y;scanf("%d%d",&x,&y);deg[x]++;deg[y]++;}
	rep(i,n-1)deg[i+1]--;
	work(1,n,0);
	int ANS=(LL)ans[0]*fac[n]%mod;
	rep(i,n)ANS=(ANS+((i&1)?-1:1)*(LL)ans[i]*fac[n-i]%mod+mod)%mod;
	printf("%d\n",ANS);
    return 0;
}