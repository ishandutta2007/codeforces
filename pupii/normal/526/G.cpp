#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,fir[100010],dis[200010],nxt[200010],w[200010],id;
void link(int a,int b,int c){nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;}
int tag[400010];
struct qaq{int x,p;}mx[400010];
#define mid ((l+r)>>1)
qaq operator+(const qaq&a,const qaq&b){return a.x>b.x?a:b;}
void pushup(int x){mx[x]=mx[x<<1]+mx[x<<1|1];}
void upd(int x,int d){tag[x]+=d,mx[x].x+=d;}
void pushdown(int x){if(tag[x])upd(x<<1,tag[x]),upd(x<<1|1,tag[x]),tag[x]=0;}
void update(int x,int l,int r,int L,int R,int d){
	if(L<=l&&r<=R)return upd(x,d);
	pushdown(x);
	if(L<=mid)update(x<<1,l,mid,L,R,d);
	if(mid<R)update(x<<1|1,mid+1,r,L,R,d);
	pushup(x);
}
void build(int x,int l,int r,int*d,int*rdfn){
	tag[x]=0;if(l==r){mx[x]={d[rdfn[l]],l};return;}
	build(x<<1,l,mid,d,rdfn),build(x<<1|1,mid+1,r,d,rdfn);
	pushup(x);
}
#undef mid
struct fuck{
	int fa[100010],dfn[100010],rdfn[100010],end[100010],dep[100010],dist[100010],faw[100010];
	int rt,f[100010],g[100010],tm[100010];
	int st[17][100010];
	void dfs(int x){
		rdfn[dfn[x]=++dfn[0]]=x;
		for(int i=fir[x];i;i=nxt[i]){
			if(fa[x]==dis[i])continue;
			fa[dis[i]]=x;
			dep[dis[i]]=dep[x]+1;
			dist[dis[i]]=dist[x]+w[i];
			faw[dis[i]]=w[i];
			dfs(dis[i]);
			g[x]=std::max(g[x],g[dis[i]]+w[i]);
		}
		end[x]=dfn[0];
	}
	//f[x]:x
	//g[x]:xx
	void pre(){
		dfs(rt);build(1,1,n,dist,rdfn);
		tm[rt]=1;
		for(int i=2,x;i<=n;++i){
			f[i]=f[i-1]+mx[1].x;
			x=rdfn[mx[1].p];
			while(!tm[x])
				update(1,1,n,dfn[x],end[x],-faw[x]),tm[x]=i,x=fa[x];
		}
		for(int i=1;i<=n;++i)st[0][i]=fa[i];
		for(int i=1;i<17;++i)
			for(int j=1;j<=n;++j)
				st[i][j]=st[i-1][st[i-1][j]];
	}
	int solve(int x,int y){
		y=std::min(n,y*2);
		if(tm[x]<=y)return f[y];
		else{
			int ret=f[y]+g[x]+dist[x];
			for(int i=16;~i;--i)if(st[i][x]&&tm[st[i][x]]>=y)x=st[i][x];
			x=st[0][x];return ret-std::min(f[y]-f[y-1],g[x])-dist[x];
		}
	}
}A,B;
int dist[100010],D=1;
void dfs(int x,int fa=-1){
	if(dist[x]>dist[D])D=x;
	for(int i=fir[x];i;i=nxt[i]){
		if(fa==dis[i])continue;
		dist[dis[i]]=dist[x]+w[i];
		dfs(dis[i],x);
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();int lans=n,u,v,w,q=gi();
	for(int i=1;i<n;++i)u=gi(),v=gi(),w=gi(),link(u,v,w),link(v,u,w);
	dfs(1);
	dist[A.rt=D]=0,dfs(D);
	B.rt=D;
	A.pre();B.pre();
	while(q--){
		u=(gi()+lans-1)%n+1,v=(gi()+lans-1)%n+1;
		printf("%d\n",lans=std::max(A.solve(u,v),B.solve(u,v)));
	}
	return 0;
}