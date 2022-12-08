#include <iostream>

using namespace std;

const int MAXN=100111;
const int MAXM=100111;

int N, M;
int F[MAXN];

int Find(int a){
	return F[a]==a?a:F[a]=Find(F[a]);
}

struct Vert{
	int FE;
	int Dep;
	int Cnt;
	int Dps;
	int Dfn, Low;
	bool Vis;
} V[MAXN];

struct Edge{
	int x, y, next, neg;
	bool u, odd;
	int Bel;
} E[MAXM<<1];

int Ecnt;

void addE(int a, int b){
	++Ecnt;
	E[Ecnt].x=a;E[Ecnt].y=b;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;E[Ecnt].neg=Ecnt+1;
	++Ecnt;
	E[Ecnt].y=a;E[Ecnt].x=b;E[Ecnt].next=V[b].FE;V[b].FE=Ecnt;E[Ecnt].neg=Ecnt-1;
}

int DFN;

void DFS(int at){
	V[at].Dps=DFN;
	V[at].Vis=true;
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(V[to].Vis)	continue;
		E[k].u=true;E[E[k].neg].u=true;
		V[to].Dep=V[at].Dep+1;
		DFS(to);
	}
}

int St[MAXM<<1], Top;
int Bcnt;
bool Odd[MAXM<<1];

void PBC(int at, int e=0){
	++DFN;
	V[at].Low=V[at].Dfn=DFN;
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		if(k==E[e].neg)	continue;
		to=E[k].y;
		//St[++Top]=k;
		if(V[to].Dfn){
			if(V[to].Dfn<V[at].Dfn)	St[++Top]=k;
			V[at].Low=min(V[at].Low, V[to].Dfn);
		}
		else{
			St[++Top]=k;
			PBC(to, k);
			V[at].Low=min(V[at].Low, V[to].Low);
		}
	}
	if(V[at].Low>=V[E[e].x].Dfn){
		++Bcnt;
		while(Top>1 && St[Top]!=e){
			E[St[Top]].Bel=Bcnt;
			--Top;
		}
		E[St[Top]].Bel=Bcnt;
		--Top;
	}
}

void Push(int at){
	V[at].Vis=true;
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(V[to].Vis)	continue;
		V[to].Cnt=V[at].Cnt+E[k].odd;
		Push(to);
		if(!E[k].odd)	F[to]=at;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	for(int i=1, a, b;i<=M;++i){
		cin >> a >> b;
		addE(a, b);
	}
	
	for(int i=1;i<=N;++i)	if(!V[i].Vis)	{++DFN;DFS(i);}
	
	for(int i=1, a, b;i<=Ecnt;++i){
		if(E[i].u)	continue;
		a=E[i].x;b=E[i].y;
		if(V[a].Dep<V[b].Dep)	swap(a, b);
		if((V[a].Dep-V[b].Dep)&1)	continue;
		E[i].odd=true;
	}
	
	for(int i=1;i<=N;++i)	if(!V[i].Dfn)	{Top=0;PBC(i);}
	
	for(int i=1;i<=Ecnt;++i)
		if(E[i].Bel && E[i].odd)	Odd[E[i].Bel]=true;
	
	for(int i=1;i<=Ecnt;++i)
		if(Odd[E[i].Bel])	E[i].odd=true;
	
	for(int i=1;i<=Ecnt;++i)	if(E[E[i].neg].odd)	E[i].odd=true;
	
	for(int i=1;i<=N;++i)	V[i].Vis=false;
	
	for(int i=1;i<=N;++i)	F[i]=i;
	
	for(int i=1;i<=N;++i)	if(!V[i].Vis)	Push(i);
	
	int Qcnt;
	
	cin >> Qcnt;
	for(int i=1, a, b;i<=Qcnt;++i){
		cin >> a >> b;
		if(V[a].Dps!=V[b].Dps)	puts("No");
		else{
			if(V[a].Dep<V[b].Dep)	swap(a, b);
			if((V[a].Dep-V[b].Dep)&1)	puts("Yes");
			//else if(V[a].Cnt-V[b].Cnt>0)	puts("Yes");
			else if(Find(a)!=Find(b))	puts("Yes");
			else	puts("No");
		}
	}
		
	return 0;
}