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
#define int long long
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
const int mod=998244353;
const int N=550;
int n,m,fac[N],ifac[N],f[N][N];
int ksm(int x,int k){
	int base=1;
	while(k){
		if(k&1)base=1ll*base*x%mod;
		k>>=1;
		x=1ll*x*x%mod;
	}
	return base;
}
int C(int n,int m){
	if(n<m)return 0;
	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int dp(int x,int y){
	if(!x)return 1;
	if(f[x][y]!=-1)return f[x][y];
	int tmp=ksm(y,x);
	if(x<=1)return 0;
	if(y+1<=x)return tmp;
	tmp=1;int ans=0;
	if(x==3 && y==3){
		new char;
		// puts("kel");
	}
	for(int i=0;i<=x;i++,tmp=1ll*tmp*(x-1)%mod){
		int tpp=1ll*C(x,i)*tmp%mod;
		ans=(ans+1ll*tpp*dp(x-i,y-x+1)%mod)%mod;
	}
	f[x][y]=ans;
	return ans;
}
signed main(){
	#ifdef newbiewzs
	//	freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>=0;i--){
		ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	}
	ifac[0]=1;
//	cout<<C(3,2)<<endl;
	memset(f,-1,sizeof(f));
	cout<<dp(n,m);
	return 0;
}