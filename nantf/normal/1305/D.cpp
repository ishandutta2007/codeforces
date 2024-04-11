#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
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
int n,el,head[maxn],to[maxn],nxt[maxn],ch[maxn],cl,tot,deg[maxn],rt;
bool vis[maxn];
inline int query(int u,int v){
	printf("? %d %d\n",u,v);
	fflush(stdout);
	return read();
}
inline void submit(int u){
	printf("! %d\n",u);
	fflush(stdout);
	exit(0);
}
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u,int f){
	deg[u]=!!f;
	tot++;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f || vis[v]) continue;
		dfs(v,u);
		deg[u]++;
	}
	if(deg[u]!=1) rt=u;
}
void solve(int u){
	tot=0;
	dfs(u,0);
	if(tot==1) submit(u);
	if(tot==2){
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(vis[v]) continue;
			int x=query(u,v);
			submit(x);
		}
	}
	u=rt;
	vis[u]=true;
	cl=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(vis[v]) continue;
		ch[++cl]=v;
	}
	if(cl&1){
		FOR(i,1,cl/2){
			int x=ch[2*i-1],y=ch[2*i];
			int f=query(x,y);
			if(f==x) solve(x);
			if(f==y) solve(y);
			vis[x]=vis[y]=true;
		}
		vis[u]=false;
		solve(u);
	}
	else{
		FOR(i,1,cl/2){
			int x=ch[2*i-1],y=ch[2*i];
			int f=query(x,y);
			if(f==x) solve(x);
			if(f==y) solve(y);
		}
		submit(u);
	}
}
int main(){
	n=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	solve(1);
}
// shit problem, shit solution