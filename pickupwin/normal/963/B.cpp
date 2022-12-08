#include <iostream>

using namespace std;

const int MAXN=200111;

int N;

struct Vert{
	int FE, DP;
} V[MAXN];

struct Edge{
	int x, y, next;
} E[MAXN<<1];

int Ecnt=0;

void addE(int a, int b){
	++Ecnt;
	E[Ecnt].x=a;E[Ecnt].y=b;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
}

void DFS1(int at, int f=0){
	int c=0;
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==f)	continue;
		DFS1(to, at);
		if(V[to].DP==0)	++c;
	}
	V[at].DP=c&1;
}

void DFS2(int at, int f=0){
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==f)	continue;
		DFS2(to, at);
	}
	if(V[at].DP==1)	cout << at << endl;
}

void DFS3(int at, int f=0){
	if(V[at].DP==0)	cout << at << endl;
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==f)	continue;
		DFS3(to, at);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1, p;i<=N;++i){
		cin >> p;if(p==0)	continue;
		addE(i, p);addE(p, i);
	}
	
	DFS1(1);
	if(V[1].DP==0){
		cout << "YES" << endl;
		DFS2(1);
		DFS3(1);
	}
	else	cout << "NO" << endl;
	
	return 0;
}

/*
5
0 1 2 3 4

*/

/*
11
0 1 1 2 1 3 2 3 2 1 3

*/