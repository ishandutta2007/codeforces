#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int x,y,z;
	node(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
};

int n,m,q,tot,scnt,ncnt;
int v[400005],c[400005],nxt[400005],h[200005],dfn[200005],low[200005],col[200005];
vector<int> pt[200005];
vector<node> ed[200005];
stack<int> stk;
bool vis[200005],ins[200005];
ll dep[200005],g[200005],d1[200005],d2[200005];

void addedge(int x,int y,int z){v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;}

void tarjan(int u){
	dfn[u]=low[u]=++ncnt;
	stk.push(u); ins[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(!dfn[v[p]]) tarjan(v[p]),chkmin(low[u],low[v[p]]);
		else if(ins[v[p]]) chkmin(low[u],dfn[v[p]]);
	}
	if(dfn[u]==low[u]){
		int tmp;
		scnt++;
		do{
			tmp=stk.top(); stk.pop();
			col[tmp]=scnt,ins[tmp]=0,pt[scnt].pb(tmp);
		}while(tmp!=u);
	}
}

void dfs1(int u){
	for(int p=h[u];p;p=nxt[p]){
		if(vis[v[p]]) continue;
		vis[v[p]]=1;
		d1[v[p]]=d1[u]+c[p];
		dfs1(v[p]);
	}
}

void dfs2(int u){
	for(int p=h[u];p;p=nxt[p]){
		if(vis[v[p]]) continue;
		vis[v[p]]=1;
		d2[v[p]]=d2[u]+c[p];
		dfs2(v[p]);
	}
}

int main(){
	n=readint(); m=readint();
	int x,y,z;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint(); z=readint();
		addedge(x,y,z);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++) for(int p=h[i];p;p=nxt[p]) if(col[i]==col[v[p]]) ed[col[i]].pb(node(i,v[p],c[p]));
	for(int i=1;i<=scnt;i++){
		for(auto r:pt[i]) h[r]=vis[r]=0; tot=0;
		for(auto r:ed[i]) addedge(r.x,r.y,r.z);
		vis[pt[i][0]]=1; dfs1(pt[i][0]);
		for(auto r:pt[i]) h[r]=vis[r]=0; tot=0;
		for(auto r:ed[i]) addedge(r.y,r.x,r.z);
		vis[pt[i][0]]=1; dfs2(pt[i][0]);
		for(auto r:ed[i]) g[i]=__gcd(g[i],d1[r.x]+r.z+d2[r.y]);
	}
	q=readint();
	while(q--){
		x=readint(); y=readint(); z=readint();
		ll tmp=__gcd(g[col[x]],(ll)z);
		if((z-y)%tmp==0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}