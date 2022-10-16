#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=133,mod=998244353;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0;bool f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
inline int qmo(int x){return x+((x>>31)&mod);}
int n,a[maxn][maxn],p[maxn],ans;
namespace flow{
	const int maxn=33333,maxm=maxn*12;
	int el=1,head[maxn],to[maxm],nxt[maxm],fl[maxm],s,t,dis[maxn],q[maxn],h,r,cur[maxn];
	inline void add(int u,int v,int c){
		to[++el]=v;nxt[el]=head[u];head[u]=el;fl[el]=c;
		to[++el]=u;nxt[el]=head[v];head[v]=el;fl[el]=0;
	}
	inline void add(int u,int v){
		add(2*u-1,2*v-1,1e9);
		add(2*u,2*v,1e9);
		add(2*u-1,2*v,1e9);
	}
	bool bfs(){
		FOR(i,1,t) dis[i]=1e9,cur[i]=head[i];
		q[h=r=1]=s;
		dis[s]=0;
		while(h<=r){
			int u=q[h++];
			for(int i=head[u];i;i=nxt[i]){
				int v=to[i];
				if(fl[i] && dis[v]>dis[u]+1) dis[v]=dis[u]+1,q[++r]=v;
			}
		}
		return dis[t]!=1e9;
	}
	int dfs(int u,int res){
		if(u==t || !res) return res;
		int f=0,tot=0;
		for(int &i=cur[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[v]==dis[u]+1 && (f=dfs(v,min(res,fl[i])))){
				fl[i]-=f;fl[i^1]+=f;
				res-=f;tot+=f;
				if(!res) break;
			}
		}
		return tot;
	}
	int dinic(){
		int tot=0;
		while(bfs()) tot+=dfs(s,1e9);
		return tot;
	}
}
using namespace flow;
inline int id(int x,int y){return (x-1)*n+y;}
int main(){
	n=read();
	FOR(i,1,n) FOR(j,1,n) a[i][j]=read();
	FOR(i,1,n){
		FOR(j,1,n) p[a[i][j]]=j;
		FOR(j,1,n-1) add(id(i,p[j]),id(i,p[j+1]));
	}
	FOR(j,1,n){
		FOR(i,1,n) p[a[i][j]]=i;
		FOR(i,1,n-1) add(id(p[i],j),id(p[i+1],j));
	}
	s=2*n*n+1;t=s+1;
	FOR(i,1,n) FOR(j,1,n){
		int w=read()+n;
		ans+=w;
		add(s,2*id(i,j)-1,w);
		add(2*id(i,j),t,w);
	}
	printf("%d\n",ans-dinic()-n*n);
}