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
// #pra gma GCC opti mize(3)
#define int long long
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
const int mod=1e9+7;
const int N=3e6+10;
const int M=3e6+5;
int fac[N],ifac[N],f[N][3];
int ksm(int x,int k){
	int base=1;
	while(k){
		if(k&1)base=1ll*base*x%mod;
		k>>=1;
		x=1ll*x*x%mod;
	}
	return base;
}
int C(int x,int y){
	if(x<y)return 0;
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int n,q,x;
inline int add(const int &x,const int &y){
	return (x+y>=mod?x+y-mod:x+y);
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();q=read();
	fac[0]=ifac[0]=1;
	const int i3=ksm(3,mod-2);
	for(int i=1;i<=M;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[M]=ksm(fac[M],mod-2);
	for(int i=M-1;i>=1;i--)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	f[0][0]=f[0][1]=f[0][2]=n;
	for(int i=1;i<=3*n;i++){
		int tmp=C(3*n+1,i+1);
		int tma=add(2ll*f[i-1][2]%mod,f[i-1][1]);
		f[i][2]=(tmp-tma+mod)%mod;
		f[i][2]=1ll*f[i][2]*i3%mod;
		f[i][1]=add(f[i][2],f[i-1][2]);
		f[i][0]=add(f[i][1],f[i-1][1]);
	}
	for(int i=1;i<=q;i++){
		x=read();
		cout<<f[x][0]<<'\n';
	}
	return 0;
}