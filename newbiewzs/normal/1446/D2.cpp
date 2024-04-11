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
		int cnttt=0;
		template<typename T>
		T debug(T x){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
		  	cerr<<x<<" ";
		  	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		}
		template<typename T,typename ...Types>
		void debug(T x,Types ... y){
			cnttt++;int tmp=cnttt;
			debug(x);
			debug(y...);
			if(tmp==cnttt)cerr<<'\n';
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
	inline int read(){
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
}using namespace IO_BUFF;
const int N=2e5+5;
int n,B,maxx,cnt,pos,s[N],a[N],tong[N],d[N],las[N*2];
int ans;
void work(int u){
	for(int i=1;i<=n;i++)d[i]=d[i-1]+(a[i]==u);
	memset(las,-1,sizeof(las));
	for(int i=n;i>=1;i--){
		int tmp=s[i-1]-d[i-1];
		if(~las[tmp+N]){
			ans=max(ans,las[tmp+N]-i+1);
		}
		int tpp=s[i]-d[i];
		if(las[tpp+N]==-1)las[tpp+N]=i;
	}
}
void solve(int u){
	int head=1;
	mem0(tong);
	int maxx=0,cnt=0,cz=0;
	for(int i=1;i<=n;i++){
		if(tong[a[i]]==u){
			cnt--;cz++;
		}
		tong[a[i]]++;
		if(tong[a[i]]==u){
			cnt++;
		}
		while(cz){
			if(tong[a[head]]==u+1)cz--,cnt++;
			if(tong[a[head]]==u)cnt--;
			tong[a[head]]--;
			head++;
		}
		if(cnt>1){
			ans=max(ans,i-head+1);	
		}
	}
}
int main(){
	#ifdef newbiewzs
	#else
	#endif
	n=read();
	B=ceil(1.0*sqrt(n)+1);
	for(int i=1;i<=n;i++){
		a[i]=read();
		tong[a[i]]++;
	}
	maxx=*max_element(tong+1,tong+n+1);
	for(int i=1;i<=n;i++){
		if(tong[i]==maxx)cnt++,pos=i;
	}
	if(cnt>1){
		cout<<n;return 0;
	}
	for(int i=1;i<=n;i++)s[i]=s[i-1]+(a[i]==pos);
	for(int i=1;i<=n;i++){
		if(tong[i]>=B && i!=pos)work(i);
	}
	for(int i=1;i<=B;i++){
		solve(i);
	}
	cout<<ans;
	return 0;
}