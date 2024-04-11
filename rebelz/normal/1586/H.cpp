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
	int x,y,z,v;
	bool operator<(const node c)const{return z>c.z;}
}e[200005];

int n,q,cnt,ncnt;
int f1[400005][20],f[400005],a[200005],ch[400005][2],d[400005],mx[400005],mina[400005],maxa[400005],f2[400005][20],md[400005],dfn[200005],rnk[200005],dep[400005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

void dfs1(int u){
	for(int i=1;i<=19;i++) f1[u][i]=f1[f1[u][i-1]][i-1];
	mina[u]=1<<30,maxa[u]=0;
	if(u<=n){
		mina[u]=maxa[u]=dfn[u];
		mx[u]=a[u];
	}
	for(int i=0;i<2;i++){
		int v=ch[u][i];
		if(!v) continue;
		f1[v][0]=u;
		dfs1(v);
		chkmax(mx[u],mx[v]);
	}
	for(int i=0;i<2;i++){
		int v=ch[u][i];
		if(!v) continue;
		if(mx[v]==mx[u]) chkmin(mina[u],mina[v]),chkmax(maxa[u],maxa[v]);
	}
}

void dfs2(int u){
	for(int i=1;i<=19;i++) f2[u][i]=f2[f2[u][i-1]][i-1];
	if(u<=n) dfn[u]=++ncnt,rnk[ncnt]=u;
	for(int i=0;i<2;i++){
		int v=ch[u][i];
		if(!v) continue;
		f2[v][0]=u;
		dep[v]=dep[u]+1;
		dfs2(v);
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--) if(dep[f2[x][i]]>=dep[y]) x=f2[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--) if(f2[x][i]!=f2[y][i]) x=f2[x][i],y=f2[y][i];
	return f2[x][0];
}

int main(){
	n=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<n;i++) e[i].x=readint(),e[i].y=readint(),e[i].z=readint(),e[i].v=readint();
	sort(e+1,e+n,[&](node x,node y){return x.v<y.v;});
	for(int i=1;i<=n;i++) f[i]=i;
	cnt=n;
	for(int i=1;i<n;i++){
		int fx=getf(e[i].x),fy=getf(e[i].y);
		cnt++;
		f[fx]=f[fy]=f[cnt]=cnt;
		ch[cnt][0]=fx,ch[cnt][1]=fy;
		md[cnt]=e[i].v;
	}
	dep[cnt]=1; dfs2(cnt);
	sort(e+1,e+n);
	cnt=n;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<n;i++){
		int fx=getf(e[i].x),fy=getf(e[i].y);
		cnt++;
		f[fx]=f[fy]=f[cnt]=cnt;
		ch[cnt][0]=fx,ch[cnt][1]=fy;
		d[cnt]=e[i].z;
	}
	dfs1(cnt);
	int v,x;
	while(q--){
		v=readint(); x=readint();
		int pl=x;
		for(int i=19;i>=0;i--) if(d[f1[pl][i]]>=v) pl=f1[pl][i];
		printf("%d ",mx[pl]);
		printf("%d\n",max(md[lca(rnk[mina[pl]],x)],md[lca(rnk[maxa[pl]],x)]));
	}
	return 0;
}