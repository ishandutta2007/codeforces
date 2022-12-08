#include <iostream>

using namespace std;

const int MAXN=3011;
const int MAXM=3011;
const int MAXQ=400111;

int N, M, Qcnt;
int Ans[MAXQ];

struct Vert{
	int FE, FQ;
	int Pre[15];
} V[MAXN];

struct Edge{
	int y, next;
} E[MAXM];

int Ecnt;

void addE(int a, int b){
	++Ecnt;
	E[Ecnt].y=b;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
}

struct Query{
	int x, next;
	int k, id;
} Q[MAXQ];

void addQ(int a, int b, int c, int i){
	Q[i].x=b;Q[i].next=V[a].FQ;V[a].FQ=i;Q[i].k=c-1;Q[i].id=i;
}

void DFS(int at, int r){
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==r)	continue;
		if(V[to].Pre[0]==0 || V[to].Pre[0]>at){
			V[to].Pre[0]=at;
			DFS(to, r);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M >> Qcnt;
	for(int i=1, a, b;i<=M;++i){
		cin >> a >> b;
		addE(b, a);
	}
	for(int i=1, a, b, c;i<=Qcnt;++i){
		cin >> a >> b >> c;
		addQ(b, a, c, i);
	}
	for(int i=1;i<=N;++i){
		if(V[i].FQ<=0)	continue;
		for(int k=0;k<15;++k)
			for(int j=1;j<=N;++j)
				V[j].Pre[k]=0;
		DFS(i, i);
		for(int k=1;k<15;++k)
			for(int j=1;j<=N;++j)
				V[j].Pre[k]=V[V[j].Pre[k-1]].Pre[k-1];
		for(int k=V[i].FQ, p;k>0;k=Q[k].next){
			p=Q[k].x;
			if(V[p].Pre[14] || V[p].Pre[0]==0){
				Ans[Q[k].id]=-1;
			}
			else{
				for(int d=0;d<15;++d){
					if((Q[k].k>>d)&1)	p=V[p].Pre[d];
				}
				Ans[Q[k].id]=(p>0)?p:(-1);
			}
		}
	}
	
	for(int i=1;i<=Qcnt;++i)
		cout << Ans[i] << endl;
	
	return 0;
}