#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
struct Path {
	int s, t, lca, dep;
	bool operator<(const Path &o) const {
		return dep>o.dep||dep==o.dep&&lca<o.lca;
	}
};
struct Segment {
	int sum;
	Segment *lc, *rc;
};
const int N=1.5e5+1;
int n, k, pa[N], dep[N], siz[N], prefer[N], dfsn, real[N], dfn[N], dfr[N], top[N], bit[N], v[2*N], stack[N];
Path q[N];
long long ans;
Segment nil[1], pool[N*64], *mem, *root[N];
std::vector<int> e[N], pathid[N];
int rd() {
	int a=0;
	unsigned char c;
	while((c=getchar()-48)>9);
	while(a=a*10+c, (c=getchar()-48)<=9);
	return a;
}
void dfs1(int u) {
	int mx=0;
	siz[u]=1;
	for(int v: e[u]) {
		if(v!=pa[u]) {
			pa[v]=u;
			dep[v]=dep[u]+1;
			dfs1(v);
			siz[u]+=siz[v];
			if(siz[v]>mx) {
				mx=siz[v];
				prefer[u]=v;
			}
		}
	}
}
void dfs2(int u) {
	real[dfn[u]=++dfsn]=u;
	if(prefer[u]) {
		top[prefer[u]]=top[u];
		dfs2(prefer[u]);
	}
	for(int v: e[u]) {
		if(v!=pa[u] && v!=prefer[u]) {
			top[v]=v;
			dfs2(v);
		}
	}
	dfr[u]=dfsn;
}
int lca(int u, int v) {
	while(top[u]!=top[v]) {
		if(dep[top[u]]<dep[top[v]])
			v=pa[top[v]];
		else
			u=pa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
int climb(int u, int target) {
	while(dep[top[u]]>target) u=pa[top[u]];
	return real[dfn[u]-dep[u]+target];
}
int bit_partial_sum(int x) {
	int ans=0;
	for(; x; x&=x-1) ans+=bit[x];
	return ans;
}
void bit_increase(int x, int v) {
	for(; x<=n; x+=x&-x) bit[x]+=v;
}
void down_increase(int u, int target) {
	if(dep[u]>=target) {
		u=climb(u, target);
		bit_increase(dfn[u], 1);
		bit_increase(dfr[u]+1, -1);
	}
}
Segment *merge(Segment *u, Segment *v) {
	if(u==nil) return v;
	if(v==nil) return u;
	u->sum+=v->sum;
	u->lc=merge(u->lc, v->lc);
	u->rc=merge(u->rc, v->rc);
	return u;
}
void insert(Segment *&o, int l, int r, int pos) {
	if(o==nil) {
		o=mem++;
		o->sum=0;
		o->lc=o->rc=nil;
	}
	++o->sum;
	if(l!=r) {
		int mid=(l+r)/2;
		if(pos<=mid)
			insert(o->lc, l, mid, pos);
		else
			insert(o->rc, mid+1, r, pos);
	}
}
void query(Segment *o, int l, int r, int ql, int qr) {
	if(ql>r||l>qr||o->sum==0) return;
	if(ql<=l&&r<=qr) {
		ans+=o->sum;
	} else {
		int mid=(l+r)/2;
		query(o->lc, l, mid, ql, qr);
		query(o->rc, mid+1, r, ql, qr);
	}
}
void qry(int s, int t) {
	int ls=dep[s]-dep[v[0]];
	if(ls+dep[t]-dep[v[0]]>=k) {
		int u = ls>=k ? v[0] : climb(t, dep[v[0]]+k-ls);
		query(root[s], 1, n, dfn[u], dfr[u]);
	}
}
void join(int u, int p) {
	if(pathid[u].size()>pathid[p].size()) {
		std::swap(pathid[u], pathid[p]);
		std::swap(root[u], root[p]);
	}
	for(int i: pathid[u]) {
		qry(p, q[i].t);
		pathid[p].push_back(i);
	}
	pathid[u].clear();
	root[p]=merge(root[u], root[p]);
}
int main() {
	int m;
	nil->lc=nil->rc=nil;
	n=rd();
	m=rd();
	k=rd();
	for(int i=1; i<n; ++i) {
		int u=rd(), v=rd();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1);
	top[1]=1;
	dfs2(1);
	for(int i=0; i<m; ++i) {
		q[i].s=rd();
		q[i].t=rd();
		if(dfn[q[i].s]>dfn[q[i].t])
			std::swap(q[i].s, q[i].t);
		q[i].lca=lca(q[i].s, q[i].t);
		q[i].dep=dep[q[i].lca];
	}
	std::sort(q, q+m);
	for(int l=0, r=0; l<m; l=r) {
		int vn=0, top=0;
		while(r<m&&q[l].lca==q[r].lca) ++r;
		for(int i=l; i<r; ++i) ans+=bit_partial_sum(dfn[q[i].t]);
		for(int i=l; i<r; ++i) down_increase(q[i].t, q[i].dep+k);
		for(int i=l; i<r; ++i) ans+=bit_partial_sum(dfn[q[i].s]);
		for(int i=l; i<r; ++i) down_increase(q[i].s, q[i].dep+k);
		for(int i=l; i<r; ++i) {
			v[vn++]=dfn[q[i].s];
			v[vn++]=dfn[q[i].t];
		}
		std::sort(v, v+vn);
		vn=std::unique(v, v+vn)-v;
		for(int i=vn; --i; ) v[vn++]=dfn[lca(real[v[i-1]], real[v[i]])];
		std::sort(v, v+vn);
		vn=std::unique(v, v+vn)-v;
		for(int i=0; i<vn; ++i) {
			v[i]=real[v[i]];
			pathid[v[i]].clear();
			root[v[i]]=nil;
		}
		mem=pool;
		for(int i=l; i<r; ++i) {
			qry(q[i].s, q[i].t);
			pathid[q[i].s].push_back(i);
			insert(root[q[i].s], 1, n, dfn[q[i].t]);
		}
		for(int i=0; i<vn; ++i) {
			while(top&&dfn[v[i]]>dfr[stack[top-1]]) {
				if(top>1) join(stack[top-1], stack[top-2]);
				--top;
			}
			stack[top++]=v[i];
		}
		while(top>1) {
			join(stack[top-1], stack[top-2]);
			--top;
		}
	}
	printf("%lld\n", ans);
	return 0;
}