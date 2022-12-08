#include <cstdio>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::min;

const int MAXN=500111, MAXM=500111;
const long long LONF=4567891012345678910LL;

int N, M;

long long Ans[MAXM];

struct Query{
	int l, r;
	int id;
};

struct Vert{
	int Fa, Df;
	int Son, Bro;
	int Id, Rd;
	long long Dis;
	vector<Query> Q;
} V[MAXN];

void DFS(int at){
	V[at].Rd=V[at].Id;
	for(int to=V[at].Son;to;to=V[to].Bro){
		V[to].Dis=V[at].Dis+(long long)(V[to].Df);
		DFS(to);
		V[at].Rd=max(V[at].Rd, V[to].Rd);
	}
}

struct Node{
	int l, r;
	long long m, opt;
} T[MAXN<<2];

inline void pup(int at){
	T[at].m=min(T[at<<1].m, T[(at<<1)|1].m);
}

void Build(int at, int l, int r){
	T[at].l=l;T[at].r=r;
	T[at].opt=0LL;
	int m=(l+r)>>1;
	if(l==r){
		T[at].m=(V[m].Son==0)?V[m].Dis:LONF;
		return;
	}
	Build(at<<1, l, m);
	Build((at<<1)|1, m+1, r);
	pup(at);
}

int L, R;
long long op;

inline void opr(int at){
	T[at].m+=op;
}

inline void cop(int at){
	T[at].opt+=op;
}

void pdw(int at){
	if(T[at].opt==0LL)	return;
	long long top=op;op=T[at].opt;
	opr(at<<1);cop(at<<1);
	opr((at<<1)|1);cop((at<<1)|1);
	op=top;T[at].opt=0LL;
}

void Update(int at){
	if(T[at].l>=L && T[at].r<=R){
		opr(at);cop(at);
		return;
	}
	pdw(at);
	int m=(T[at].l+T[at].r)>>1;
	if(L<=m)	Update(at<<1);
	if(R>m)	Update((at<<1)|1);
	pup(at);
}

long long Ask(int at){
	if(T[at].l>=L && T[at].r<=R)
		return T[at].m;
	pdw(at);
	int m=(T[at].l+T[at].r)>>1;
	long long ret=LONF;
	if(L<=m)	ret=min(ret, Ask(at<<1));
	if(R>m)	ret=min(ret, Ask((at<<1)|1));
	return ret;
}

void Deal(int at){
	for(Query Qu:V[at].Q){
		L=Qu.l;R=Qu.r;
		Ans[Qu.id]=Ask(1)+V[at].Dis;
	}
	for(int to=V[at].Son;to;to=V[to].Bro){
		L=V[to].Id;R=V[to].Rd;op=-2LL*V[to].Df;
		Update(1);
		Deal(to);
		L=V[to].Id;R=V[to].Rd;op=2LL*V[to].Df;
		Update(1);
	}
}

int main(){
	
	scanf("%d%d", &N, &M);
	
	for(int i=1;i<=N;++i)	V[i].Id=i;
	
	for(int i=2;i<=N;++i){
		scanf("%d%d", &V[i].Fa, &V[i].Df);
		V[i].Bro=V[V[i].Fa].Son;
		V[V[i].Fa].Son=i;
	}
	
	DFS(1);
	
	for(int i=1, v, l, r;i<=M;++i){
		scanf("%d%d%d", &v, &l, &r);
		V[v].Q.push_back(Query{l, r, i});
	}
	
	Build(1, 1, N);
	
	Deal(1);
	
	for(int i=1;i<=M;++i)	printf("%I64d\n", Ans[i]);
	
	return 0;
}