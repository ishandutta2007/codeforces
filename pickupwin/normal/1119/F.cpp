#include <cstdio>
#include <set>
#include <cstdlib>
#include <cassert>
#include <algorithm>

using std::sort;
using std::min;
using std::max;
using std::set;

const int INF=1034567890;
const int MAXN=250011;

int Rand(){
	return (rand()<<15)+rand();
}

set<int> Set;

int N;
long long Ans[MAXN];

long long Tmp[MAXN];

struct Node{
	Node *s[2];
	int rnd, sz;
	long long val, sum;
	Node(bool i=false);
	void sc(Node *x, int d){s[d]=x;}
	void pup(){
		sz=s[0]->sz+1+s[1]->sz;
		sum=s[0]->sum+val+s[1]->sum;
	}
} *NIL=new Node(true);

Node::Node(bool i){
	if(i)	{s[0]=s[1]=NULL;sz=0;rnd=-1;}
	else	{s[0]=s[1]=NIL;sz=1;rnd=Rand();}
	val=0LL;sum=0LL;
}

Node *Noding(long long v){
	Node *ret=new Node;
	ret->val=v;ret->pup();
	return ret;
}

int Find(Node *at, long long v){
	int ret=0;
	for(int d;at!=NIL;at=at->s[d]){
		d=at->val<v;
		if(d)	ret+=at->s[0]->sz+1;
	}
	return ret;
}

Node *lr, *rr;
void Split(Node *x, int k){
	if(k<=0)	{lr=NIL;rr=x;return;}
	if(k>=x->sz){lr=x;rr=NIL;return;}
	int ls=x->s[0]->sz;
	if(k<=ls)	{Split(x->s[0], k);x->sc(rr, 0);x->pup();rr=x;}
	else	{Split(x->s[1], k-ls-1);x->sc(lr, 1);x->pup();lr=x;}
}

Node *Merge(Node *x, Node *y){
	if(x==NIL)	return y;
	if(y==NIL)	return x;
	if(x->rnd<y->rnd){
		y->sc(Merge(x, y->s[0]), 0);y->pup();
		return y;
	}
	else{
		x->sc(Merge(x->s[1], y), 1);x->pup();
		return x;
	}
}

struct Treap{
	Node *Root;
	Treap(){Root=NIL;}
	void Insert(long long v){
		Split(Root, Find(Root, v));
		Root=Merge(Merge(lr, Noding(v)), rr);
	}
	void Erase(long long v){
		Split(Root, Find(Root, v));
		Node *r1=lr, *r2=rr;
		Split(r2, 1);assert(lr->val==v);
		Root=Merge(r1, rr);
	}
	long long Ask(int k){
		k=max(k, Find(Root, 0LL));
		Split(Root, k);
		long long ret=lr->sum;
		Root=Merge(lr, rr);
		return ret;
	}
};

struct Vert{
	int FE;
	int Deg, Dps;
	int Fa, Fl;
	long long Base, Dis;
	Treap Cost;
} V[MAXN];

int Rk[MAXN];

inline bool cmpd(const int &a, const int &b){
	return V[a].Deg>V[b].Deg;
}

struct Edge{
	int y, l, next;
} E[MAXN<<1];

int Ecnt;

void addE(int a, int b, int c){
	++Ecnt;
	E[Ecnt].y=b;E[Ecnt].l=c;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
}

int Dfn[MAXN], DFN;

void DFS(int at){
	Dfn[++DFN]=at;
	V[at].Dps=DFN;
	for(int k=V[at].FE, to;k;k=E[k].next){
		to=E[k].y;
		if(to==V[at].Fa)	continue;
		V[to].Fa=at;
		V[to].Fl=E[k].l;
		V[at].Cost.Insert(E[k].l);
		DFS(to);
	}
}

int Lim;
int P[MAXN], Pc;
long long Val, Val_;

long long Deal(){
	Pc=0;
	for(set<int>::iterator it=Set.begin();it!=Set.end();++it){
		P[++Pc]=*it;
	}
	long long ret=0LL;
	for(int i=Pc, p, c, f;i>=1;--i){
		p=Dfn[P[i]];
		c=V[p].Deg-Lim;
		Val=V[p].Cost.Ask(c);
		Val_=V[p].Cost.Ask(c-1);
		f=V[p].Fa;
		if(f)	V[f].Cost.Erase(V[p].Dis+V[p].Fl);
		V[p].Base+=Val;
		V[p].Dis=Val_-Val;
		if(f)	V[f].Cost.Insert(V[p].Dis+V[p].Fl);
		V[f].Base+=V[p].Base;
		if(V[f].Deg<=Lim){
			ret+=min(V[p].Base, V[p].Base+V[p].Dis+V[p].Fl);
		}
	}
	for(int i=Pc, p, f;i>=1;--i){
		p=Dfn[P[i]];f=V[p].Fa;
		V[p].Base=V[f].Base=0LL;
	}
	return ret;
}

int main(){
	
	scanf("%d", &N);
	for(int i=1, a, b, c;i<N;++i){
		scanf("%d%d%d", &a, &b, &c);
		addE(a, b, c);addE(b, a, c);
		++V[a].Deg;++V[b].Deg;
		Ans[0]+=c;
	}
	
	for(int i=1;i<=N;++i)	Rk[i]=i;
	sort(Rk+1, Rk+N+1, cmpd);
	
	V[1].Fl=INF;
	DFS(1);
	
	for(int i=N-1, j=1;i>=1;--i){
		Lim=i;
		while(j<=N && V[Rk[j]].Deg>Lim)	{Set.insert(V[Rk[j]].Dps);++j;}
		Ans[i]=Deal();
	}
	
	for(int i=0;i<N;++i)
		printf("%I64d ", Ans[i]);
	puts("");
	
	return 0;
}

/*
12
1 3 1
1 2 1
1 4 1
3 5 1
3 6 1
3 7 100
3 8 100
4 9 1
4 10 1
4 11 100
4 12 100

*/