#pragma GCC optimize(3)
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
    inline int print(ll x)
    {
        if(x<0)ss[++ssl]='-',x=(-x);
		if(!x) ss[++ssl]='0';for(ttl=0;x;x/=10) tt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ss[++ssl]=tt[ttl];return ss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ss+1,sizeof(char),ssl,stdout),ssl=0,0;}
}using namespace IO_BUFF;
const int N=1e5+5;
int n,m,x[N],y[N],z[N],q;
struct node{
	int to,dis,id;
};
vector<node>g[N];
vector<pii> v[N],gg[N];
bool vis[N],us[N];

void dfs(int u){
	vis[u]=1;
	for(auto i:g[u]){
		if(vis[i.to])continue;
		v[u].pb(mp(i.to,i.dis));
		us[i.id]=1;
		dfs(i.to);
	}
}
struct LCT{
	ll deep[N];
	int son[N],fu[N],siz[N],top[N],sd[N];
	void dfs(int u){
		siz[u]=1;
		for(auto i:v[u]){
			fu[i.fi]=u;
			deep[i.fi]=deep[u]+i.se;
			sd[i.fi]=sd[u]+1;
			dfs(i.fi);
			if(siz[i.fi]>siz[son[u]])son[u]=i.fi;
			siz[u]+=siz[i.fi];
		}
	}
	void dfs1(int u,int fa){
		top[u]=fa;
		if(son[u])dfs1(son[u],fa);
		for(auto i:v[u]){
			if(top[i.fi])continue;
			dfs1(i.fi,i.fi);
		}
	}
	ll dis(int x,int y){
		return deep[x]+deep[y]-2ll*deep[lca(x,y)];
	}
	int lca(int x,int y){
		while(top[x]!=top[y]){
			if(sd[top[x]]<sd[top[y]])swap(x,y);
			x=fu[top[x]];
		}
		if(sd[x]<sd[y])swap(x,y);
		return y;
	}
}t;
int id[N],tot,st[N],top;
ll ans[22][N];
struct TP{
	int id;
	ll val;
	friend bool operator <(TP x,TP y){
		return x.val>y.val;
	}
};
ll dis[N],pd[N];
void work(int u){
	priority_queue<TP>q;
	memset(dis,10,sizeof(dis));
	memset(pd,0,sizeof(pd));
	q.push({x[st[u]],0});
	q.push({y[st[u]],0});
	dis[x[st[u]]]=dis[y[st[u]]]=0;
	while(!q.empty()){
		auto u=q.top();q.pop();
		if(pd[u.id])continue;
		pd[u.id]=1;
		for(auto i:gg[u.id]){
			if(dis[i.fi]>dis[u.id]+i.se){
				dis[i.fi]=dis[u.id]+i.se;
				q.push({i.fi,dis[i.fi]});
			}
		}
	}
	memcpy(ans[u],dis,sizeof(dis));
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();
	for(int i=1;i<=m;i++){
		x[i]=read();y[i]=read();z[i]=read();
		g[x[i]].pb({y[i],z[i],i});
		g[y[i]].pb({x[i],z[i],i});
		gg[x[i]].pb(mp(y[i],z[i]));
		gg[y[i]].pb(mp(x[i],z[i]));
	}
	dfs(1);
	t.dfs(1);
	t.dfs1(1,1);
	for(int i=1;i<=m;i++){
		if(us[i])continue;
		st[++top]=i;
		id[i]=top;
	}
	for(int i=1;i<=top;i++){
		work(i);
	}
	q=read();
	int tx,ty;
	for(int i=1;i<=q;i++){
		tx=read();ty=read();
		ll da=t.dis(tx,ty);
		for(int k=1;k<=top;k++){
			da=min(da,ans[k][tx]+ans[k][ty]+z[st[k]]);
		}
		print(da);
	}
	Flush(); 
	return 0;
}