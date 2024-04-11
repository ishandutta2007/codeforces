#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot;
int v[400005],nxt[400005],c[400005],h[200005],f[200005][20];
ll dep[200005],d[200005],a[200005];

void addedge(int x,int y,int z){v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;}

void dfs1(int u){
	for(int i=1;i<=19;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int p=h[u];p;p=nxt[p]){
		f[v[p]][0]=u,dep[v[p]]=dep[u]+c[p];
		dfs1(v[p]);
	}
}

void dfs2(int u){
	for(int p=h[u];p;p=nxt[p]){
		dfs2(v[p]);
		d[u]+=d[v[p]];
	}
}

int getpl(int u,ll x){
	int now=u;
	for(int i=19;i>=0;i--) if(dep[u]-dep[f[now][i]]<=x) now=f[now][i];
	return f[now][0];
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	int x,y;
	for(int i=2;i<=n;i++){
		x=readint(); y=readint();
		addedge(x,i,y);
	}
	dfs1(1);
	for(int i=1;i<=n;i++) d[f[i][0]]++,d[getpl(i,a[i])]--;
	dfs2(1);
	for(int i=1;i<=n;i++) printf("%d ",d[i]);
	printf("\n");
	return 0;
}