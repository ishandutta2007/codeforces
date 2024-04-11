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
int n,m,x,y,z,tot,xx[N],yy[N],fu[N];
int a[N],dfn[N],ed[N],deep[N],pos[N],sd[N],st[N*2],top,dy[N];
vector<pii> v[N];
struct T{
	vi v[N];
	int f[21][N*2],id[21][N*2],lg[N*2];
	void prework(){
		lg[0]=-1;
		for(int i=1;i<=top;i++)lg[i]=lg[i>>1]+1;
		for(int i=1;i<=top;i++){
			f[0][i]=sd[st[i]];
			id[0][i]=st[i];
		}
		for(int i=1;(1<<i)<=top;i++){
			for(int k=1;k+(1<<i)-1<=top;k++){
				if(f[i-1][k]<f[i-1][k+(1<<(i-1))])id[i][k]=id[i-1][k];
				else id[i][k]=id[i-1][k+(1<<(i-1))];
				f[i][k]=min(f[i-1][k],f[i-1][k+(1<<(i-1))]);
			}
		}
	}
	int lca(int x,int y){
		if(x==y)return x;
		x=dy[x];y=dy[y];
		if(x>y)swap(x,y);
		int tmp=lg[y-x+1];
		if(f[tmp][x]<f[tmp][y-(1<<tmp)+1])return id[tmp][x];
		else return id[tmp][y-(1<<tmp)+1];
	}
	int dis(int x,int y){
		if(!x || !y)return 0;
		return sd[x]+sd[y]-2*sd[lca(x,y)];
	}
}t;
void dfs(int u,int fa){
	dfn[u]=++tot;pos[tot]=u;fu[u]=fa;sd[u]=sd[fa]+1;
	st[++top]=u;dy[u]=top;
	for(auto i:v[u]){
		if(i.fi==fa)continue;
		deep[i.fi]=deep[u]^(i.se);
		dfs(i.fi,u);st[++top]=u;
	}
	ed[u]=tot;
	
}
struct node{
	int x,y,val;
	friend node operator + (node x,node y){
		node z=x;
		if(y.val>=z.val && y.x && y.y)z=y;
		
		int tmp=t.dis(x.x,y.x);
		if(tmp>z.val)z.val=tmp,z.x=x.x,z.y=y.x;
		
		tmp=t.dis(x.x,y.y);
		if(tmp>z.val)z.val=tmp,z.x=x.x,z.y=y.y;
		
		tmp=t.dis(x.y,y.x);
		if(tmp>z.val)z.val=tmp,z.x=x.y,z.y=y.x;
		
		tmp=t.dis(x.y,y.y);
		if(tmp>z.val)z.val=tmp,z.x=x.y,z.y=y.y;
		
		return z;
	}
}summ[N*4][2];
int rev[N*4];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
void pushdown(int u){
	if(!rev[u])return ;
	swap(summ[ls][0],summ[ls][1]);
	swap(summ[rs][0],summ[rs][1]);
	rev[ls]^=1;
	rev[rs]^=1;
	rev[u]=0;
}
void update(int u){
	summ[u][0]=summ[ls][0]+summ[rs][0];
	summ[u][1]=summ[ls][1]+summ[rs][1];
}
void build(int u,int l,int r){
	if(l==r){
		summ[u][deep[pos[l]]]={pos[l],pos[l],0};
		summ[u][deep[pos[l]]^1]={0,0,0};
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(u);
}
void change(int u,int l,int r,int L,int R){
	if(L<=l && R>=r){
		rev[u]^=1;
		swap(summ[u][0],summ[u][1]);
		return ;
	}
	pushdown(u);
	if(L<=mid)change(ls,l,mid,L,R);
	if(R>mid)change(rs,mid+1,r,L,R);
	update(u);
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();
	for(int i=1;i<n;i++){
		x=read();y=read();z=read();
		xx[i]=x;yy[i]=y;
		v[x].pb(mp(y,z));
		v[y].pb(mp(x,z));
		t.v[x].pb(y);
		t.v[y].pb(x);
	}
	dfs(1,0);t.prework();
	build(1,1,n);
	
	m=read();
	for(int i=1;i<=m;i++){
		x=read();
		if(fu[xx[x]]!=yy[x])swap(xx[x],yy[x]);
		change(1,1,n,dfn[xx[x]],ed[xx[x]]);
		cout<<max(summ[1][0].val,summ[1][1].val)<<'\n';
	}
	return 0;
}