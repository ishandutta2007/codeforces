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
char c[N];
int n,x,y,a[N],b[N],sa[N],sb[N],st[N],top,ans;
int calc(){
	int tmp=0;
	for(int i=1;i<=n;i++){
		for(int k=i+1;k<=n;k++){
			if(b[i]==0 && b[k]==1)tmp=tmp+x;
			if(b[i]==1 && b[k]==0)tmp=tmp+y;
		}
	}
	return tmp;
}
int solvea(){
	for(int i=1;i<=n;i++){
		sa[i]=sa[i-1]+(a[i]==0);
		sb[i]=sb[i-1]+(a[i]==1);
	}
	int ta=0,tb=0;
	for(int i=1;i<=n;i++){
		if(a[i]==2){
			tb=tb+(sb[i-1]);
			ta=ta+(sb[n]-sb[i]);
		}
	}
	int tmp=ta*x+tb*y;
	for(int T=1;T<=top;T++){
		int i=st[T];
		tb=tb-(sb[i-1]);
		ta=ta-(sb[n]-sb[i]);
		
		ta=ta+sa[i-1];
		tb=tb+(sa[n]-sa[i]);
		
		tb=tb+(top-T);
		tb=tb-(T-1);
		tmp=min(tmp,ta*x+tb*y);
	}
	return tmp;
}
int solveb(){
	for(int i=1;i<=n;i++){
		sa[i]=sa[i-1]+(a[i]==0);
		sb[i]=sb[i-1]+(a[i]==1);
	}
	int ta=0,tb=0;
	for(int i=1;i<=n;i++){
		if(a[i]==2){
			ta=ta+(sa[i-1]);
			tb=tb+(sa[n]-sa[i]);
		}
	}
	int tmp=ta*x+tb*y;
	for(int T=1;T<=top;T++){
		int i=st[T];
		ta=ta-(sa[i-1]);
		tb=tb-(sa[n]-sa[i]);
		
		tb=tb+(sb[i-1]);
		ta=ta+(sb[n]-sb[i]);
		
		ta=ta+(top-T);
		ta=ta-(T-1);
		tmp=min(tmp,ta*x+tb*y);
	}
	return tmp;
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	scanf("%s",c+1);
	x=read();y=read();
	n=strlen(c+1);
	for(int i=1;i<=n;i++){
		if(c[i]=='0')a[i]=0;
		if(c[i]=='1')a[i]=1;
		if(c[i]=='?')a[i]=2,st[++top]=i;
	}
	int pa=0,pb=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			ans=ans+y*pb;
		}
		if(a[i]==1){
			ans=ans+x*pa;
		}
		if(a[i]==0)pa++;
		if(a[i]==1)pb++;
	}
	ans=ans+min(solvea(),solveb());
	cout<<ans;
	return 0;
}