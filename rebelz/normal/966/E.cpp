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

int n,q,tot,ncnt;
int v[100005],nxt[100005],h[100005],dfn[100005],siz[100005],son[100005],f[100005],top[100005],val[100005];

void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}

namespace ds{
	int m,blo,cnt1,cnt2;
	int a[100005],tag[100005],lf[405],rg[405],bl[100005],rk[100005];
	pii b[100005],tmp1[100005],tmp2[100005];
	bool vis[100005];
	void init(){
		blo=sqrt(n);
		for(int i=1;i<=n;i+=blo) lf[++m]=i,rg[m]=min(n,i+blo-1);
		for(int i=1;i<=m;i++) for(int j=lf[i];j<=rg[i];j++) bl[j]=i;
		for(int i=1;i<=n;i++) b[i]=mp(a[i],i);
		for(int i=1;i<=m;i++) sort(b+lf[i],b+rg[i]+1);
		for(int i=1;i<=n;i++) rk[b[i].se]=i;
	}
	void add(int l,int r,int c){
		int lb=bl[l],rb=bl[r];
		if(lb==rb){
			for(int i=l;i<=r;i++){
				a[i]+=c;
				vis[rk[i]]=1;
			}
			cnt1=cnt2=0;
			for(int i=lf[lb];i<=rg[lb];i++){
				if(!vis[i]) tmp1[++cnt1]=b[i];
				else tmp2[++cnt2]=b[i];
			}
			for(int i=1;i<=cnt2;i++) tmp2[i].fi+=c;
			int p1=1,p2=1,p=lf[lb];
			while(p1<=cnt1&&p2<=cnt2){
				if(tmp1[p1]<=tmp2[p2]) b[p]=tmp1[p1],rk[tmp1[p1].se]=p,p++,p1++;
				else b[p]=tmp2[p2],rk[tmp2[p2].se]=p,p++,p2++;
			}
			while(p1<=cnt1) b[p]=tmp1[p1],rk[tmp1[p1].se]=p,p++,p1++;
			while(p2<=cnt2) b[p]=tmp2[p2],rk[tmp2[p2].se]=p,p++,p2++;
			for(int i=lf[lb];i<=rg[lb];i++) vis[i]=0;
		}
		else{
			for(int i=lb+1;i<=rb-1;i++) tag[i]+=c;
			add(l,rg[lb],c);
			add(lf[rb],r,c);
		}
	}
	int query(){
		int ans=0;
		for(int i=1;i<=m;i++){
			int pl=lower_bound(b+lf[i],b+rg[i]+1,mp(-tag[i],0))-b;
			ans+=pl-lf[i];
		}
		return ans;
	}
}

void dfs1(int u){
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		dfs1(v[p]);
		siz[u]+=siz[v[p]];
		if(siz[v[p]]>siz[son[u]]) son[u]=v[p];
	}
}

void dfs2(int u){
	dfn[u]=++ncnt;
	if(son[u]) top[son[u]]=top[u],dfs2(son[u]);
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==son[u]) continue;
		top[v[p]]=v[p];
		dfs2(v[p]);
	}
}

int main(){
	n=readint(); q=readint();
	for(int i=2;i<=n;i++) addedge(f[i]=readint(),i);
	for(int i=1;i<=n;i++) val[i]=readint();
	dfs1(1);
	top[1]=1; dfs2(1);
	for(int i=1;i<=n;i++) ds::a[dfn[i]]=val[i];
	ds::init();
	int x;
	while(q--){
		x=readint();
		if(x>0){
			ds::add(dfn[x],dfn[x],n);
			x=f[x];
			while(x){
				ds::add(dfn[top[x]],dfn[x],-1);
				x=f[top[x]];
			}
		}
		else{
			x*=-1;
			ds::add(dfn[x],dfn[x],-n);
			x=f[x];
			while(x){
				ds::add(dfn[top[x]],dfn[x],1);
				x=f[top[x]];
			}
		}
		printf("%d ",ds::query());
	}
	printf("\n");
	return 0;
}