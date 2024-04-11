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
const int N=3e5+5;
const int mod=998244353;
int n,m,summ,ans,bs,h[N],d[N],f[2],g[2],pw[N];
char c[N];
int ksm(int x,int k){
	int base=1;
	while(k){
		if(k&1)base=1ll*base*x%mod;
		k>>=1;
		x=1ll*x*x%mod;
	}
	return base;
}
inline int add(const int &x,const int &y){
	return (x+y>=mod?x+y-mod:x+y);
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();
	vector<vector<int>>a(n+5,vi(m+5,0));
	for(int i=1;i<=n;i++){
		scanf("%s",c+1);
		for(int k=1;k<=m;k++){
			if(c[k]=='*')a[i][k]=0;
			else a[i][k]=1,summ++;
		}
	}
	if(summ<2){
		cout<<0;return 0;
	}
	pw[0]=1;
	for(int i=1;i<=n*m;i++)pw[i]=2ll*pw[i-1]%mod;
	for(int i=1;i<=n;i++){
		int pre=0;
		f[0]=1;f[1]=0;
		for(int k=1;k<=m;k++){
			if(k==3){
				new char;
			}
			if(a[i][k] && a[i][k+1]){
				ans=add(ans,1ll*f[0]*pw[summ-pre-2]%mod);
			}
			if(a[i][k]){
				pre++;
				int x=f[0],y=f[1];
				f[0]=add(x,2ll*y%mod);
				f[1]=x;
			}
			else{
				f[0]=add(f[0],f[1]);
				f[1]=0;
			}
		}
	}
	for(int k=1;k<=m;k++){
		f[0]=1;f[1]=0;int pre=0;
		for(int i=1;i<=n;i++){
			if(a[i][k] && a[i+1][k]){
				ans=add(ans,1ll*f[0]*pw[summ-pre-2]%mod);
			}
			if(a[i][k]){
				pre++;
				int x=f[0],y=f[1];
				f[0]=add(x,2ll*y%mod);
				f[1]=x;
			}
			else{
				f[0]=add(f[0],f[1]);
				f[1]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}