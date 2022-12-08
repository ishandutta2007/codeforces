#include <iostream>

using namespace std;

const int MAXN=1000111;

int N=4, A=2, B=4, Len=2, M;

struct Vert{
	int Dep;
	int Pre[21];
} V[MAXN];

void Link(int a, int b){
	V[b].Pre[0]=a;
	V[b].Dep=V[a].Dep+1;
	for(int i=1;i<21;++i)	V[b].Pre[i]=V[V[b].Pre[i-1]].Pre[i-1];
}

int LCA(int a, int b){
	if(V[a].Dep<V[b].Dep)	swap(a, b);
	for(int i=20;i>=0;--i)
		if(V[V[a].Pre[i]].Dep>=V[b].Dep)
			a=V[a].Pre[i];
	if(a!=b){
		for(int i=20;i>=0;--i){
			if(V[a].Pre[i]!=V[b].Pre[i]){
				a=V[a].Pre[i];
				b=V[b].Pre[i];
			}
		}
		a=V[a].Pre[0];
		b=V[b].Pre[0];
	}
	return (a+b)>>1;
}

int Dis(int a, int b){
	int c=LCA(a, b);
	return V[a].Dep+V[b].Dep-(V[c].Dep<<1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	V[1].Dep=1;
	Link(1, 2);Link(1, 3);Link(1, 4);
	
	cin >> M;
	for(int p, da, db;M--;){
		cin >> p;
		Link(p, N+1);Link(p, N+2);
		da=Dis(A, p);
		db=Dis(B, p);
		if(da>db){
			if(da>=Len){
				B=N+1;
				Len=Dis(A, B);
			}
		}
		else{
			if(db>=Len){
				A=N+1;
				Len=Dis(A, B);
			}
		}
		//cout << A << " " << B << " ";
		cout << Len << "\n";
		N+=2;
	}
	
	
	return 0;
}