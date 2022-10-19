#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 300000

const LL mod=1000000007;
LL n,m,x,y,z,fa[N],top[N],dep[N],sz[N],tot,head[N];
struct poly{
	LL f[3];
	poly(){memset(f,0,sizeof f);}
	poly operator + (const poly &g) const{
		poly h; for (LL i=0;i<3;i++) h.f[i]=(f[i]+g.f[i])%mod; return h;
	}
	void operator += (const poly &g){*this=*this+g;}
	poly operator - (const poly &g) const{
		poly h; for (LL i=0;i<3;i++) h.f[i]=(f[i]-g.f[i]+mod)%mod; return h;
	}
	void operator -= (const poly &g){*this=*this-g;}
	LL operator () (LL k) const{
		LL ret=0; k%=mod; for (LL i=2;i>=0;i--) ret=(ret*k+f[i])%mod; return ret;
	}
	poly operator << (LL k) const{
		poly g; k%=mod;
		for (LL i=2;i>=0;i--){
			for (LL j=2;j;j--)
				g.f[j]=(g.f[j]*k+g.f[j-1])%mod;
			g.f[0]=(g.f[0]*k+f[i])%mod;
		}
		return g;
	}
}f[N],g[N];
struct edge{LL v,l,nxt;}e[N];

void add(LL x,LL y,LL z){e[++tot].v=y; e[tot].l=z; e[tot].nxt=head[x]; head[x]=tot;}

void dfs1(LL u){
	f[u].f[2]=1;
	for (LL i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa[u]){
			fa[v]=u; dep[v]=dep[u]+e[i].l; dfs1(v);	sz[u]+=sz[v];
			f[u]+=f[v]<<e[i].l;
		}
	if (!sz[u]) ++sz[u];
}

void dfs2(LL u){
	for (LL i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa[u])
			g[v]=g[u]+(f[u]<<(-dep[u]))-(f[v]<<(-dep[u]+e[i].l));
	if (!top[u]) top[u]=u; LL t=0;
	for (LL i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa[u]&&sz[v]>sz[t]) t=v;
	if (!t) return; top[t]=top[u]; dfs2(t);
	for (LL i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa[u]&&v!=t) dfs2(v);
}

LL lca(LL u,LL v){
	for (;top[u]!=top[v];u=fa[top[u]]) if (dep[top[u]]<dep[top[v]]) swap(u,v);
	return dep[u]<dep[v]?u:v;
}

LL ddd(LL x,LL y){
	LL z=lca(x,y);
	if (z==y) return ((f[x](0)+g[x](dep[x])-g[y](dep[x]))%mod+mod)%mod;
	return f[y](dep[x]+dep[y]-dep[z]*2);
}

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<n;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z); add(y,x,z);
	}
	dfs1(1); dfs2(1);
	scanf("%lld",&m);
	for (LL i=1;i<=m;i++){
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",((ddd(x,y)*2-ddd(x,1))%mod+mod)%mod);
	}
	
	return 0;
}