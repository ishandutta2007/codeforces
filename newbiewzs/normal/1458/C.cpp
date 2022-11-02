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
const int N=1005;
const int M=1e5+5;
int T,n,m,a[N][N],v[N][N];
char c[M];
int p[4],t[4];
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();m=read();
		for(int i=0;i<n;i++){
			for(int k=0;k<n;k++){
				a[i][k]=read()-1;
			}
		}
		memset(t,0,sizeof(t));
		for(int i=1;i<=3;i++)p[i]=i;
		scanf("%s",c+1);
		for(int i=1;i<=m;i++){
			if(c[i]=='R'){
				t[2]++;
			}
			if(c[i]=='L'){
				t[2]--;
			}
			if(c[i]=='D'){
				t[1]++;
			}
			if(c[i]=='U'){
				t[1]--;
			}
			if(c[i]=='I'){
				swap(p[2],p[3]);
				swap(t[2],t[3]);
			}
			if(c[i]=='C'){
				swap(p[1],p[3]);
				swap(t[1],t[3]);
			}
		}
		for(int i=0;i<n;i++){
			for(int k=0;k<n;k++){
				int px,py,pz;
				if(p[1]==1)px=i;
				if(p[2]==1)py=i;
				if(p[3]==1)pz=i;
				if(p[1]==2)px=k;
				if(p[2]==2)py=k;
				if(p[3]==2)pz=k;
				if(p[1]==3)px=a[i][k];
				if(p[2]==3)py=a[i][k];
				if(p[3]==3)pz=a[i][k];
				v[((px+t[1])%n+n)%n][((py+t[2])%n+n)%n]=((pz+t[3])%n+n)%n;
			}
		}
		for(int i=0;i<n;i++){
			for(int k=0;k<n;k++){
				if(i==0 && k==1){
					new char;
				}
			//	if(!v[i][k])v[i][k]=n;
				cout<<v[i][k]+1<<" ";
			}
			cout<<'\n';
		}
		cout<<'\n';
	}
	return 0;
}