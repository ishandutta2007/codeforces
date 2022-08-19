// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,tot;
int f[100005][20],dep[100005],v[200005],nxt[200005],h[100005],fa[100005],val[100005];
bool vis[200005];
pii e[200005];

int getf(int x){return x==fa[x]?x:fa[x]=getf(fa[x]);}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	for(int i=1;i<=19;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		f[v[p]][0]=u;
		dep[v[p]]=dep[u]+1;
		dfs(v[p],u);
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

int jump(int x,int y){
	for(int i=19;i>=0;i--) if(y&(1<<i)) x=f[x][i];
	return x;
}

void dfs2(int u,int fa){
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		val[v[p]]+=val[u];
		dfs2(v[p],u);
	}
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) e[i].fi=readint(),e[i].se=readint();
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int fx=getf(e[i].fi),fy=getf(e[i].se);
		if(fx==fy) continue;
		vis[i]=1;
		fa[fx]=fy;
		addedge(e[i].fi,e[i].se);
	}
	dep[1]=1; dfs(1,-1);
	for(int i=1;i<=m;i++){
		if(!vis[i]){
			int l=lca(e[i].fi,e[i].se);
			if(l==e[i].fi){
				val[1]++;
				val[jump(e[i].se,dep[e[i].se]-dep[e[i].fi]-1)]--;
				val[e[i].se]++;
			}
			else if(l==e[i].se){
				val[1]++;
				val[jump(e[i].fi,dep[e[i].fi]-dep[e[i].se]-1)]--;
				val[e[i].fi]++;
			}
			else val[e[i].fi]++,val[e[i].se]++;
		}
	}
	dfs2(1,-1);
	for(int i=1;i<=n;i++){
		if(val[i]==m-n+1) putchar('1');
		else putchar('0');
	}
	putchar('\n');
	return 0;
}