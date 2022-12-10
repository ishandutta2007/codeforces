#include <iostream>

using namespace std;

const int MAXN=500011;
const int MAXV=1000011;
const int MAXE=1011111;

int N, a[MAXN], b[MAXN];
int C[MAXN];

struct Vert{
	int FE;
	bool Vis;
	int Deg;
} V[MAXV];

int Vcnt;
int PosX[MAXN], PosY[MAXN];

struct Edge{
	int x, y, next;
	int id;
} E[MAXE];

int Ecnt=0;

void addE(int a, int b, int c){
	++Ecnt;
	E[Ecnt].x=a;E[Ecnt].y=b;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;E[Ecnt].id=c;
	++Ecnt;
	E[Ecnt].x=b;E[Ecnt].y=a;E[Ecnt].next=V[b].FE;V[b].FE=Ecnt;E[Ecnt].id=-c;
}

int ANS[MAXE], Acnt;
bool Used[MAXE];

void DFS(int at){
	V[at].Vis=true;
	for(int k=V[at].FE;k>0;k=V[at].FE){
		while(k>0 && Used[abs(E[k].id)])	k=E[k].next;
		V[at].FE=k;
		if(k>0){
			Used[abs(E[k].id)]=true;
			DFS(E[k].y);
			ANS[++Acnt]=E[k].id;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	for(int i=1;i<=200000;++i){
		PosX[i]=++Vcnt;
		PosY[i]=++Vcnt;
	}
	
	for(int i=1;i<=N;++i){
		cin >> a[i] >> b[i];
		addE(PosX[a[i]], PosY[b[i]], i);
		++V[PosX[a[i]]].Deg;++V[PosY[b[i]]].Deg;
	}
	
	int IdCnt=N;
	
	for(int i=1;i<=Vcnt;++i)
		if(V[i].Deg&1)
			for(int j=i+1;j<=Vcnt;++j)
				if(V[j].Deg&1){
					addE(i, j, ++IdCnt);
					++V[i].Deg;++V[j].Deg;
					break;/**/
				}
	
	for(int i=1;i<=Vcnt;++i){
		if(!V[i].Vis)	DFS(i);
	}
	
	for(int i=1;i<=Acnt;++i){
		if(ANS[i]>=-N && ANS[i]<=N)
			C[abs(ANS[i])]=ANS[i];
	}
	
	for(int i=1;i<=N;++i){
		if(C[i]<0)	cout << "b";
		else	cout << "r";
	}
	cout << endl;
	
	return 0;
}

/*
4
10 10
10 20
20 10
20 20

brrb

*/