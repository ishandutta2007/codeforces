#include<bits/stdc++.h>

using namespace std;

#define N 600000

int n,m,p,x,y,a[N],fa[N],c[N][2],sz[N],head[N],tot,rev[N],cov[N],stk[N];
char s[10];
struct edge{int v,nxt;}e[N];
struct fenwick{
	int f[N];
	void add(int x,int k){
		for (;x<=p;x+=x&(-x)) f[x]+=k;
	}
	int qry(int x){
		int ret=0;
		for (;x;x-=x&(-x)) ret+=f[x];
		return ret;
	}
}fenw;

void add(int x,int y){
	e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;
}

#define ls c[x][0]
#define rs c[x][1]

void upd(int x){
	if (x) sz[x]=sz[ls]+sz[rs]+1;
}

void dfs(int u){
	int t=0;
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa[u]){
			fa[v]=u; dfs(v);
			if (a[v]>a[t]) t=v;
		}
	if (a[t]>u){a[u]=a[t]; c[u][1]=t;} else a[u]=u;
	upd(u); fenw.add(a[u],1);
}

bool isrt(int x){return x!=c[fa[x]][0]&&x!=c[fa[x]][1];}

bool dic(int x){return x==c[fa[x]][1];}

void rtt(int x){
	int y=fa[x],dx=dic(x),dy=dic(y);
	fa[c[x][dx^1]]=y; c[y][dx]=c[x][dx^1];
	fa[x]=fa[y]; if (!isrt(y)) c[fa[y]][dy]=x;
	fa[y]=x; c[x][dx^1]=y;
	upd(y); upd(x);
}

void psd(int x){
	if (rev[x]){
		swap(ls,rs);
		rev[ls]^=1; rev[rs]^=1; rev[x]=0;
	}
	if (cov[x]){
		a[ls]=cov[ls]=a[rs]=cov[rs]=cov[x];
		cov[x]=0;
	}
}

void splay(int x){
	int tp; stk[tp=1]=x;
	for (int t=x;!isrt(t);t=fa[t]) stk[++tp]=fa[t];
	for (;tp;--tp) psd(stk[tp]);
	for (int y;!isrt(x);rtt(x))
		if (!isrt(y=fa[x])) rtt(dic(x)^dic(y)?x:y);
}

void acs(int x){
	for (int t=0;x;t=x,x=fa[x]){
		splay(x);
		fenw.add(a[x],-(sz[ls]+1));
		rs=t; upd(x);
	}
}

void mrt(int x){
	acs(x); splay(x);
	swap(ls,rs);
	rev[rs]^=1; a[rs]=cov[rs]=n; fenw.add(n,sz[rs]);
	a[x]=++n; fenw.add(n,1);
	rs=0; upd(x);
}

int rk(int x){
	splay(x);
	return fenw.qry(a[x])-sz[c[x][0]];
}

int main(){
	scanf("%d%d",&n,&m); p=n+m;
	for (int i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(n);
	while (m--){
		scanf("%s",s);
		if (s[0]=='u'){
			scanf("%d",&x); mrt(x);
		}
		if (s[0]=='w'){
			scanf("%d",&x);
			printf("%d\n",rk(x));
		}
		if (s[0]=='c'){
			scanf("%d%d",&x,&y);
			printf("%d\n",rk(x)<rk(y)?x:y);
		}
	}
	
	return 0;
}