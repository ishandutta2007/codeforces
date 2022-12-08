#include <iostream>
#include <cassert>
#include <queue>

using namespace std;

const int MAXN=200111;
const int MAXM=300111;
const long long LONF=4567891012345678910LL;

int N, M, S;
int Ans=0;

namespace Tree{
	
	struct Vert{
		int Son, Bro;
		int Dep, Size;
		int Pre[19];
	} V[MAXN];
	
	int Sun;
	
	int LCA(int a, int b){
		if(V[a].Dep<V[b].Dep)	swap(a, b);
		if(b==0)	return a;
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
	
	void Link(int a, int b){
		//cout << "Tree:: " << a << " " << b << endl;
		if(a==0)	a=Sun;
		V[b].Dep=V[a].Dep+1;
		V[b].Bro=V[a].Son;V[a].Son=b;
		V[b].Pre[0]=a;
		for(int i=1;i<19;++i)	V[b].Pre[i]=V[V[b].Pre[i-1]].Pre[i-1];
	}
	
	void DFS(int at){
		V[at].Size=1;
		for(int to=V[at].Son;to>0;to=V[to].Bro){
			DFS(to);
			V[at].Size+=V[to].Size;
		}
		if(at!=S)	Ans=max(Ans, V[at].Size);
	}
	
}

namespace Dag{
	
	struct Vert{
		int FE;
		int Deg;
	} V[MAXN];
	
	struct Edge{
		int x, y, next;
	} E[MAXM];
	
	int Ecnt;
	
	void addE(int a, int b){
		//cout << "Dag:: " << a << " " << b << endl;
		++Ecnt;
		E[Ecnt].x=a;E[Ecnt].y=b;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
		++V[b].Deg;
	}
	
	int Tps[MAXN], TPN;
	int Q[MAXN], Head, Tail;
	
	void TopSort(){
		for(int i=1;i<=N;++i)
			if(V[i].Deg==0)
				Q[Tail++]=i;
		for(int at;Head<Tail;){
			at=Q[Head++];
			Tps[++TPN]=at;
			for(int k=V[at].FE, to;k>0;k=E[k].next){
				to=E[k].y;
				--V[to].Deg;
				if(V[to].Deg==0)
					Q[Tail++]=to;
			}
		}
	}
	
}

namespace Map{
	
	struct Pair{
		int p;
		long long v;
		Pair(){}
		Pair(int _p, long long _v){p=_p;v=_v;}
	};
	
	bool operator < (Pair A, Pair B){
		return A.v>B.v;
	}
	
	struct Vert{
		int FE;
		long long Dis;
	} V[MAXN];

	struct Edge{
		int x, y, l, next;
	} E[MAXM<<1];

	int Ecnt;

	void addE(int a, int b, int c){
		++Ecnt;
		E[Ecnt].x=a;E[Ecnt].y=b;E[Ecnt].l=c;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
	}
	
	priority_queue<Pair> PQ;
	
	void Dij(int at=S){
		for(int i=1;i<=N;++i)	V[i].Dis=LONF;
		V[at].Dis=0LL;
		PQ.push(Pair(at, 0LL));
		for(Pair P;!PQ.empty();){
			P=PQ.top();PQ.pop();
			if(V[P.p].Dis<P.v)	continue;
			at=P.p;
			for(int k=V[at].FE, to;k>0;k=E[k].next){
				to=E[k].y;
				if(V[to].Dis>V[at].Dis+E[k].l){
					V[to].Dis=V[at].Dis+E[k].l;
					PQ.push(Pair(to, V[to].Dis));
				}
			}
		}
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	{
		using namespace Map;
		
		cin >> N >> M >> S;
		for(int i=1, a, b, c;i<=M;++i){
			cin >> a >> b >> c;
			addE(a, b, c);addE(b, a, c);
		}
		
		Dij();
		
		for(int i=1, a, b;i<=Ecnt;++i){
			a=E[i].x;b=E[i].y;
			if(V[a].Dis+E[i].l==V[b].Dis)	Dag::addE(b, a);
		}
		
	}
	
	{
		using namespace Dag;
		
		TopSort();
		
		assert(TPN==N);
		
		Tree::Sun=N+1;
		
		for(int i=TPN, p, f;i>=1;--i){
			p=Tps[i];
			f=0;
			for(int k=V[p].FE, to;k>0;k=E[k].next){
				to=E[k].y;
				f=Tree::LCA(f, to);
			}
			Tree::Link(f, p);
		}
	}
	
	Tree::DFS(S);
	
	cout << Ans << endl;
	
	return 0;
}