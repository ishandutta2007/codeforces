#include<bits/stdc++.h>

using namespace std;

#define N 1200000
#define ls (x<<1)
#define rs (x<<1|1)

int n,m,a[N],stk[N],dfn[N],head[N],tot,clk,fst[N],lst[N],seg[N<<2],fa[N],mx[N],dep[N];
struct edge{int v,nxt;}e[N];
multiset<int> se;

int gfa(int x){return x==fa[x]?x:fa[x]=gfa(fa[x]);}

void add(int x,int y){
	e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;
}

void dfs(int u){
	dfn[u]=++clk; fst[u]=lst[u]=clk;
	for (int i=head[u],v;i;i=e[i].nxt){
		dep[v=e[i].v]=dep[u]+1; dfs(v); lst[u]=clk;
	}
}

void mdf(int x,int l,int r,int t,int k){
	if (l==r){seg[x]=k; return;}
	int mid=(l+r)>>1;
	if (t<=mid) mdf(ls,l,mid,t,k);
	else mdf(rs,mid+1,r,t,k);
	seg[x]=max(seg[ls],seg[rs]);
}

int qry(int x,int l,int r,int L,int R){
	if (l>=L&&r<=R) return seg[x];
	int mid=(l+r)>>1,tmp=0;
	if (L<=mid) tmp=max(tmp,qry(ls,l,mid,L,R));
	if (R>mid) tmp=max(tmp,qry(rs,mid+1,r,L,R));
	return tmp;
}

void del(int x){
	se.erase(se.find(mx[x]));
}

void renew(int x){
	se.insert(mx[x]=qry(1,1,n+1,fst[x],lst[x])-dep[x]+1);
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	int tp=0;
	for (int i=1;i<=n;++i){
		for (;tp&&a[i]>a[stk[tp]];--tp) add(i,stk[tp]);
		stk[++tp]=i;
	}
	for (;tp;--tp) add(0,stk[tp]);
	dfs(0);
	for (int i=1;i<=n;++i) fa[i]=i;
	for (int i=1,j=1;i<=n-m+1;++i){
		if (i-1){
			mdf(1,1,n+1,dfn[i-1],0);
			del(gfa(i-1)); renew(gfa(i-1));
		}
		for (;j<i+m;++j){
			mdf(1,1,n+1,dfn[j],dep[j]);
			for (int k=head[j];k;k=e[k].nxt){
				del(e[k].v);
				fa[e[k].v]=j;
			}
			renew(j);
		}
		printf("%d ",*(--se.end()));
	}
	puts("");
	
	return 0;
}