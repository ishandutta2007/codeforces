#include <iostream>

using namespace std;

const int MAXN=111111;
const int INF=1034567890;

int N, M;
int Ecnt=0;
int ANS;
int Red[MAXN], Rcnt=1;
int Lim=75;

struct Vert{
	int FE;
	int Dis, Dep;
	int Pre[18];
	bool Vis;
	Vert(){
		FE=-1;
		Dis=INF;
		Dep=0;
		Vis=false;
		for(int i=0;i<18;++i)	Pre[i]=0;
	}
} V[MAXN];

struct Edge{
	int x, y, next;
} E[MAXN<<1];

void addE(int a, int b){
	++Ecnt;
	E[Ecnt].x=a;E[Ecnt].y=b;
	E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
}

void DFS(int at){
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to!=V[at].Pre[0]){
			V[to].Dep=V[at].Dep+1;
			V[to].Pre[0]=at;
			DFS(to);
		}
	}
}

int LCA(int a, int b){
	if(V[a].Dep<V[b].Dep)	swap(a, b);
	for(int i=17;i>=0;--i)
		if(V[V[a].Pre[i]].Dep>=V[b].Dep)
			a=V[a].Pre[i];
	if(a!=b){
		for(int i=17;i>=0;--i)
			if(V[a].Pre[i]!=V[b].Pre[i]){
				a=V[a].Pre[i];
				b=V[b].Pre[i];
			}
		a=V[a].Pre[0];
		b=V[b].Pre[0];
	}
	return (a+b)>>1;
}

int Dist(int a, int b){
	int c=LCA(a, b);
	return V[a].Dep-V[c].Dep+V[b].Dep-V[c].Dep;
}

int Q[MAXN], Head, Tail;

void ClearRed(){
	int at;
	Head=1;Tail=1;
	for(int i=1;i<=N;++i)
		V[i].Vis=false;
	
	for(int i=1;i<=Rcnt;++i){
		V[Red[i]].Dis=0;
		Q[Tail++]=Red[i];
		V[Red[i]].Vis=true;
	}
	
	while(Head<Tail){
		at=Q[Head++];
		for(int k=V[at].FE, to;k>0;k=E[k].next){
			to=E[k].y;
			if(V[to].Vis)	continue;
			if(V[to].Dis>V[at].Dis+1){
				V[to].Dis=V[at].Dis+1;
				Q[Tail++]=to;
				V[to].Vis=true;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	
	for(int i=1, a, b;i<N;++i){
		cin >> a >> b;
		addE(a, b);addE(b, a);
	}
	
	V[1].Dep=1;
	DFS(1);
	
	for(int i=1;i<18;++i)
		for(int j=1;j<=N;++j)
			V[j].Pre[i]=V[V[j].Pre[i-1]].Pre[i-1];
	
	Red[++Rcnt]=1;
	
	for(int t, v;M--;){
		cin >> t >> v;
		if(t==1){
			Red[++Rcnt]=v;
			if(Rcnt>Lim){
				ClearRed();
				Rcnt=0;
			}
		}
		else{
			ANS=INF;
			for(int i=1;i<=Rcnt;++i)
				ANS=min(ANS, Dist(Red[i], v));
			ANS=min(V[v].Dis, ANS);
			cout << ANS << endl;
		}
	}
	
	return 0;
}