// xtqqwq
#include<bits/stdc++.h>

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

int n,m,tot;
int f[300005][20],dep[300005],d[300005],g[300005],siz[300005],v[300005],nxt[300005],h[300005],x[300005],y[300005];
vector<int> vec[300005];

void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}

void dfs1(int u){
	for(int i=1;i<=19;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int p=h[u];p;p=nxt[p]){
		f[v[p]][0]=u,dep[v[p]]=dep[u]+1;
		dfs1(v[p]);
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

void dfs2(int u){
	g[u]=0;
	int sum=0;
	for(int p=h[u];p;p=nxt[p]){
		dfs2(v[p]);
		sum+=d[v[p]];
	}
	d[u]=sum;
	for(int p=h[u];p;p=nxt[p]) if(g[v[p]]==dep[u]) d[u]++,siz[v[p]]=1;//,cout<<"test "<<v[p]<<endl;
	for(int p=h[u];p;p=nxt[p]){
		if(d[u]-d[v[p]]-siz[v[p]]==0){
			if(g[v[p]]!=dep[u]) chkmax(g[u],g[v[p]]);
			for(auto r:vec[v[p]]) chkmax(g[u],dep[r]);
		}
	}
//	cout<<"dfs "<<u<<' '<<d[u]<<' '<<g[u]<<endl;
}

void dfs3(int u){
	for(int p=h[u];p;p=nxt[p]){
		dfs3(v[p]);
		siz[u]+=siz[v[p]];
	}
}

int jump(int x,int d){
	for(int i=19;i>=0;i--) if(d&(1<<i)) x=f[x][i];
	return x;
}

int main(){
	n=readint(); m=readint();
	for(int i=2;i<=n;i++) addedge(readint(),i);
	dep[1]=1; dfs1(1);
	for(int i=1;i<=m;i++){
		x[i]=readint(); y[i]=readint();
		int l=lca(x[i],y[i]);
		if((l==x[i]||l==y[i])&&abs(dep[x[i]]-dep[y[i]])==1) return printf("-1\n"),0;
		if(l==x[i]) vec[y[i]].pb(x[i]);
		else if(l==y[i]) vec[x[i]].pb(y[i]);
	}
	dfs2(1);
	dfs3(1);
	bool fl=0;
	for(int i=1;i<=m;i++){
		int l=lca(x[i],y[i]),l1=jump(dep[x[i]]>dep[y[i]]?x[i]:y[i],abs(dep[x[i]]-dep[y[i]])-1);
		if(l==x[i]) fl|=siz[y[i]]+siz[x[i]]-siz[l1]==siz[1];
		else if(l==y[i]) fl|=siz[x[i]]+siz[y[i]]-siz[l1]==siz[1];
		else fl|=siz[x[i]]+siz[y[i]]==siz[1];
	}
	printf("%d\n",siz[1]+fl);
	return 0;
}