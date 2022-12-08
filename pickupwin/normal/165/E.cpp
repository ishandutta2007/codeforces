#include <iostream>
using namespace std;
const int MAXN=4194305;
int N, M=4194304;
unsigned int Num[MAXN], F[MAXN], G[MAXN];
int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i=0;i<=M;++i){
		F[i]=0;
		G[i]=0;
	}
	for(int i=1;i<=N;++i){
		cin >> Num[i];
		F[Num[i]]=i;
	}
	for(int i=0;i<=M;++i){
		G[i]=F[i];
		for(int j=0;j<=21;++j){
			if((i>>j)&1){
				G[i]=max(G[i], G[i^(1<<j)]);
			}
		}
	}
	for(unsigned int i=1, k;i<=N;++i){
		k=0;
		for(int j=0;j<=21;++j){
			if((Num[i]>>j)&1)continue;
			k+=(1<<j);
		}
		if(G[k]>0)	cout << Num[G[k]] << " ";
		else	cout << "-1" << " ";
	}
	cout << endl;
	return 0;
}