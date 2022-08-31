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

int n,q,tot,nowd,da,db;
int v[200005],nxt[200005],c[200005],h[100005];

struct pst{
	int ntot;
	int lch[6000000],rch[6000000],val[6000000],vs[100005];
	void build(int id,int l,int r){
		val[id]=1<<30;
		if(l==r) return;
		int mid=(l+r)/2;
		build(lch[id]=++ntot,l,mid);
		build(rch[id]=++ntot,mid+1,r);
	}
	int change(int id,int l,int r,int x,int c){
		int rt=++ntot,mid=(l+r)/2;
		lch[rt]=lch[id],rch[rt]=rch[id],val[rt]=min(val[id],c);
		if(l==r) return rt;
		if(x<=mid) lch[rt]=change(lch[id],l,mid,x,c);
		else rch[rt]=change(rch[id],mid+1,r,x,c);
		return rt;
	}
	int query(int id,int l,int r,int ql,int qr){
		if(l==ql&&r==qr) return val[id];
		int mid=(l+r)/2;
		if(qr<=mid) return query(lch[id],l,mid,ql,qr);
		else if(ql>mid) return query(rch[id],mid+1,r,ql,qr);
		else return min(query(lch[id],l,mid,ql,mid),query(rch[id],mid+1,r,mid+1,qr));
	}
}pt[2];

struct node{
	int kd,rt,ncnt;
	int dfn[100005],rnk[100005],siz[100005],f[100005][17],dep[100005],d[100005],cf[100005],lazy[300000],dr[100005];
	pii val[300000];
	bool leaf[100005];
	void dfs(int u,int fa){
		dfn[u]=++ncnt,rnk[ncnt]=u,siz[u]=1;
		if(!nxt[h[u]]&&fa!=-1) leaf[u]=1;
		for(int i=1;i<=16;i++) f[u][i]=f[f[u][i-1]][i-1];
		for(int p=h[u];p;p=nxt[p]){
			if(v[p]==fa) continue;
			dep[v[p]]=dep[u]+c[p];
			f[v[p]][0]=u,cf[v[p]]=c[p];
			dfs(v[p],u);
			siz[u]+=siz[v[p]];
		}
	}
	void build(int id,int l,int r){
		lazy[id]=0;
		if(l==r) return (void)(val[id]=mp(leaf[rnk[l]]?dep[rnk[l]]:-1,rnk[l]));
		int mid=(l+r)/2;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
		val[id]=max(val[id<<1],val[id<<1|1]);
	}
	void pushdown(int id){
		if(lazy[id]){
			val[id<<1].fi-=lazy[id],lazy[id<<1]+=lazy[id];
			val[id<<1|1].fi-=lazy[id],lazy[id<<1|1]+=lazy[id];
			lazy[id]=0;
		}
	}
	void change(int id,int l,int r,int ql,int qr,int c){
		if(l==ql&&r==qr) return (void)(lazy[id]+=c,val[id].fi-=c);
		pushdown(id);
		int mid=(l+r)/2;
		if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
		else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
		else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
		val[id]=max(val[id<<1],val[id<<1|1]);
	}
	int query(int id,int l,int r,int ql,int qr){
		if(l==ql&&r==qr) return val[id].fi;
		int mid=(l+r)/2;
		if(qr<=mid) return query(id<<1,l,mid,ql,qr);
		else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
		else return max(query(id<<1,l,mid,ql,mid),query(id<<1|1,mid+1,r,mid+1,qr));
	}
	int clist(int x,int id){
		int ret=0;
		while(x!=rt&&!d[x]){
			d[x]=id;
			change(1,1,n,dfn[x],dfn[x]+siz[x]-1,cf[x]);
			ret+=cf[x];
			x=f[x][0];
		}
		return ret;
	}
	void init(int x,int k){
		rt=x,kd=k;
		dfs(rt,-1);
		build(1,1,n);
		pt[kd].build(pt[kd].vs[0]=0,1,n);
		for(int i=1;i<=n;i++){
			pii tmp=val[1];
			if(tmp.fi<0) break;
			dr[i]=dr[i-1]+clist(tmp.se,i);
			pt[kd].vs[i]=pt[kd].change(pt[kd].vs[i-1],1,n,dfn[tmp.se],dep[tmp.se]);
			change(1,1,n,dfn[tmp.se],dfn[tmp.se],dep[tmp.se]);
		}
		for(int i=1;i<=n;i++) if(!dr[i]) dr[i]=dr[i-1];
		build(1,1,n);
	}
	int jump(int x,int y){
		for(int i=16;i>=0;i--) if(d[f[x][i]]>y) x=f[x][i];
		return f[x][0];
	}
	int solve(int x,int y){
		y--;
		if(d[x]<=y) return dr[y];
		int tmp=jump(x,y-1),mxd=query(1,1,n,dfn[x],dfn[x]+siz[x]-1);
		int now=dr[y-1]+mxd-dep[tmp];
		tmp=jump(x,y);
		chkmax(now,dr[y]+mxd-pt[kd].query(pt[kd].vs[y],1,n,dfn[tmp],dfn[tmp]+siz[tmp]-1));
		return now;
	}
}T1,T2;

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=z; nxt[tot]=h[y]; h[y]=tot;
}

pii getroot(int u,int fa){
	pii mx1=mp(0,u),mx2=mp(0,0);
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		pii tmp=getroot(v[p],u); tmp.fi+=c[p];
		if(tmp>mx1) mx2=mx1,mx1=tmp;
		else if(tmp>mx2) mx2=tmp;
	}
	if(chkmax(nowd,mx1.fi+mx2.fi)) da=mx1.se,db=mx2.se;
	return mx1;
}

int main(){
	n=readint(); q=readint();
	int x,y,z;
	for(int i=1;i<n;i++){
		x=readint(); y=readint(); z=readint();
		addedge(x,y,z);
	}
	getroot(1,-1);
	T1.init(da,0);
	T2.init(db,1);
	int lastans=0;
	while(q--){
		x=(readint()+lastans-1)%n+1; y=(readint()+lastans-1)%n+1;
		lastans=max(T1.solve(x,min(n,y<<1)),T2.solve(x,min(n,y<<1)));
		printf("%d\n",lastans);
	}
	return 0;
}