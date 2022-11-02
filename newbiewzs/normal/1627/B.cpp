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
const int N=5e5+5;
int T;
int n,m;
vi v[N];
int st[N],top;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();m=read();
		for(int i=1;i<=n;i++)v[i].resize(m+5);
		queue<pii>q;
		int ans=0;
		if(n&1){
			if(m&1){
				v[n/2+1][m/2+1]=1;
				
			}
			else{
				v[n/2+1][m/2]=v[n/2+1][m/2+1]=1;
			}
		}
		else{
			
			if(m&1){
				v[n/2][m/2+1]=1;
				v[n/2+1][m/2+1]=1;
			}
			else{
				v[n/2+1][m/2]=v[n/2+1][m/2+1]=1;
				v[n/2][m/2]=v[n/2][m/2+1]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int k=1;k<=m;k++){
				if(v[i][k])q.push(mp(i,k));
			}
		}
		ans=(n/2)+(m/2)-1;
		top=0;
		while(!q.empty()){
			pii u=q.front();q.pop();
			int x=u.fi;
			int y=u.se;
			st[++top]=v[x][y];
			for(int i=0;i<4;i++){
				if(x+dx[i]>0 && x+dx[i]<=n && y+dy[i]>0 && y+dy[i]<=m && !v[x+dx[i]][y+dy[i]]){
					v[x+dx[i]][y+dy[i]]=v[x][y]+1;
					q.push(mp(x+dx[i],y+dy[i]));
				}
			}
		}
		for(int i=1;i<=top;i++){
			cout<<ans+st[i]<<" ";
		}
		for(int i=1;i<=n;i++)v[i].clear();
		cout<<'\n';
	}
	return 0;
}