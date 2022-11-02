#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<bitset>
#include<set>
#include<cmath>
#include<ctime>
#include<random>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
#define re register
#define il inline
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
#define dbg(x) cerr<<"In Line "<< __LINE__<<" the "<<#x<<" = "<<x<<'\n';
#define dpi(x,y) cerr<<"In Line "<<__LINE__<<" the "<<#x<<" = "<<x<<" ; "<<"the "<<#y<<" = "<<y<<'\n';
// #pragma GCC optimize(3)
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	mt19937 rnd(time(0)^(ll)(new char));
	int rend(int x){
		return rnd()%x+1;
	}
	void rendom_shuffle(int *a,int len){
		shuffle(a+1,a+len+1,rnd);
	}
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
	inline int gc(){
	    if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
	    return (HD==TL)?EOF:*HD++;
	}
	inline int inn(){
	    int x,ch,s=1;while((ch=gc())<'0'||ch>'9')if(ch=='-')s=-1;x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x*s;
	}
	char ssss[19999999],tttt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ssss[++ssl]='-',x=(-x);
		if(!x) ssss[++ssl]='0';for(ttl=0;x;x/=10) tttt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ssss[++ssl]=tttt[ttl];return ssss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ssss+1,sizeof(char),ssl,stdout),ssl=0,0;}
	int read(){
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
	}
}using namespace IO_BUFF;
namespace CFConTest{
	const int mod=1e9+7;
	inline int add(const int &x,const int &y){
		return (x+y>=mod?x+y-mod:x+y);
	}
	inline int del(const int &x,const int &y){
		return (x-y<0?x-y+mod:x-y);
	}
	int ksm(int x,int k){
		int base=1;
		while(k){
			if(k&1)base=1ll*base*x%mod;
			k>>=1;
			x=1ll*x*x%mod;
		}
		return base;
	}
};
using namespace CFConTest;
const int N=2e3+5;
const int M=2e5;
int n,m,a,b,p,k;
int f[N][N],g[M+5],fac[M+5],ifac[M+5];
int s[N],sg[N],sgs[N];
int C(int x,int y){
	if(x<y)return 0;
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#endif
	n=read();m=read();
	a=read();b=read();
	k=read();
	p=1ll*a*ksm(b,mod-2)%mod;
	fac[0]=1;ifac[0]=1;
	for(int i=1;i<=M;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[M]=ksm(fac[M],mod-2);
	for(int i=M-1;i>=1;i--)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	for(int i=0;i<=k;i++){
		g[i]=1ll*C(k,i)*ksm(p,i)%mod*ksm(del(1,p),k-i)%mod;
	}
	f[0][m]=1;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++){
			s[k]=add(s[k-1],f[i-1][k]);
		}
		sg[0]=g[0];
		for(int k=1;k<=m;k++){
			sg[k]=add(sg[k-1],g[k]);
			sgs[k]=add(sgs[k-1],1ll*g[k]*s[k]%mod);
		}
		for(int k=1;k<=m;k++){
			f[i][k]=add(f[i][k],1ll*g[m-k]*del(s[m],s[m-k])%mod*sg[k-1]%mod);
			f[i][k]=del(f[i][k],1ll*g[m-k]*sgs[k-1]%mod);
		}
	}
	int summ=0;
	for(int k=1;k<=m;k++)summ=add(summ,f[n][k]);
	cout<<summ;
    #ifdef newbiewzs
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}