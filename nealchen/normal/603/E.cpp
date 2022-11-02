#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-48, (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-48)<=9; a=a*10+c);
	return b?-a:a;
}
int (*rd)()=read<int>;
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;

//struct Node {
//	int w;
//	bool rev;
//	Node *ch[2], *fa, *choice;
//	bool check() {return fa&&(this==fa->ch[0]||this==fa->ch[1]);}
//	bool type() {return this==fa->ch[1];}
//	void pushup() {
//		choice=this;
//		if(ch[0]&&ch[0]->choice->w>choice->w) choice=ch[0]->choice;
//		if(ch[1]&&ch[1]->choice->w>choice->w) choice=ch[1]->choice;
//	}
//	void pushdown() {
//		if(rev) {
//			if(ch[0]) ch[0]->rev^=1;
//			if(ch[1]) ch[1]->rev^=1;
//			std::swap(ch[0], ch[1]);
//			rev=false;
//		}
//	}
//	void pda() {
//		if(check()) fa->pda();
//		pushdown();
//	}
//	void rotate() {
//		int d=type();
//		Node *f=fa;
//		fa=f->fa;
//		if(f->check()) f->fa->ch[f->type()]=this;
//		if(f->ch[d]=ch[!d]) ch[!d]->fa=f;
//		f->fa=this, ch[!d]=f;
//		f->pushup();
//	}
//	void splay() {
//		for(pda(); check(); rotate()) if(fa->check()) (type()==fa->type()?fa:this)->rotate();
//		pushup();
//	}
//};
//Node *access(Node *p) {
//	Node *i;
//	for(i=NULL; p; i=p, p=p->fa) {
//		p->splay();
//		p->ch[1]=i;
//		p->pushup();
//	}
//	return i;
//}
//void make_root(Node *p) {
//	access(p);
//	p->splay();
//	p->rev^=1;
//}
//Node *root(Node *p) {
//	access(p);
//	p->splay();
//	while(p->ch[0]) p=p->ch[0];
//	p->splay();
//	return p;
//}
//void link(Node *p, Node *q) {
//	make_root(p);
//	make_root(q);
//	q->fa=p;
//}
//void cut(Node *p, Node *q) {
//	make_root(p);
//	access(q);
//	q->splay();
//	p->fa=q->ch[0]=NULL;
//	q->pushup();
//}

struct Edge {
	int u, v, w;
	bool operator<(const Edge &o) const {return w<o.w;}
};
struct History {
	int *pos, val;
};
const int N=1e5+1, M=3e5+1;
int n, m, tot, ans[M], fa[N], size[N], real[M], id[M];
Edge e[M];
History stack[M*2], *top=stack;
std::pair<int, int> sorted[M];
void record(int &v) {*top++=(History){&v, v};}
void rollback() {--top, *(top->pos)=top->val;}
int find(int u) {return fa[u]==u?u:find(fa[u]);}
bool merge(int u, int v) {
	u=find(u), v=find(v);
	if(u==v) return 0;
	if(size[u]<size[v]) std::swap(u, v);
	record(fa[v]);
	record(size[u]);
	size[fa[v]=u]+=size[v];
	return size[u]%2==0&&size[v]%2==1;
}
void dfs(int l, int r, int d, int u) {
	int mid=(l+r)/2, &A=ans[mid];
	History *save1, *save2;
	save1=top;
	record(tot);
	for(int i=l; i<=mid; ++i)
		if(e[i].w<d) {
			if(merge(e[i].u, e[i].v)) tot-=2;
		} else if(e[i].w<=u) {
			record(id[e[i].w]);
			id[e[i].w]=i;
		}
	save2=top;
	record(tot);
	for(A=d; A<u; ++A) if(id[A]!=-1&&merge(e[id[A]].u, e[id[A]].v)&&(tot-=2)==0) break;
	while(save2!=top) rollback();
	if(mid<r) dfs(mid+1, r, d, A);
	while(save1!=top) rollback();
	record(tot);
	for(int i=d; i<A; ++i) if(id[i]!=-1&&merge(e[id[i]].u, e[id[i]].v)) tot-=2;
	if(l<mid) dfs(l, mid-1, A, u);
	while(save1!=top) rollback();
}
int main() {
	n=rd(), m=rd();
	for(int i=0; i<m; ++i) {
		e[i]={rd(), rd(), rd()};
		sorted[i]={e[i].w, i};
	}
	std::sort(sorted, sorted+m);
	for(int i=0; i<m; ++i) real[e[sorted[i].second].w=i]=sorted[i].first;
	real[m]=-1;
	tot=n;
	for(int i=1; i<=n; ++i) fa[i]=i, size[i]=1;
	memset(id, -1, m*sizeof(int));
	dfs(0, m-1, 0, m);
	for(int i=0; i<m; ++i) printf("%d\n", real[ans[i]]);
	return 0;
}