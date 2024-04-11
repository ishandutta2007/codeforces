#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 220000
#define M (N<<5)

LL n,ans,tot,mn[M],mx[M],sum[M],ls[M],rs[M],go[N][20],dep[N],pre[N],dfn[N],clk,rt[N];
char s[N];

struct sam{
	LL p,np,cnt,fa[N],pos[N],mx[N],rg[N],c[N][30];
	vector<LL> g[N];
	void extend(LL w){
		p=np; np=++cnt; rg[np]=mx[np]=mx[p]+1; pos[rg[np]]=np;
		for (;p&&!c[p][w];p=fa[p]) c[p][w]=np;
		if (!p) fa[np]=1;
		else{
			LL q=c[p][w];
			if (mx[q]==mx[p]+1) fa[np]=q;
			else{
				LL nq=++cnt; mx[nq]=mx[p]+1;
				memcpy(c[nq],c[q],sizeof c[nq]);
				fa[nq]=fa[q]; fa[q]=fa[np]=nq;
				for (;p&&c[p][w]==q;p=fa[p]) c[p][w]=nq;
			}
		}
	}
	void build(char s[]){
		np=cnt=1;
		for (LL i=1;i<=n;++i) extend(s[i]-'a');
		for (LL i=2;i<=cnt;++i) g[fa[i]].push_back(i);
	}
}s1,s2;

LL lca(LL x,LL y){
	for (LL i=18;~i;--i){
		if (dep[go[x][i]]>=dep[y]) x=go[x][i];
		if (dep[go[y][i]]>=dep[x]) y=go[y][i];
	}
	for (LL i=18;~i;--i){
		if (go[x][i]!=go[y][i]){x=go[x][i]; y=go[y][i];}
	}
	return x==y?x:s1.fa[x];
}

void upd(LL x){
	mn[x]=mn[ls[x]]?mn[ls[x]]:mn[rs[x]];
	mx[x]=mx[rs[x]]?mx[rs[x]]:mx[ls[x]];
	sum[x]=sum[ls[x]]+sum[rs[x]]-pre[lca(mx[ls[x]],mn[rs[x]])];
}

void mdf(LL &x,LL l,LL r,LL t,LL k){
	if (!x) x=++tot;
	if (l==r){mn[x]=mx[x]=k; sum[x]=pre[k]; return;}
	LL mid=(l+r)>>1;
	if (t<=mid) mdf(ls[x],l,mid,t,k);
	if (t>mid) mdf(rs[x],mid+1,r,t,k);
	upd(x);
}

void merge(LL &x,LL y){
	if (!x||!y){x=x|y; return;}
	merge(ls[x],ls[y]); merge(rs[x],rs[y]);
	upd(x);
}

void dfs1(LL u){
	dep[u]=dep[s1.fa[u]]+1;
	dfn[u]=++clk;
	pre[u]=pre[s1.fa[u]]+s1.mx[u]-s1.mx[s1.fa[u]];
	for (LL i=1;i<=18;++i) go[u][i]=go[go[u][i-1]][i-1];
	if (!s1.rg[u]) s1.rg[u]=n;
	for (LL v:s1.g[u]){
		go[v][0]=u;
		dfs1(v);
		s1.rg[u]=min(s1.rg[u],s1.rg[v]);
	}
	ans+=(s1.mx[u]-s1.mx[s1.fa[u]])*(1+(s1.rg[u]<n));
}

void dfs2(LL u){
	if (s2.rg[u]&&n-s2.rg[u]-1>0){
		LL x=s1.pos[n-s2.rg[u]-1];
		if (x) mdf(rt[u],1,s1.cnt,dfn[x],x);
	}
	if (!s2.rg[u]) s2.rg[u]=n;
	for (LL v:s2.g[u]){
		dfs2(v);
		s2.rg[u]=min(s2.rg[u],s2.rg[v]);
		merge(rt[u],rt[v]);
	}
	ans+=(sum[rt[u]]+(s2.rg[u]<n))*(s2.mx[u]-s2.mx[s2.fa[u]]);
}

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	s1.build(s);
	reverse(s+1,s+n+1);
	s2.build(s);
	dfs1(1);
	dfs2(1);
	printf("%lld\n",ans+2);
	
	return 0;
}