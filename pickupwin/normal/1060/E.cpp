#include <iostream>

using namespace std;

const int MAXN=200111;

int N;

struct Vert{
	int FE;
	int Fa;
	int Dep;
	int Cnt[2];
	long long Val;
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
	++V[at].Cnt[V[at].Dep&1];
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==V[at].Fa)	continue;
		V[to].Fa=at;
		V[to].Dep=V[at].Dep+1;
		DFS(to);
		V[at].Cnt[0]+=V[to].Cnt[0];
		V[at].Cnt[1]+=V[to].Cnt[1];
	}
}

void Deal(int at){
	int d=V[at].Dep&1;
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==V[at].Fa)	continue;
		V[to].Val=V[at].Val;
		V[to].Val+=(V[1].Cnt[d]-V[to].Cnt[d]);
		V[to].Val-=V[to].Cnt[!d];
		Deal(to);
	}
}

int main(){
	
	cin >> N;
	for(int i=1, a, b;i<N;++i){
		cin >> a >> b;
		addE(a, b);addE(b, a);
	}
	
	V[1].Dep=1;
	DFS(1);
	
	for(int i=1;i<=N;++i)
		V[1].Val+=V[i].Dep>>1;
	
	Deal(1);
	
	long long Ans=0LL;
	for(int i=1;i<=N;++i)
	    Ans+=V[i].Val;
	
	/*
	for(int i=1;i<=N;++i){
		cout << V[i].Val << endl;
	}
	*/
	
	cout << (Ans>>1) << endl;
	
	return 0;
}