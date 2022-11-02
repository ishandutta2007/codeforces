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
	#ifdef newbiewzs
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
const int B=450;
const int inf=1e9;
int T,n,ans,maxx,a[N],pos[N];
int f[N][B+5],g[N][B+5];
int find(int x,int Y){
	if(g[x][Y]!=x){
		return g[x][Y]=find(g[x][Y],Y);
	}
	return x;
}
void merge(int x,int y,int Y){
	x=find(x,Y);
	y=find(y,Y);
	if(x==y)return ;
	g[y][Y]=x;
}
void work(int u,int v,int l,int r){
	if(l>r)return ;
	int tmp=find(r,u);
	while(tmp>=l){
		f[tmp][u+1]=max(f[tmp][u+1],a[v]-a[tmp]-1);
		merge(tmp-1,tmp,u);
		tmp--;
		tmp=find(tmp,u);
	}
}
int solve(){
	int mexx=0;
	if(n==2){
		new char;
	}
	for(int i=n;i>=2;i--){
		f[i][0]=inf;
		for(int j=1;j<=B;j++){
			if(f[i][j]==-inf)break;
			f[i][j]=min(f[i][j],f[i][j-1]);
		}
		for(int j=0;j<=B;j++){
			if(f[i][j]==-inf)break;
			int L=max(a[i]-f[i][j],1);
			int R=min(a[i]-f[i][j+1]-1,maxx);
			if(R<0)R=0;
			L=pos[L-1]+1;
			R=pos[R];
			if(R>=i)R=i-1;
			work(j,i,L,R);
			mexx=max(mexx,j);
		}
	}
	for(int i=1;i<=B;i++){
		if(f[1][i]==-inf)break;
		mexx=max(mexx,i);
	}
	#ifdef newbiewzs
	debug(mexx);
	#endif
//	if(mexx==0)puts("SSS");
	return mexx+1;
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();maxx=0;
		for(int i=1;i<=n;i++)a[i]=read(),maxx=max(maxx,a[i]),pos[a[i]]=i;
		for(int i=1;i<=maxx;i++)if(!pos[i])pos[i]=pos[i-1];
		for(int i=1;i<=n;i++)for(int k=0;k<=B+1;k++)g[i][k]=i,f[i][k]=-inf;
		ans^=solve();
		for(int i=1;i<=maxx;i++)pos[i]=0;
	}
	if(!ans)puts("NO");
	else puts("YES");
	return 0;
}