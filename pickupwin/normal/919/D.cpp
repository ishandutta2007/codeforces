#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN=333333;
const int MAXM=333333;

int N, M;
string input;
int Way[MAXN];

struct Vert{
	int FE, In, F[26], Data;
} V[MAXN];

struct Edge{
	int x, y, next;
} E[MAXM];
int Ecnt=0;
void addE(int a, int b){
	++Ecnt;
	E[Ecnt].x=a;E[Ecnt].y=b;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
	++V[b].In;
}

int Head, Tail;
void Topsort(){
	Head=1;Tail=1;
	for(int i=1;i<=N;++i)	if(V[i].In==0)	Way[Tail++]=i;
	int at;
	while(Head<Tail){
		at=Way[Head++];
		//cout << at << endl;
		for(int k=V[at].FE, to;k>0;k=E[k].next){
			to=E[k].y;
			--V[to].In;
			if(V[to].In==0)	Way[Tail++]=to;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	cin >> input;
	
	for(int i=1;i<=N;++i){
		V[i].FE=-1;V[i].In=0;V[i].Data=input[i-1]-'a';
		for(int j=0;j<26;++j)	V[i].F[j]=0;
	}
	
	for(int i=1, a, b;i<=M;++i){
		cin >> a >> b;
		addE(a, b);
	}
	
	Topsort();
	
	if(Tail!=N+1){
		cout << "-1" << endl;
		return 0;
	}
	
	/*
	for(int i=N;i>=1;--i){
		for(int k=V[i].FE, to;k>0;k=E[k].next){
			to=E[k].y;
			for(int j=0;j<26;++j){
				V[i].F[j]=max(V[i].F[j], V[to].F[j]);
			}
		}
		++V[i].F[V[i].Data];
	}
	*/
	
	for(int i=N, at;i>=1;--i){
		at=Way[i];
		for(int k=V[at].FE, to;k>0;k=E[k].next){
			to=E[k].y;
			for(int j=0;j<26;++j)	V[at].F[j]=max(V[at].F[j], V[to].F[j]);
		}
		++V[at].F[V[at].Data];
	}
	
	int ANS=0;
	for(int i=1;i<=N;++i){
		for(int j=0;j<26;++j){
			ANS=max(ANS, V[i].F[j]);
		}
	}
	
	cout << ANS << endl;
	
	return 0;
}