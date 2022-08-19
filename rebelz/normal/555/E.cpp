#include<bits/stdc++.h>

#define y1 dmytxdy
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

int n,m,q,tot,ncnt,scnt;
int v[400005],nxt[400005],h[200005],dep[200005],f[200005][20],bel[200005],dfn[200005],low[200005],d0[200005],d1[200005],x[200005],y[200005];
stack<int> s;

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa){
	dfn[u]=low[u]=++ncnt;
	s.push(u);
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa){
			fa=0;
			continue;
		}
		if(!dfn[v[p]]){
			dfs1(v[p],u);
			low[u]=min(low[u],low[v[p]]);
		}
		else low[u]=min(low[u],dfn[v[p]]);
	}
	if(dfn[u]==low[u]){
		scnt++;
		int tmp;
		do{
			tmp=s.top(); s.pop();
			bel[tmp]=scnt;
		}while(tmp!=u);
	}
}

void dfs2(int u){
	for(int i=1;i<=19;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int p=h[u];p;p=nxt[p]){
		if(f[v[p]][0]||v[p]==f[u][0]) continue;
		f[v[p]][0]=u,dep[v[p]]=dep[u]+1;
		dfs2(v[p]);
	}
}

void dfs3(int u){for(int p=h[u];p;p=nxt[p]) if(f[v[p]][0]==u) dfs3(v[p]),d0[u]+=d0[v[p]],d1[u]+=d1[v[p]];}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

int main(){
	n=readint(); m=readint(); q=readint();
	for(int i=1;i<=m;i++){
		x[i]=readint(); y[i]=readint();
		addedge(x[i],y[i]);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) dfs1(i,-1);
	memset(h,0,sizeof(h)); tot=0;
	for(int i=1;i<=m;i++) if(bel[x[i]]!=bel[y[i]]) addedge(bel[x[i]],bel[y[i]]);
	for(int i=1;i<=scnt;i++) if(!f[i][0]) dep[i]=1,dfs2(i);
	int x,y;
	while(q--){
		x=bel[readint()]; y=bel[readint()];
		int l=lca(x,y);
		if(!l) return printf("No\n"),0;
		d0[x]++,d0[l]--,d1[y]++,d1[l]--;
	}
	for(int i=1;i<=scnt;i++) if(!f[i][0]) dfs3(i);
	for(int i=1;i<=scnt;i++) if(d0[i]&&d1[i]) return printf("No\n"),0;
	printf("Yes\n");
	return 0;
}