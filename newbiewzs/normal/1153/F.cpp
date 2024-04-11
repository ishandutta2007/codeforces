#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#include<cmath>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
#define fl fflush(stdout)
#define re register
#define il inline
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
// #pra gma GCC opti mize(3)
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
	inline int gc(){
	    if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
	    return (HD==TL)?EOF:*HD++;
	}
	inline int inn(){
	    int x,ch;while((ch=gc())<'0'||ch>'9');x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x;
	}
	char ss[19999999],tt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ss[++ssl]='-',x=(-x);
		if(!x) ss[++ssl]='0';for(ttl=0;x;x/=10) tt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ss[++ssl]=tt[ttl];return ss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ss+1,sizeof(char),ssl,stdout),ssl=0,0;}
	int read(){
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
	}
}using namespace IO_BUFF;
const int N=2005;
const int mod=998244353;
inline int add(const int &x,const int &y){
	return (x+y>=mod?x+y-mod:x+y);
}
int n,m,l,f[N*2][N],fac[N],summ;
int ksm(int x,int k){
	int base=1;
	while(k){
		if(k&1)base=1ll*base*x%mod;
		k>>=1;
		x=1ll*x*x%mod;
	}
	return base;
}
int main(){
	#ifdef newbiewzs
	#else
	#endif
	n=read();m=read();l=read();
	l=1ll*l*ksm(2*n+1,mod-2)%mod;
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=1ll*fac[i-1]*i%mod;
	}
	f[0][0]=1;
	for(int i=1;i<=n*2;i++){
		for(int k=0;k<=n;k++){
			f[i][k]=add(f[i][k],f[i-1][k-1]);
			f[i][k]=add(f[i][k],1ll*f[i-1][k+1]*(k+1)%mod);
		}
	}
	for(int i=1;i<=n*2;i++){
		for(int k=m;k<=n;k++){
			summ=add(summ,1ll*f[i][k]*f[2*n-i][k]%mod*l%mod*fac[k]%mod);
		}
	}
	cout<<(1ll*summ*ksm(f[n*2][0],mod-2)%mod);
	return 0;
}