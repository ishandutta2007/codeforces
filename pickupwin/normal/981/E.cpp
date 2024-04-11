#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MAXN=10011;
const int MAXM=10011;

int N, M;

struct Node{
	int l, r;
	int Vcnt;
	vector<int> V;
	bitset<MAXN> B;
} T[MAXN<<2];

int L, R, op;

void BuildTree(int l, int r, int at){
	T[at].l=l;T[at].r=r;
	if(l<r){
		int m=(l+r)>>1;
		BuildTree(l, m, at<<1);
		BuildTree(m+1, r, (at<<1)|1);
	}
}

void Update(int at){
	if(T[at].l>=L && T[at].r<=R){
		++T[at].Vcnt;
		T[at].V.push_back(op);
		return;
	}
	int m=(T[at].l+T[at].r)>>1;
	if(L<=m)	Update(at<<1);
	if(R>m)	Update((at<<1)|1);
}

void Deal(int at){
	if(T[at].l<T[at].r){
		Deal(at<<1);
		Deal((at<<1)|1);
		T[at].B=T[at<<1].B|T[(at<<1)|1].B;
	}
	T[at].B[0]=1;
	for(int i=T[at].Vcnt-1;i>=0;--i){
		T[at].B|=(T[at].B<<T[at].V[i]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	
	BuildTree(1, N, 1);
	
	for(int i=1;i<=M;++i){
		cin >> L >> R >> op;
		Update(1);
	}
	
	Deal(1);/**/
	
	int Cnt=0;
	for(int i=1;i<=N;++i)
		if(T[1].B[i])	++Cnt;
	cout << Cnt << endl;
	for(int i=1;i<=N;++i)
		if(T[1].B[i])	cout << i << " ";
	cout << endl;
	
	return 0;
}