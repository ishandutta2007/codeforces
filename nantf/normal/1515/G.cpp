#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,m,q,el,head[maxn],to[maxn],nxt[maxn],w[maxn],dfn[maxn],low[maxn],dfc,scc,id[maxn],stk[maxn],tp;
bool ins[maxn],vis[maxn];
ll pre[maxn],g,ans[maxn];
inline void add(int u,int v,int ww){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=ww;
}
void dfs(int u){
	dfn[u]=low[u]=++dfc;
	stk[++tp]=u;
	ins[u]=true;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(!dfn[v]) dfs(v),low[u]=min(low[u],low[v]);
		else if(ins[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		scc++;
		do{
			int v=stk[tp];
			id[v]=scc;
			ins[v]=false;
		}while(stk[tp--]!=u);
	}
}
inline ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
void dfs2(int u){
	vis[u]=true;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(id[u]!=id[v]) continue;
		if(vis[v]){
			g=gcd(g,pre[u]+w[i]-pre[v]);
			continue;
		}
		pre[v]=pre[u]+w[i];
		dfs2(v);
	}
}
int main(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read(),w=read();
		add(u,v,w);
	}
	FOR(i,1,n) if(!dfn[i]) dfs(i);
	FOR(i,1,n) if(!vis[i]) g=0,dfs2(i),ans[id[i]]=g;
	q=read();
	while(q--){
		int u=read(),x=read(),y=read();
		x=(y-x)%y;
		if(gcd(x,y)%gcd(ans[id[u]],y)==0) puts("YES");
		else puts("NO");
	}
}