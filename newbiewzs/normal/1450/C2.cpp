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
const int N=305;
int T,n,summ;
char c[N][N],a[N][N];
bool check(){
	int tmp=0;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			if(c[i][k]!=a[i][k])tmp++;
		}
	}
	if(tmp<=(summ/3))return 1;
	return 0;
}
void solve(int u,int v){
	memcpy(a,c,sizeof(a));
	for(int i=1;i<=n;i++){
		int tx=(i+u)%3;
		for(int k=1+tx;k<=n;k+=3){
			if(a[i][k]=='X')a[i][k]='O';
		}
		int ty=(i+v)%3;
		for(int k=1+ty;k<=n;k+=3){
			if(a[i][k]=='O')a[i][k]='X';
		}
	}
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();summ=0;
		for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
		for(int i=1;i<=n;i++){
			for(int k=1;k<=n;k++){
				if(c[i][k]!='.')summ++;
			}
		}
		for(int i=0;i<3;i++){
			for(int k=0;k<3;k++){
				if(i==k)continue;
				solve(i,k);
				if(check()){
					goto qwq;
				}
			}
		}
		qwq:;
		for(int i=1;i<=n;i++){
			for(int k=1;k<=n;k++){
				cout<<a[i][k];
			}
			cout<<'\n';
		}
	}
	return 0;
}