#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN=100111;
const int MAXM=100111;

int N, M;

struct Node{
	int s, r;
} T[MAXN];

bool cmpr(Node A, Node B){
	return A.r>B.r;
}

struct Group{
	int id, s;
} G[MAXM];

bool cmps(Group A, Group B){
	return A.s>B.s;
}

int R[MAXM];

vector<int> Mem[MAXM];

int main(){
	
	cin >> N >> M;
	
	for(int i=1;i<=M;++i)	G[i].id=i;
	
	for(int i=1;i<=N;++i){
		cin >> T[i].s >> T[i].r;
		++G[T[i].s].s;
	}
	
	sort(G+1, G+M+1, cmps);
	
	for(int i=1;i<=M;++i)	R[G[i].id]=i;
	
	sort(T+1, T+N+1, cmpr);
	
	for(int i=1;i<=N;++i){
		Mem[R[T[i].s]].push_back(T[i].r);
	}
	
	for(int i=1;i<=M;++i){
		for(int j=1, s=Mem[i].size();j<s;++j){
			Mem[i][j]+=Mem[i][j-1];
		}
	}
	
	int Ans=0, Temp;
	for(int i=N;i>=1;--i){
		Temp=0;
		for(int j=1;j<=M;++j){
			if(Mem[j].size()<(unsigned int)(i))	break;
			Temp+=max(0, Mem[j][i-1]);
		}
		Ans=max(Ans, Temp);
	}
	
	cout << Ans << endl;
	
	return 0;
}