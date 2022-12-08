#include <iostream>

using namespace std;

const int MAXN=1000111;

int N, K;
int Cnt;

struct Vert{
	int FE;
	bool Co;
	int Dep;
	int Pre[21];
} V[MAXN];

struct Edge{
	int x, y, next;
} E[MAXN<<1];

int Ecnt;

void addE(int a, int b){
	++Ecnt;
	E[Ecnt].x=a;E[Ecnt].y=b;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
}

void DFS(int at){
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==V[at].Pre[0])	continue;
		V[to].Pre[0]=at;
		V[to].Dep=V[at].Dep+1;
		DFS(to);
	}
}

int Jump(int at){
	for(int i=20;i>=0;--i)
		if(!V[V[at].Pre[i]].Co)
			at=V[at].Pre[i];
	return V[at].Pre[0];
}

void Color(int at){
	for(int i=at;!V[i].Co;i=V[i].Pre[0])
		{V[i].Co=true;++Cnt;}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	V[0].Co=true;
	
	cin >> N >> K;
	for(int i=1, a, b;i<N;++i){
		cin >> a >> b;
		addE(a, b);addE(b, a);
	}
	
	V[N].Dep=1;
	DFS(N);
	
	for(int j=1;j<21;++j)
		for(int i=1;i<=N;++i)
			V[i].Pre[j]=V[V[i].Pre[j-1]].Pre[j-1];
	
	V[N].Co=true;++Cnt;
	for(int i=N-1, j;i>=1;--i){
		if(V[i].Co)	continue;
		j=Jump(i);
		if(Cnt+V[i].Dep-V[j].Dep<=N-K)	Color(i);
	}
	
	for(int i=1;i<=N;++i)	if(!V[i].Co)	cout << i << " ";
	cout << "\n";
	
	return 0;
}