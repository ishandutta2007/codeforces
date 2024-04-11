#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=200111;
const int MAXM=200111;
const int INF=1034567890;
const int Lim=1000000000;

int N, M;
int Ans[MAXM];

int F[MAXN];

int Find(int a){
	if(F[F[a]]!=F[a])	F[a]=Find(F[a]);
	return F[a];
}

struct Data{
	int x, y, l;
	int id;
	bool u;
} D[MAXM];

bool cmpl(Data A, Data B){
	return A.l<B.l;
}

struct Vert{
	int FE;
	int Dep;
	int Pre[19], Max[19];
	int Val;
} V[MAXN];

struct Edge{
	int x, y, l, next;
} E[MAXN<<1];

int Ecnt;

void addE(int a, int b, int c){
	++Ecnt;
	E[Ecnt].x=a;E[Ecnt].y=b;E[Ecnt].l=c;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
}

void DFS(int at){
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==V[at].Pre[0])	continue;
		V[to].Pre[0]=at;
		V[to].Dep=V[at].Dep+1;
		V[to].Max[0]=E[k].l;
		DFS(to);
	}
}	

int LCA(int a, int b){
	if(V[a].Dep<V[b].Dep)	swap(a, b);
	for(int i=18;i>=0;--i)
		if(V[V[a].Pre[i]].Dep>=V[b].Dep)
			a=V[a].Pre[i];
	if(a!=b){
		for(int i=18;i>=0;--i)
			if(V[a].Pre[i]!=V[b].Pre[i]){
				a=V[a].Pre[i];
				b=V[b].Pre[i];
			}
		a=V[a].Pre[0];
		b=V[b].Pre[0];
	}
	return (a+b)>>1;
}

int Ask_Max(int a, int b){
	if(V[a].Dep<V[b].Dep)	swap(a, b);
	int ret=0;
	for(int i=18;i>=0;--i)
		if(V[V[a].Pre[i]].Dep>=V[b].Dep){
			ret=max(ret, V[a].Max[i]);
			a=V[a].Pre[i];
		}
	if(a!=b){
		for(int i=18;i>=0;--i)
			if(V[a].Pre[i]!=V[b].Pre[i]){
				ret=max(ret, V[a].Max[i]);
				a=V[a].Pre[i];
				ret=max(ret, V[b].Max[i]);
				b=V[b].Pre[i];
			}
		ret=max(ret, V[a].Max[0]);
		a=V[a].Pre[0];
		ret=max(ret, V[b].Max[0]);
		b=V[b].Pre[0];
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	for(int i=1;i<=M;++i){
		cin >> D[i].x >> D[i].y >> D[i].l;
		D[i].id=i;
	}
	
	sort(D+1, D+M+1, cmpl);
	
	for(int i=1;i<=N;++i)	F[i]=i;
	
	for(int i=1, a, b;i<=M;++i){
		a=D[i].x;b=D[i].y;
		a=Find(a);b=Find(b);
		if(a!=b){
			addE(D[i].x, D[i].y, D[i].l);
			addE(D[i].y, D[i].x, D[i].l);
			F[a]=b;
			D[i].u=true;
		}
	}
	
	V[1].Dep=1;
	DFS(1);
	
	for(int i=1;i<19;++i)
		for(int j=1;j<=N;++j){
			V[j].Pre[i]=V[V[j].Pre[i-1]].Pre[i-1];
			V[j].Max[i]=max(V[V[j].Pre[i-1]].Max[i-1], V[j].Max[i-1]);
		}
	
	for(int i=1;i<=N;++i)	F[i]=i;
	
	for(int i=1;i<=N;++i)	V[i].Val=INF;
	
	for(int i=1, a, b, c;i<=M;++i){
		if(D[i].u)	continue;
		a=D[i].x;b=D[i].y;
		if(V[a].Dep<V[b].Dep)	swap(a, b);
		Ans[D[i].id]=Ask_Max(a, b)-1;
		c=LCA(a, b);
		for(int j=Find(a);V[j].Dep>V[c].Dep;j=Find(j)){
			V[j].Val=D[i].l;
			F[j]=V[j].Pre[0];
		}
		for(int j=Find(b);V[j].Dep>V[c].Dep;j=Find(j)){
			V[j].Val=D[i].l;
			F[j]=V[j].Pre[0];
		}
	}
	
	for(int i=1, a, b;i<=M;++i){
		if(!D[i].u)	continue;
		a=D[i].x;b=D[i].y;
		if(V[a].Dep<V[b].Dep)	swap(a, b);
		Ans[D[i].id]=V[a].Val-1;
	}
	
	for(int i=1;i<=M;++i){
		if(Ans[i]>Lim)	cout << "-1 ";
		else	cout << Ans[i] << " ";
	}
	cout << "\n";
	
	return 0;
}