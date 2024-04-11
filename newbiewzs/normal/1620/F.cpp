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
int T,n,a[N],st[N],top;
int f[N][2][2],sx[N][2][2],sy[N][2][2];
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)for(int k=0;k<2;k++)for(int j=0;j<2;j++)f[i][k][j]=1e9,sx[i][k][j]=sy[i][k][j]=1e9;
		f[1][0][0]=f[1][1][0]=-1e9;
		for(int i=1;i<n;i++){
			for(int k=0;k<2;k++){
				for(int j=0;j<2;j++){
					if(f[i][k][j]==1e9)continue;
					int tx=(k==0?a[i]:-a[i]);
					int ty=f[i][k][j]; 
					if(j)swap(tx,ty);
					for(int h=0;h<2;h++){
						int tmp=(h==0?a[i+1]:-a[i+1]);
						if(tmp>tx && f[i+1][h][0]>ty){
							f[i+1][h][0]=ty;
							sx[i+1][h][0]=k;
							sy[i+1][h][0]=j;
						}
						else if(tmp<tx && tmp>ty && f[i+1][h][1]>tx){
							f[i+1][h][1]=tx;
							sx[i+1][h][1]=k;
							sy[i+1][h][1]=j;
						}
					}
				}
			}
		}
		top=0;
		int tx=-1,ty=-1;
		for(int i=0;i<2;i++){
			for(int k=0;k<2;k++){
				if(f[n][i][k]<1e9){
					tx=i;ty=k;
				}
			}
		}
		if(tx==-1){
			puts("NO");
		}
		else{
			puts("YES");
			for(int i=n;i>=1;i--){
				st[++top]=(tx==0?a[i]:-a[i]);
				int ta=sx[i][tx][ty];
				int tb=sy[i][tx][ty];
				tx=ta;
				ty=tb;
			}
			while(top){
				cout<<st[top--]<<" ";
			}
			cout<<'\n';
		}
	}
	return 0;
}