#include <iostream>
#include <cassert>

using namespace std;

const int MAXN=5011;
const int MAXM=5011;
const int MAXV=MAXN+(MAXM<<2);
const int MAXE=500111;
const int INF=1034567890;

int N, M;

struct Vert{
	int FE;
	int Bfn, Lev;
	int Id;
} V[MAXV];

int Vcnt;

struct Node{
	int l, r;
	int p;
} T[MAXM<<2];

int Pos[MAXM], W[MAXN];
bool Cover[MAXM], isO[MAXN];
int Sour, Sink;

struct Omg{
	int id, o[3];
} O[MAXN];

int Oc;

int Bel[MAXM];

struct Edge{
	int y, f, next;
} E[MAXE<<1];

int Ecnt=1;

void addE(int a, int b, int c){
	++Ecnt;
	E[Ecnt].y=b;E[Ecnt].f=c;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
}

int Flow(int e){
	return E[e^1].f;
}

void Push(int e, int f=1){
	E[e].f-=f;
	E[e^1].f+=f;
}

void BuildTree(int at, int l, int r){
	T[at].l=l;T[at].r=r;T[at].p=++Vcnt;
	int m=(l+r)>>1;
	if(l==r){
		Pos[m]=T[at].p;
		V[T[at].p].Id=m;
		return;
	}
	int s;
	s=at<<1;
	BuildTree(s, l, m);
	addE(T[at].p, T[s].p, INF);
	addE(T[s].p, T[at].p, 0);
	s|=1;
	BuildTree(s, m+1, r);
	addE(T[at].p, T[s].p, INF);
	addE(T[s].p, T[at].p, 0);
}

void Update(int at, int &ql, int &qr, int &p){
	if(T[at].l>=ql && T[at].r<=qr){
		addE(p, T[at].p, 1);
		addE(T[at].p, p, 0);
		return;
	}
	int m=(T[at].l+T[at].r)>>1;
	if(ql<=m)	Update(at<<1, ql, qr, p);
	if(qr>m)	Update((at<<1)|1, ql, qr, p);
}

bool Search(int at, int &p){
	if(V[at].Id){
		Bel[V[at].Id]=p;
		return true;
	}
	for(int k=V[at].FE, to;k;k=E[k].next){
		if(k&1)	continue;;
		to=E[k].y;
		if(Flow(k)){
			assert(Search(to, p));
			Push(k^1);
			return true;
		}
	}
	return false;
}

int Q[MAXV], Head, Tail;
int BFN;

bool BFS(int at=Sour){
	Head=Tail=0;++BFN;
	V[at].Lev=1;
	Q[Tail++]=at;
	V[at].Bfn=BFN;
	while(Head<Tail){
		at=Q[Head++];
		for(int k=V[at].FE, to;k;k=E[k].next){
			if(!E[k].f)	continue;
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
	if(inc<=0 || at==Sink)	return inc;
	int ret=0, out;
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		if(!E[k].f)	continue;
		to=E[k].y;
		if(V[to].Lev!=V[at].Lev+1)	continue;
		out=DFS(to, min(E[k].f, inc));
		ret+=out;inc-=out;
		Push(k, out);
	}
	if(inc>0)	V[at].Lev=-1;
	return ret;
}

int DINIC(){
	int ret=0;
	while(BFS())	ret+=DFS();
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	
	for(int i=1;i<=N;++i)	W[i]=++Vcnt;
	BuildTree(1, 1, M);
	Sour=++Vcnt;Sink=++Vcnt;
	
	for(int i=1, t, k, l, r;i<=N;++i){
		cin >> t;
		if(t==0){
			addE(Sour, W[i], 1);
			addE(W[i], Sour, 0);
			cin >> k;
			for(int c=1, p;c<=k;++c){
				cin >> p;
				addE(W[i], Pos[p], 1);
				addE(Pos[p], W[i], 0);
			}
		}
		if(t==1){
			addE(Sour, W[i], 1);
			addE(W[i], Sour, 0);
			cin >> l >> r;
			Update(1, l, r, W[i]);
		}
		if(t==2){
			addE(W[i], Sink, 1);
			addE(Sink, W[i], 0);
			++Oc;
			O[Oc].id=i;
			isO[i]=true;
			for(int o=0, p;o<3;++o){
				cin >> p;
				O[Oc].o[o]=p;
				Cover[p]=true;
				addE(Pos[p], W[i], 1);
				addE(W[i], Pos[p], 0);
			}
		}
	}
	
	for(int i=1;i<=M;++i)	if(!Cover[i])	{addE(Pos[i], Sink, 1);addE(Sink, Pos[i], 0);}
	
	int Ans=DINIC();
	
	cout << Ans+(Oc<<1) << endl;
	
	for(int i=1, at;i<=N;++i){
		if(isO[i])	continue;
		at=W[i];
		for(int k=V[at].FE, to;k;k=E[k].next){
			if(k&1)	continue;
			to=E[k].y;
			if(Flow(k)){
				assert(Search(to, i));
				Push(k^1);
			}
		}
	}
	
	for(int i=1, p;i<=Oc;++i){p=O[i].id;
		for(int k=0, c=1, t;k<3 && c<=2;++k){t=O[i].o[k];
			if(!Bel[t]){
				++c;
				Bel[t]=p;
			}
		}
	}
	
	for(int i=1;i<=M;++i){
		if(Bel[i]){
			cout << Bel[i] << " " << i << endl;
		}
	}
	
	return 0;
}