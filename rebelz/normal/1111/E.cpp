#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
int n,m,q,k,r,tot,ncnt;
int siz[100005],dep[100005],top[100005],v[200005],nxt[200005],h[100005],dfn[100005],f[100005],son[100005],a[100005],faa[100005];
ll d[100005][305];

namespace seg{
	int sum[300000];
	void change(int id,int l,int r,int p,int c){
		if(l==r) return (void)(sum[id]+=c);
		int mid=(l+r)/2;
		if(p<=mid) change(id<<1,l,mid,p,c);
		else change(id<<1|1,mid+1,r,p,c);
		sum[id]=sum[id<<1]+sum[id<<1|1];
	}
	int query(int id,int l,int r,int ql,int qr){
		if(l==ql&&r==qr) return sum[id];
		int mid=(l+r)/2;
		if(qr<=mid) return query(id<<1,l,mid,ql,qr);
		else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
		else return query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr);
	}
}

int mod(int x){return x>=cys?x-cys:x;}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa){
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dep[v[p]]=dep[u]+1,faa[v[p]]=u;
		dfs1(v[p],u);
		siz[u]+=siz[v[p]];
		if(siz[v[p]]>siz[son[u]]) son[u]=v[p];
	}
}

void dfs2(int u,int fa){
	dfn[u]=++ncnt;
	if(son[u]){
		top[son[u]]=top[u];
		dfs2(son[u],u);
	}
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa||v[p]==son[u]) continue;
		top[v[p]]=v[p];
		dfs2(v[p],u);
	}
}

int qlist(int x,int y){
	int ret=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ret+=seg::query(1,1,n,dfn[top[x]],dfn[x]);
		x=faa[top[x]];
	}
	if(dfn[x]>dfn[y]) swap(x,y);
	return ret+seg::query(1,1,n,dfn[x],dfn[y]);
}

int main(){
	n=readint(); q=readint();
	for(int i=1;i<=n-1;i++) addedge(readint(),readint());
	dep[1]=1; dfs1(1,-1);
	top[1]=1; dfs2(1,-1);
	while(q--){
		k=readint(); m=readint(); r=readint();
		for(int i=1;i<=k;i++) a[i]=readint();
		for(int i=1;i<=k;i++) seg::change(1,1,n,dfn[a[i]],1);
		for(int i=1;i<=k;i++) f[a[i]]=qlist(r,a[i])-1;
		sort(a+1,a+k+1,[&](int x,int y){return f[x]<f[y];});
		d[0][0]=1;
		for(int i=1;i<=k;i++) for(int j=1;j<=m;j++) d[i][j]=mod(d[i-1][j-1]+(j-f[a[i]])*d[i-1][j]%cys);
		for(int i=1;i<=k;i++) seg::change(1,1,n,dfn[a[i]],-1);
		ll ans=0;
		for(int i=1;i<=m;i++) ans=mod(ans+d[k][i]);
		printf("%lld\n",ans);
	}
	return 0;
}