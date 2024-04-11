#include <iostream>

using namespace std;

const int MAXN=100011;
const int MAXV=200011;
const int MAXE=400011;

int N;

int Sour, Sink;

struct Vert{
	int FE;
	bool Vis;
} V[MAXV];

int Vcnt=0;

struct Edge{
	int x, y, next;
} E[MAXE];

int Ecnt=0;

void addE(int a, int b){
	++Ecnt;
	E[Ecnt].x=a;E[Ecnt].y=b;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
}

struct Rect{
	int x, y;
	int p;
	Rect(){}
	Rect(int _x, int _y){x=_x;y=_y;}
} R1[MAXN], R2[MAXN];

void DFS(int at){
	V[at].Vis=true;
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(V[to].Vis)	continue;
		DFS(to);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	for(int i=1, a, b;i<=N;++i){
		cin >> a >> b;
		R1[i]=Rect(a, b);
		R2[i]=Rect(b, a);
	}
	
	for(int i=1;i<=N;++i){
		R1[i].p=++Vcnt;
		R2[i].p=++Vcnt;
	}
	
	for(int i=1;i<N;++i){
		if(R1[i].x>=R1[i+1].x)	addE(R1[i].p, R1[i+1].p);
		if(R1[i].x>=R2[i+1].x)	addE(R1[i].p, R2[i+1].p);
		if(R2[i].x>=R1[i+1].x)	addE(R2[i].p, R1[i+1].p);
		if(R2[i].x>=R2[i+1].x)	addE(R2[i].p, R2[i+1].p);
	}
	
	Sour=++Vcnt;Sink=++Vcnt;
	
	addE(Sour, R1[1].p);addE(Sour, R2[1].p);
	addE(R1[N].p, Sink);addE(R2[N].p, Sink);
	
	DFS(Sour);
	
	if(V[Sink].Vis)	cout << "YES" << endl;
	else	cout << "NO" << endl;
	
	return 0;
}