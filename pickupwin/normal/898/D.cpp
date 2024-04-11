#include <iostream>
#include <cassert>
using namespace std;
const int MAXN=211111, MAXT=1111111;
int N, M, K, T=0;
int Num[MAXN], Cnt[MAXT], Sum[MAXT];
int ANS=0, D;
int main(){
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> K;
	for(int i=0;i<MAXT;++i)	Cnt[i]=0, Sum[i]=0;
	for(int i=1;i<=N;++i){
		cin >> Num[i];
		T=max(T, Num[i]);
		++Cnt[Num[i]];
	}
	for(int r=1, l;r<=T;++r){
		l=max(0, r-M);
		Sum[r]=Sum[r-1]+Cnt[r];
		if(Sum[r]-Sum[l]>=K){
			D=Sum[r]-Sum[l]-K+1;
			ANS+=D;
			Cnt[r]-=D;
			assert(Cnt[r]>=0);
			Sum[r]-=D;
		}
	}
	cout << ANS << endl;
	return 0;
}