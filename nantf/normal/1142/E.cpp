#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
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
int n,m,dfn[maxn],low[maxn],stk[maxn],tp,cnt,id[maxn],deg[maxn],scnt,el,head[maxn],to[maxn],nxt[maxn],ans,q[maxn],h=1,r;
bool ins[maxn];
vector<int> vec[maxn]; 
inline int ask(int u,int v){
	printf("? %d %d\n",u,v);
	fflush(stdout);
	return read();
}
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u){
	dfn[u]=low[u]=++cnt;
	stk[++tp]=u;
	ins[u]=true;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(!dfn[v]) dfs(v),low[u]=min(low[u],low[v]);
		else if(ins[v]) low[u]=min(low[u],dfn[v]);
	}
//	printf("low[%d]=%d,dfn[%d]=%d\n",u,low[u],u,dfn[u]);
	if(low[u]==dfn[u]){
		scnt++;
		do{
			int v=stk[tp];
			ins[v]=false;
			id[v]=scnt;
			vec[scnt].PB(v);
		}while(stk[tp--]!=u);
	}
}
int main(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read();
		add(u,v);
	}
	FOR(i,1,n) if(!dfn[i]) dfs(i);
	FOR(u,1,n) for(int i=head[u];i;i=nxt[i]) if(id[u]!=id[to[i]]) deg[id[to[i]]]++;
	FOR(i,1,scnt) if(!deg[i]) q[++r]=i;
	ans=vec[q[h]].back();
	while(h!=r){
		int &at=q[h+1];
		int u=vec[at].back();
		if(!ask(ans,u)) swap(u,ans),swap(q[h],q[h+1]);
		for(int i=head[u];i;i=nxt[i]) if(id[u]!=id[to[i]] && !--deg[id[to[i]]]) q[++r]=id[to[i]];
		vec[at].pop_back();
		if(vec[at].empty()) swap(q[h],q[h+1]),h++;
	}
	printf("! %d\n",ans);
	fflush(stdout);
}