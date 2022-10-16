#include<bits/stdc++.h>
namespace my_std{
	using namespace std;
	#define reg register
	#define Rint register int
	#define FOR(i,a,b) for(register int i=(a);i<=(b);++i)
	#define ROF(i,a,b) for(register int i=(a);i>=(b);--i)
	#define FORit(templ,arr,i,a,b) for(register templ *i=(arr)+(a);i!=(arr)+(b)+1;++i)
	#define ROFit(templ,arr,i,a,b) for(register templ *i=(arr)+(a);i!=(arr)+(b)-1;--i)
	#define GO(x,p,e,i,v) for(register int i=p[x].head,v;i;i=e[i].link)
	#define MEM(x,v) memset(x,v,sizeof(x))
	#define fir first
	#define sec second
	#define pq priority_queue
	#define PII pair<int,int>
	#define MP make_pair
	typedef long long LL;
	typedef double DB;
	inline int read(){
		int ans=0,f=1;char c=getchar();
		while(c>'9'||c<'0'){ f^=(c=='-'); c=getchar(); }
		for(;c<='9'&&c>='0';c=getchar()) ans=ans*10+c-'0'; return f?ans:-ans;
	}
	const int mod = 998244353,maxn=2000200;
	inline void inc(int &x,const int &y){ x+=y; if(x>=mod) x-=mod; }
	inline int ksm(int x,LL y){ int res=1; for(;y;y>>=1,x=1ll*x*x%mod) if(y&1) res=1ll*res*x%mod; return res;}
	inline int gcd(int x,int y){ if(x<y) swap(x,y); return y?gcd(y,x%y):x; }
	#define FILE(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
}
using namespace my_std;

struct ship{
	int at,atk,dis;
}sh[1111];
struct base{
	int at,def;
}bs[1111];
int n,m,dis[111][111],s,b,k,h,el,head[2222],to[2222222],nxt[2222222],with[2222],ans;
bool vis[2222];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
bool dfs(int u){
	if(vis[u]) return false;
	vis[u]=true;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(!with[v] || dfs(with[v])){
			with[v]=u;
			return true;
		}
	}
	return false;
}
int main(){
	n=read();m=read();
	MEM(dis,0x3f);
	FOR(i,1,m){
		int u=read(),v=read();
		dis[u][v]=dis[v][u]=1;
	}
	FOR(i,1,n) dis[i][i]=0;
	FOR(k,1,n) FOR(i,1,n) FOR(j,1,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	s=read();b=read();k=read();h=read();
	FOR(i,1,s) sh[i].at=read(),sh[i].atk=read(),sh[i].dis=read();
	FOR(i,1,b) bs[i].at=read(),bs[i].def=read();
	FOR(i,1,s) FOR(j,1,b) if(dis[sh[i].at][bs[j].at]<=sh[i].dis && sh[i].atk>=bs[j].def) add(i,j+s),add(j+s,i);
	FOR(i,1,s){
		MEM(vis,0);
		if(dfs(i)) ans++;
	}
	cout<<min(1ll*k*ans,1ll*h*s);
	return 0;
}