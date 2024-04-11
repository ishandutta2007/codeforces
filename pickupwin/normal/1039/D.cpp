#include <cstdio>
#include <algorithm>
#include <cassert>

using std::swap;

const int MAXN=100011;

int N;

struct Vert{
	int FE;
	int Fa, Len;
	int Max, Sec;
} V[MAXN];

struct Edge{
	int y, next;
} E[MAXN<<1];

int Ecnt;

void addE(int a, int b){
	++Ecnt;
	E[Ecnt].y=b;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
}

int Dfn[MAXN], DFN;

void DFS(int at){
	Dfn[++DFN]=at;
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==V[at].Fa)	continue;
		V[to].Fa=at;
		DFS(to);
	}
}

int Calc(int K){
	
	int ret=0;
	
	for(int i=1;i<=N;++i)	{V[i].Max=V[i].Sec=1;}
	for(int i=N, at, f, l;i>=1;--i){
		at=Dfn[i];f=V[at].Fa;
		if(V[at].Max+V[at].Sec>K){
			++ret;
			V[at].Len=0;
		}
		else	V[at].Len=V[at].Max;
		l=V[at].Len+1;
		if(l>V[f].Sec){
			if(l>V[f].Max){
				swap(l, V[f].Max);
			}
			V[f].Sec=l;
		}
	}
	
	return ret;
}

int Ans[MAXN];

void Deal(int ql, int qr, int vl, int vr){
	if(ql>qr)	return;
	if(vl==vr){
		int vm=(vl+vr)>>1;
		for(int q=ql;q<=qr;++q)	Ans[q]=vm;
		return;
	}
	int qm=(ql+qr)>>1, vm=Calc(qm);
	Ans[qm]=vm;
	Deal(ql, qm-1, vm, vr);
	Deal(qm+1, qr, vl, vm);
}

int main(){
	
	scanf("%d", &N);
	
	for(int i=1, a, b;i<N;++i){
		scanf("%d%d", &a, &b);
		addE(a, b);addE(b, a);
	}
	
	DFS(1);
	assert(DFN==N);
	
	Deal(1, N, 0, N);
	
	for(int i=1;i<=N;++i)	printf("%d\n", Ans[i]);
	
	return 0;
}