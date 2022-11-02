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
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	#ifdef WIN
		#include<windows.h>
		int cnt=0;
		template<typename T>
		T debug(T x){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
		  	cerr<<x<<" ";
		  	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		}
		template<typename T,typename ...Types>
		void debug(T x,Types ... y){
			cnt++;int tmp=cnt;
			debug(x);
			debug(y...);
			if(tmp==cnt)cerr<<'\n';
		}
	#else
		// Linux
		/*#define Green \033[32m
		#define Reset \033[0m\n
		void debug(int x){
			cout<<"Green"<<x<<"Reset";
		}*/
	#endif
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
const int N=1e5+5;
const int mod=998244353;

inline int add(const int &x,const int &y){
	return (x+y>=mod?x+y-mod:x+y);
}
inline int del(const int &x,const int &y){
	return (x-y<0?x-y+mod:x-y);
}
int n,m,inv,S[N],g[N],f[N],pre[N];
int ksm(int x,int k){
	int base=1;
	while(k){
		if(k&1)base=1ll*base*x%mod;
		k>>=1;
		x=1ll*x*x%mod;
	}
	return base;
}
void init(){
	g[0]=1;
	for(int i=1;i<=min(m,n);i++)g[i]=1ll*g[i-1]*inv%mod;
	f[0]=1;
	for(int i=1;i<=min(m,n);i++)f[i]=1ll*f[i-1]*(n-i+1)%mod;
}
struct NTT{
	const int g=3;
	const int fg=332748118;
	int le,nl,zs,r[N<<2],fac[N],ifac[N],tpp[N<<2];
	int a[N<<2],b[N<<2];
	void prework(int &x){
		int tmp=x;x=1;
		while(x<tmp)x*=2,zs++;
		for(int i=0;i<x;i++)r[i]=((r[i>>1]>>1)|((i&1)<<(zs-1)));
	}
	void ntt(int a[],int len,int op){
		for(int i=0;i<len;i++)if(r[i]<i)swap(a[r[i]],a[i]);
		for(int i=1;i<len;i*=2){
			const int w=ksm(op==1?g:fg,(mod-1)/(i*2));
			tpp[0]=1;
			for(int k=1;k<i;k++)tpp[k]=1ll*tpp[k-1]*w%mod;
			for(int k=0;k<len;k+=i*2){
				for(int j=0;j<i;j++){
					const int x=a[k+j];
					const int y=1ll*a[i+k+j]*tpp[j]%mod;
					a[k+j]=add(x,y);
					a[i+k+j]=del(x,y);
				}
			}
		}
		if(op==-1){
			const int inv=ksm(len,mod-2);
			for(int i=0;i<len;i++)a[i]=1ll*a[i]*inv%mod;
		}
	}
	void main(){
		fac[0]=ifac[0]=1;
		for(int i=1;i<=m;i++)fac[i]=1ll*fac[i-1]*i%mod;
		ifac[m]=ksm(fac[m],mod-2);
		for(int i=m-1;i>=1;i--)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
		int pre=1;
		for(int k=0;k<=m;k++){
			if(k&1)a[k]=(mod-ifac[k]);
			else a[k]=ifac[k];
			b[k]=1ll*ksm(k,m)*ifac[k]%mod;
		}
		le=m+m+1;
		prework(le);
		ntt(a,le,1);
		ntt(b,le,1);
		for(int i=0;i<le;i++)a[i]=1ll*a[i]*b[i]%mod;
		ntt(a,le,-1);
		for(int i=0;i<=m;i++)S[i]=a[i];
	}
}SS;

int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();inv=ksm(n,mod-2);
	SS.main();
	init();
	int ans=ksm(n,n),summ=0;
	for(int i=0;i<=min(m,n);i++){
		summ=add(summ,1ll*S[i]*f[i]%mod*g[i]%mod*ksm(inv+1,n-i)%mod);
	}
	cout<<1ll*ans*summ%mod;
	return 0;
}