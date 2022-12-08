#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=511;

int N;
int Ans;

struct Node{
	int a, id, c;
} T[MAXN];

bool cmpa(Node A, Node B){
	return A.a>B.a;
}

void addE(int a, int b){
	cout << T[a].id << " " << T[b].id << endl;
	++T[a].c;++T[b].c;
}

int main(){
	
	cin >> N;
	
	for(int i=1;i<=N;++i){
		cin >> T[i].a;
		T[i].id=i;
	}
	
	int SumA=0;
	for(int i=1;i<=N;++i)	SumA+=T[i].a;
	if(SumA<(N<<1)-2){
		cout << "NO" << endl;
		return 0;
	}
	
	sort(T+1, T+N+1, cmpa);
	
	for(int i=1;i<=N;++i)
		if(T[i].a>1)	++Ans;
	++Ans;
	
	Ans=min(Ans, N-1);
	
	cout << "YES " << Ans << endl;
	
	cout << N-1 << endl;
	
	int P=1;
	
	for(int i=1;i<=N;++i){
		if(T[i+1].a>1)	addE(i, i+1);
		else	{P=i;break;}
	}
	
	for(int i=N, j=1;i>=1 && T[i].a==1;--i){
		if(T[P].c<2)	{addE(i, P);continue;}
		while(T[j].a==T[j].c)	++j;
		addE(i, j);
	}
	
	return 0;
}