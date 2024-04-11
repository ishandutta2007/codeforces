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
	int id,x,y,z;
	bool operator<(const node c)const{return z<c.z;}
}e[2000005];
 
int n,m,tot,cnt,num;
int v[2000005],nxt[2000005],c[2000005],h[2000005],dep[2000005],be[2000005],maxd[100005][20],f[100005][20],g[2000005],siz[2000005],son[2000005],dfn[2000005],top[2000005],mina[600000],ans[2000005],fa[2000005],rnk[2000005];
bool fl[2000005];
 
int getf(int x){return fa[x]==x?x:fa[x]=getf(fa[x]);}
 
void addedge(int x,int y,int z,int w){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; g[tot]=w; h[x]=tot;
	v[++tot]=x; c[tot]=z; nxt[tot]=h[y]; g[tot]=w; h[y]=tot;
}
 
void dfs1(int u){
	siz[u]=1;
	for(int i=1;i<=19;i++) f[u][i]=f[f[u][i-1]][i-1],maxd[u][i]=max(maxd[u][i-1],maxd[f[u][i-1]][i-1]);
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==f[u][0]) continue;
		f[v[p]][0]=u,maxd[v[p]][0]=c[p],dep[v[p]]=dep[u]+1,be[v[p]]=g[p];
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
	for(int p=h[u];p;p=nxt[p]) if(v[p]!=f[u][0]&&v[p]!=son[u]) top[v[p]]=v[p],dfs2(v[p]);
}
 
int ask(int x,int y){
	int ret=0;
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--) if(dep[f[x][i]]>=dep[y]) ret=max(ret,maxd[x][i]),x=f[x][i];
	if(x==y) return ret;
	for(int i=19;i>=0;i--) if(f[x][i]!=f[y][i]) ret=max(ret,max(maxd[x][i],maxd[y][i])),x=f[x][i],y=f[y][i];
	return max(ret,max(maxd[x][0],maxd[y][0]));
}
 
void build(int id,int l,int r){
	mina[id]=1<<30;
	if(l==r) return;
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
}
 
void change(int id,int l,int r,int ql,int qr,int c){
	if(l==ql&&r==qr) return (void)(mina[id]=min(mina[id],c));
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
}
 
void clist(int x,int y,int z){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		change(1,1,n,dfn[top[x]],dfn[x],z);
		x=f[top[x]][0];
	}
	if(dfn[x]>dfn[y]) swap(x,y);
	if(x!=y) change(1,1,n,dfn[x]+1,dfn[y],z);
}
 
void calc(int id,int l,int r,int now){
	now=min(now,mina[id]);
	if(l==r) return (void)(ans[be[rnk[l]]]=now);
	int mid=(l+r)/2;
	calc(id<<1,l,mid,now);
	calc(id<<1|1,mid+1,r,now);
}
 
int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) e[i].x=readint(),e[i].y=readint(),e[i].z=readint(),e[i].id=i;
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int fx=getf(e[i].x),fy=getf(e[i].y);
		if(fx==fy) continue;
		fa[fx]=fy,num++;
		addedge(e[i].x,e[i].y,e[i].z,e[i].id);
		fl[i]=true;
		if(num==n-1) break;
	}
	dep[1]=1; dfs1(1);
	top[1]=1; dfs2(1);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		if(!fl[i]){
			ans[e[i].id]=ask(e[i].x,e[i].y);
			clist(e[i].x,e[i].y,e[i].z);
		}
	}
	calc(1,1,n,1<<30);
	for(int i=1;i<=m;i++) 
	{
		if(ans[i] == (1<<30)) ans[i] = 1e9;
		printf("%d\n",ans[i]);
	}
//	printf("\n");
	return 0;
}