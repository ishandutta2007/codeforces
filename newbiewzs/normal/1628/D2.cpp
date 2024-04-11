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
#define cpy(x,y) memcpy(x,y,sizeof(x))
//#pragma GCC optimize(3)
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
const int N=1e6+5;
const int M=1e6;
int fac[N],ifac[N],pw[N];
int T,n,m,k;
int C(int x,int y){
	if(x<y)return 0;
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	fac[0]=ifac[0]=pw[0]=1;
	for(int i=1;i<=M;i++)fac[i]=1ll*fac[i-1]*i%mod,pw[i]=2ll*pw[i-1]%mod;
	ifac[M]=ksm(fac[M],mod-2);
	for(int i=M-1;i>=1;i--)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	T=read();
	while(T--){
		n=read();m=read();k=read();
		int ans=0;
		if(n==m){
			cout<<1ll*k*n%mod<<'\n';
			continue;
		}
		for(int i=1;i<=m;i++){
			int ta=(m-i);
			int tb=(n-(m-i)-(i+1));
			if(ta<0 || tb<0)continue;
			int bs=ta+tb+1;
			int tmp=C(bs-1,ta);
			ans=add(ans,1ll*tmp*k%mod*i%mod*ksm(pw[bs],mod-2)%mod);
		}
		cout<<ans<<'\n';
	}
	return 0;
}