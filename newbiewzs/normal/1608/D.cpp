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
const int N=1e6+5;
const int M=1e6;
const int mod=998244353;
int fac[N],ifac[N];
int ksm(int x,int k){
	int base=1;
	while(k){
		if(k&1)base=1ll*base*x%mod;
		k>>=1;
		x=1ll*x*x%mod;
	}
	return base;
} 
int CC(int x,int y){
	if(x<y || y<0)return 0;
	return (1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod);
}
int n,A,B,C,D,E;
string c[N];
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	fac[0]=ifac[0]=1;
	for(int i=1;i<=M;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[M]=ksm(fac[M],mod-2);
	for(int i=M-1;i>=1;i--)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	n=read();
	int x=0,y=0,cnt=0,xx=1,yy=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		x|=(c[i]=="WW");
		y|=(c[i]=="BB");
		xx&=(c[i]=="??" || c[i]=="W?" || c[i]=="?B" || c[i]=="WB");
		yy&=(c[i]=="??" || c[i]=="B?" || c[i]=="?W" || c[i]=="BW");
		if(c[i]=="WW"){
			A++;
		}
		if(c[i]=="BB"){
			B++;
		}
		if(c[i]=="W?" || c[i]=="?W"){
			C++;
		}
		if(c[i]=="B?" || c[i]=="?B"){
			D++;
		}
		if(c[i]=="??"){
			E++;cnt++;
		}
	}
	int ans=CC(C+D+2*E,D+E-A+B);
	if(!x && !y)ans=(ans-ksm(2,cnt)+mod)%mod;
	ans=ans+xx+yy;
	cout<<ans;
	return 0;
}