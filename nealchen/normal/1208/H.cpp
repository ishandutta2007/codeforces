#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)

struct Splay {
	int key, siz;
	Splay *fa, *ch[2];
	int type() {return this==fa->ch[1];}
	void pushup() {
		siz=1;
		if(ch[0]) siz+=ch[0]->siz;
		if(ch[1]) siz+=ch[1]->siz;
	}
	void rotate() {
		int d=type();
		Splay *f=fa;
		if(fa=f->fa) fa->ch[f->type()]=this;
		if(f->ch[d]=ch[!d]) f->ch[d]->fa=f;
		ch[!d]=f, f->fa=this;
		f->pushup();
	}
	void splay() {
		for(; fa; rotate()) if(fa->fa) (type()==fa->type()?fa:this)->rotate();
		pushup();
	}
	void insert(Splay *p, int k) {
		int d;
		Splay *i=this;
		for(splay(); i->ch[d=i->key<k]; i=i->ch[d]) ++i->siz;
		*p=(Splay){k, 1};
		i->ch[d]=p, p->fa=i, p->splay();
	}
	Splay *lower_bound(int k) {
		Splay *i=this, *j, *ans;
		for(splay(); i; j=i, i=i->ch[i->key<k]) if(i->key>=k) ans=i;
		j->splay();
		return ans;
	}
	Splay *erase(int k) {
		Splay *i=lower_bound(k), *l, *r;
		i->splay();
		if(l=i->ch[0]) l->fa=NULL;
		r=i->ch[1], r->fa=NULL;
		while(r->ch[0]) r=r->ch[0];
		r->splay();
		if(r->ch[0]=l) l->fa=r;
		r->pushup();
		return i;
	}
	int size() {
		splay();
		return siz-1;
	}
	int order_of_key(int k) {
		Splay *i=lower_bound(k);
		i->splay();
		return i->ch[0]?i->ch[0]->siz:0;
	}
};
struct Data {
	int b, r;
};
struct SegmentTree {
	int offset;
	Data *f;
};

const int N=1e5+5, INF=1e9;
const Data Unit={INF, -INF}, Blue={INF, INF}, Red={-INF, -INF};
int s[N], fa[N], size[N], prefer[N], top[N], dfc, dfo[N], dfn[N];
Splay light[N], node[N];
SegmentTree chain[N];
std::vector<int> ch[N];
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar(), c-'0'>9&c!='-');
	for(a=(b=c=='-')?0:c-'0'; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}

Data merge(Data f1, Data f2) {
	return (Data){std::min(std::max(f1.r, f2.b), f1.b), std::min(std::max(f1.r, f2.r), f1.b)};
}
SegmentTree init(int n) {
	int offset;
	Data *f;
	for(offset=1; offset<n; offset<<=1);
	f=new Data[offset*2];
	for(int i=0; i<offset; ++i) f[offset+i]=Unit;
	return {offset, f};
}
void pushup_all(SegmentTree tr) {
	for(int i=tr.offset; --i; tr.f[i]=merge(tr.f[i<<1], tr.f[i<<1|1]));
}
void modify(SegmentTree tr, int x, Data v) {
	for(tr.f[x|=tr.offset]=v; x>>=1; tr.f[x]=merge(tr.f[x<<1], tr.f[x<<1|1]));
}
Data query_suffix(SegmentTree tr, int x) {
	Data ans;
	for(ans=tr.f[x|=tr.offset]; x; x>>=1) if(~x&1) ans=merge(ans, tr.f[x^1]);
	return ans;
}

//0: red, 1: blue
int col(int u, int k, int pc) {
	return k<=2*(light[u].order_of_key(-k)+pc)-light[u].size()-1;
}
int adjust(int u, int k, int pc) {
	while(col(u, k, pc)) ++k;
	while(!col(u, k-1, pc)) --k;
	return k;
}
Data update(int u, Data x) {
	if(s[u]==0) return Red;
	if(s[u]==1) return Blue;
	return (Data){adjust(u, x.b, 1), adjust(u, x.r, 0)};
}
void dfs_init(int u, int f) {
	size[u]=1;
	ch[u].resize(std::remove(ch[u].begin(), ch[u].end(), fa[u]=f)-ch[u].begin());
	int maxsize=0;
	for(int v: ch[u]) {
		dfs_init(v, u);
		size[u]+=size[v];
		if(cmax(maxsize, size[v])) prefer[u]=v;
	}
}
void dfs_make(int u, int t) {
	top[u]=t;
	dfo[dfn[u]=++dfc]=u;
	if(prefer[u]) dfs_make(prefer[u], t); else chain[t]=init(dfn[u]-dfn[t]+1);
	light[u]=(Splay){INF*2, 1};
	for(int v: ch[u])
		if(v!=prefer[u]) {
			dfs_make(v, v);
			light[u].insert(node+v, -chain[v].f[1].b);
		}
	chain[t].f[chain[t].offset+dfn[u]-dfn[t]]=update(u, {0, 0});
	if(u==t) pushup_all(chain[u]);
}
int main() {
	int (*rd)()=read<int>, n=rd(), k=rd();
	for(int i=1; i<n; ++i) {
		int u=rd(), v=rd();
		ch[u].push_back(v);
		ch[v].push_back(u);
	}
	for(int i=1; i<=n; ++i) s[i]=rd();
	dfs_init(1, 0);
	dfs_make(1, 1);
	for(int q=rd(); q--; ) {
		int op=rd();
		if(op==1) {
			int v=rd();
			printf("%d\n", query_suffix(chain[top[v]], dfn[v]-dfn[top[v]]).b>k);
		}
		if(op==2) {
			int v=rd(), c=rd();
			s[v]=c;
			while(v) {
				int u=top[v], save=-chain[u].f[1].b;
				modify(chain[u], dfn[v]-dfn[u], update(v, chain[u].f[chain[u].offset+dfn[v]-dfn[u]]));
				if(v=fa[u]) light[v].insert(light[v].erase(save), -chain[u].f[1].b);
			}
		}
		if(op==3) k=rd();
	}
	return 0;
}