#include <iostream>

using namespace std;

const int MAXN=20011;
const int MAXM=10011;
const int MAXV=MAXN*16+MAXN+MAXM;
const int MAXE=MAXV*16;
const int INF=1034567890;

int N, M;
int Ans;
int Scnt, Pcnt;
int S[MAXN], P[MAXM];

namespace Map{
	
	struct Vert{
		int FE;
		int Bfn, Lev;
		bool isS;
	} V[MAXV];
	
	int Vcnt;
	int Sour, Sink;
	int Man[MAXM], Side[MAXN];
	
	struct Edge{
		int x, y, f, next, neg;
	} E[MAXE<<1];
	
	int Ecnt;
	
	void addE(int a, int b, int c=INF){
		++Ecnt;
		E[Ecnt].x=a;E[Ecnt].y=b;E[Ecnt].f=c;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;E[Ecnt].neg=Ecnt+1;
		++Ecnt;
		E[Ecnt].x=b;E[Ecnt].y=a;E[Ecnt].f=0;E[Ecnt].next=V[b].FE;V[b].FE=Ecnt;E[Ecnt].neg=Ecnt-1;
	}
	
	int Q[MAXV], Head, Tail, BFN;
	
	bool BFS(int at=Sour){
		Head=1;Tail=1;++BFN;
		V[at].Lev=1;
		Q[Tail++]=at;
		V[at].Bfn=BFN;
		while(Head<Tail){
			at=Q[Head++];
			for(int k=V[at].FE, to;k>0;k=E[k].next){
				if(E[k].f<=0)	continue;
				to=E[k].y;
				if(V[to].Bfn==BFN)	continue;
				V[to].Lev=V[at].Lev+1;
				Q[Tail++]=to;
				V[to].Bfn=BFN;
			}
		}
		return V[Sink].Bfn==BFN;
	}
	
	int DFS(int at=Sour, int inc=INF){
		if(at==Sink || inc<=0)	return inc;
		int ret=0, out;
		for(int k=V[at].FE, to;k>0;k=E[k].next){
			if(E[k].f<=0)	continue;
			to=E[k].y;
			if(V[to].Lev!=V[at].Lev+1)	continue;
			out=DFS(to, min(inc, E[k].f));
			ret+=out;inc-=out;
			E[k].f-=out;E[E[k].neg].f+=out;
		}
		if(inc>0)	V[at].Lev=-1;
		return ret;
	}
	
	int DINIC(){
		int ret=0;
		while(BFS()){
			ret+=DFS();
		}
		return ret;
	}
	
	void Search(int at=Sour){
		V[at].isS=true;
		for(int k=V[at].FE, to;k>0;k=E[k].next){
			if(E[k].f<=0)	continue;
			to=E[k].y;
			if(V[to].isS)	continue;
			Search(to);
		}
	}
	
}

namespace Tree{
	
	struct Vert{
		int FE;
		int Dep;
		int Pre[16], Pos[16];
	} V[MAXN];
	
	struct Edge{
		int x, y, next;
		int id;
	} E[MAXN<<1];
	
	int Ecnt;
	
	void addE(int a, int b, int id){
		++Ecnt;
		E[Ecnt].x=a;E[Ecnt].y=b;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
		E[Ecnt].id=id;
	}
	
	void DFS(int at){
		for(int k=V[at].FE, to;k>0;k=E[k].next){
			to=E[k].y;
			if(to==V[at].Pre[0])	continue;
			V[to].Pre[0]=at;
			V[to].Pos[0]=++Map::Vcnt;
			Map::addE(V[to].Pos[0], Map::Side[E[k].id]);
			V[to].Dep=V[at].Dep+1;
			DFS(to);
		}
	}
	
	void Deal(int a, int b, int m){
		if(V[a].Dep<V[b].Dep)	swap(a, b);
		for(int i=15;i>=0;--i)
			if(V[V[a].Pre[i]].Dep>=V[b].Dep){
				Map::addE(Map::Man[m], V[a].Pos[i]);
				a=V[a].Pre[i];
			}
		if(a!=b){
			for(int i=15;i>=0;--i){
				if(V[a].Pre[i]!=V[b].Pre[i]){
					Map::addE(Map::Man[m], V[a].Pos[i]);
					a=V[a].Pre[i];
					Map::addE(Map::Man[m], V[b].Pos[i]);
					b=V[b].Pre[i];
				}
			}
			Map::addE(Map::Man[m], V[a].Pos[0]);
			a=V[a].Pre[0];
			Map::addE(Map::Man[m], V[b].Pos[0]);
			b=V[b].Pre[0];
		}
	}
	
};

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	
	{
		using namespace Map;
		for(int i=1;i<N;++i)	Side[i]=++Vcnt;
		for(int i=1;i<=M;++i)	Man[i]=++Vcnt;
		Sour=++Vcnt;Sink=++Vcnt;
		
		for(int i=1;i<=M;++i)	addE(Sour, Man[i], 1);
		for(int i=1;i<N;++i)	addE(Side[i], Sink, 1);
	}
	
	{
		using namespace Tree;
	
		for(int i=1, a, b;i<N;++i){
			cin >> a >> b;
			addE(a, b, i);
			addE(b, a, i);
		}
		
		V[1].Dep=1;
		DFS(1);
		
		for(int j=1;j<16;++j){
			for(int i=1;i<=N;++i){
				V[i].Pre[j]=V[V[i].Pre[j-1]].Pre[j-1];
				V[i].Pos[j]=++Map::Vcnt;
				Map::addE(V[i].Pos[j], V[i].Pos[j-1]);
				Map::addE(V[i].Pos[j], V[V[i].Pre[j-1]].Pos[j-1]);
			}
		}
		
		for(int i=1, a, b;i<=M;++i){
			cin >> a >> b;
			Deal(a, b, i);
		}
		
	}
	
	{
		using namespace Map;
		
		Ans=DINIC();
		Search();
		
		for(int i=1;i<=M;++i)	if(!V[Man[i]].isS)	P[++Pcnt]=i;
		for(int i=1;i<N;++i)	if(V[Side[i]].isS)	S[++Scnt]=i;
		
		printf("%d\n", Ans);
		printf("%d ", Pcnt);
		for(int i=1;i<=Pcnt;++i)	printf("%d ", P[i]);
		puts("");
		printf("%d ", Scnt);
		for(int i=1;i<=Scnt;++i)	printf("%d ", S[i]);
		puts("");
		
	}
	
	return 0;
}