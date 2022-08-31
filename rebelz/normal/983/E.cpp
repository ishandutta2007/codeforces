#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int lch,rch,val;
}t[10000005];

int n,m,q,tot,cnt,ncnt;
int siz[200005],dfn[200005],v[200005],nxt[200005],h[200005],f[200005][20],up[200005][20],dep[200005],son[200005],top[200005],tag[600005],vs[200005],rnk[200005];
vector<int> k[200005];

void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}

void dfs1(int u){
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		dep[v[p]]=dep[u]+1;
		dfs1(v[p]);
		if(siz[v[p]]>siz[son[u]]) son[u]=v[p];
		siz[u]+=siz[v[p]];
	}
}

void dfs2(int u){
	dfn[u]=++cnt,rnk[cnt]=u;
	if(son[u]){
		top[son[u]]=top[u];
		dfs2(son[u]);
	}
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==f[u][0]||v[p]==son[u]) continue;
		top[v[p]]=v[p];
		dfs2(v[p]);
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

void update(int id,int l,int r,int ql,int qr,int c){
	if(ql>qr) return;
	if(l==ql&&r==qr){
		if(!tag[id]||dep[c]<dep[tag[id]]) tag[id]=c;
		return;
	}
	int mid=(l+r)/2;
	if(qr<=mid) update(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) update(id<<1|1,mid+1,r,ql,qr,c);
	else update(id<<1,l,mid,ql,mid,c),update(id<<1|1,mid+1,r,mid+1,qr,c);
}

void calc(int id,int l,int r,int nm){
	if(tag[id]&&dep[tag[id]]<dep[nm]) nm=tag[id];
	if(l==r) return (void)(up[rnk[l]][0]=nm);
	int mid=(l+r)/2;
	calc(id<<1,l,mid,nm);
	calc(id<<1|1,mid+1,r,nm);
}

void clist(int x,int y){
	int l=lca(x,y);
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		update(1,1,n,dfn[top[x]],dfn[x],l);
		x=f[top[x]][0];
	}
	if(dfn[x]>dfn[y]) swap(x,y);
	update(1,1,n,dfn[x]+1,dfn[y],l);
}

void build(int id,int l,int r){
	if(l==r) return;
	int mid=(l+r)/2;
	build(t[id].lch=++ncnt,l,mid);
	build(t[id].rch=++ncnt,mid+1,r);
}

int change(int id,int l,int r,int x){
	int rt=++ncnt,mid=(l+r)/2;
	t[rt]=t[id]; t[rt].val++;
	if(l==r) return rt;
	if(x<=mid) t[rt].lch=change(t[rt].lch,l,mid,x);
	else t[rt].rch=change(t[rt].rch,mid+1,r,x);
	return rt;
}

int query(int id1,int id2,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return t[id2].val-t[id1].val;
	int mid=(l+r)/2;
	if(qr<=mid) return query(t[id1].lch,t[id2].lch,l,mid,ql,qr);
	else if(ql>mid) return query(t[id1].rch,t[id2].rch,mid+1,r,ql,qr);
	else return query(t[id1].lch,t[id2].lch,l,mid,ql,mid)+query(t[id1].rch,t[id2].rch,mid+1,r,mid+1,qr);
}

int jump(int x,int y){
	for(int i=19;i>=0;i--) if((1<<i)&y) x=up[x][i];
	return x;
}

int solve(int x,int y){
	int l=lca(x,y),d1=0,d2=0,kx=x,ky=y;
	for(int i=19;i>=0;i--) if(dep[up[x][i]]>=dep[l]) x=up[x][i],d1+=1<<i;
	for(int i=19;i>=0;i--) if(dep[up[y][i]]>=dep[l]) y=up[y][i],d2+=1<<i;
	if(x!=l&&up[x][0]==0) return -1;
	if(y!=l&&up[y][0]==0) return -1;
	if(x!=l) d1++;
	if(y!=l) d2++;
	if(!d1||!d2) return d1+d2;
	int tx=jump(kx,d1-1),ty=jump(ky,d2-1);
	return d1+d2-(query(vs[dfn[tx]-1],vs[dfn[tx]+siz[tx]-1],1,n,dfn[ty],dfn[ty]+siz[ty]-1)>0);
}

int main(){
	n=readint();
	for(int i=2;i<=n;i++) addedge(f[i][0]=readint(),i);
	for(int j=1;j<=19;j++) for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
	dep[1]=1; dfs1(1);
	top[1]=1; dfs2(1);
	m=readint();
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		clist(x,y);
		k[dfn[x]].push_back(dfn[y]);
		k[dfn[y]].push_back(dfn[x]);
	}
	dep[0]=1<<30;
	calc(1,1,n,0);
	dep[0]=0;
	for(int j=1;j<=19;j++) for(int i=1;i<=n;i++) up[i][j]=up[up[i][j-1]][j-1];
	build(vs[0]=0,1,n);
	for(int i=1;i<=n;i++){
		vs[i]=vs[i-1];
		for(int j=0;j<k[i].size();j++) vs[i]=change(vs[i],1,n,k[i][j]);
	}
	q=readint();
	while(q--){
		x=readint(); y=readint();
		printf("%d\n",solve(x,y));
	}
	return 0;
}