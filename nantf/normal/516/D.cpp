#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020,mod=998244353;
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
int n,q,el,head[maxn],to[maxn],nxt[maxn],w[maxn],rt=1,p[maxn],fa[maxn],sz[maxn];
ll d[maxn][2],d2[maxn],D[maxn];
bool vis[maxn];
inline bool cmp(int x,int y){
	return D[x]<D[y];
}
inline void add(int u,int v,int w_){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=w_;
}
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
void unite(int x,int y){
	x=getfa(x);y=getfa(y);
	if(x==y) return;
	fa[x]=y;
	sz[y]+=sz[x];
}
void dfs(int u,int f){
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs(v,u);
		if(d[v][0]+w[i]>d[u][0]) d[u][1]=d[u][0],d[u][0]=d[v][0]+w[i];
		else d[u][1]=max(d[u][1],d[v][0]+w[i]);
	}
}
void dfs2(int u,int f){
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		d2[v]=max(d2[v],d2[u]+w[i]);
		if(d[v][0]+w[i]==d[u][0]) d2[v]=max(d2[v],d[u][1]+w[i]);
		else d2[v]=max(d2[v],d[u][0]+w[i]);
		dfs2(v,u);
	}
}
int main(){
	n=read();
	FOR(i,1,n-1){
		int u=read(),v=read(),w=read();
		add(u,v,w);add(v,u,w);
	}
	dfs(1,0);dfs2(1,0);
	FOR(i,1,n) D[i]=max(d[i][0],d2[i]);
	FOR(i,1,n) p[i]=i;
	sort(p+1,p+n+1,cmp);
	q=read();
	while(q--){
		ll x=read();
		FOR(i,1,n) fa[i]=i,sz[i]=1,vis[i]=0;
		int cur=n,ans=1;
		ROF(i,n,1){
			vis[p[i]]=true;
			while(D[p[cur]]-D[p[i]]>x){
				sz[getfa(p[cur])]--;
				vis[p[cur]]=false;
				cur--;
			}
			for(int j=head[p[i]];j;j=nxt[j]) if(vis[to[j]]){
				unite(p[i],to[j]);
				ans=max(ans,sz[getfa(to[j])]);
			}
		}
		printf("%d\n",ans);
	}
}