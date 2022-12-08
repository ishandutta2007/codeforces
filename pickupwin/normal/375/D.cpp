#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=111111;
const int MAXM=111111;

int N, M;
int Ecnt=0;
int Dfn[MAXN], DFN=0;
int ANS[MAXN], Cnt[MAXN];
int L=1, R=0;

struct Vert{
	int FE, Color;
	int Dps, Dpr;
	bool Vis;
} V[MAXN];

struct Edge{
	int x, y, next;
} E[MAXN<<1];

void addE(int a, int b){
	++Ecnt;
	E[Ecnt].x=a;E[Ecnt].y=b;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
}

struct Query{
	int l, r, k, id, ans;
} Q[MAXM];

bool cmpp(Query A, Query B){
	if(A.l/317==B.l/317)	return A.r<B.r;
	return A.l<B.l;
}

bool cmpid(Query A, Query B){
	return A.id<B.id;
}

void DFS(int at){
	++DFN;
	Dfn[DFN]=at;
	V[at].Dps=DFN;
	V[at].Vis=true;
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(!V[to].Vis)	DFS(to);
	}
	V[at].Dpr=DFN;
}

void calc(int s, int t, bool in){
	for(int i=s;i<=t;++i){
		if(in){
			++Cnt[V[Dfn[i]].Color];
			++ANS[Cnt[V[Dfn[i]].Color]];
		}
		else{
			--ANS[Cnt[V[Dfn[i]].Color]];
			--Cnt[V[Dfn[i]].Color];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	
	for(int i=1;i<=N;++i){
		cin >> V[i].Color;
		V[i].FE=-1;V[i].Vis=false;
	}
	
	for(int i=1, a, b;i<N;++i){
		cin >> a >> b;
		addE(a, b);addE(b, a);
	}
	
	DFS(1);
	
	for(int i=1, v, k;i<=M;++i){
		cin >> v >> k;
		Q[i].l=V[v].Dps;Q[i].r=V[v].Dpr;
		Q[i].k=k;Q[i].id=i;
	}
	
	sort(Q+1, Q+M+1, cmpp);
	
	for(int i=1;i<=M;++i){
		calc(min(L, Q[i].l), max(L, Q[i].l)-1, (Q[i].l<L));
		L=Q[i].l;
		calc(min(R, Q[i].r)+1, max(R, Q[i].r), (Q[i].r>R));
		R=Q[i].r;
		Q[i].ans=ANS[Q[i].k];
	}
	
	sort(Q+1, Q+M+1, cmpid);
	
	for(int i=1;i<=M;++i)
		cout << Q[i].ans << endl;
	
	return 0;
}