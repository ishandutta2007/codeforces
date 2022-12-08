#include <iostream>
#include <iomanip>
using namespace std;
const int MAXN=20;
const int MAXM=277777;
int N;
double F[MAXN][MAXM];
double Map[MAXN][MAXN];
//int Queue[MAXM], Head=0, Tail=0;
//bool inQ[MAXM];
int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			cin >> Map[i][j];
	for(int i=0, k;i<N;++i){
		k=(1<<N)-(1<<i)-1;
		F[i][k]=1.0;
	}
	for(int k=(1<<N)-1, cnt;k>=0;--k){
		cnt=0;
		for(int i=0;i<N;++i){
			if((k>>i)&1)	continue;
			++cnt;
		}
		if(cnt<=1)	continue;
		for(int i=0;i<N;++i){
			if((k>>i)&1)	continue;
			F[i][k]=0.0;
			for(int a=0;a<N;++a){
				if((k>>a)&1)	continue;
				for(int b=a+1;b<N;++b){
					if((k>>b)&1)	continue;
					F[i][k]+=(F[i][k|(1<<a)]*Map[b][a]+F[i][k|(1<<b)]*Map[a][b])*2.0/(double)(cnt)/(double)(cnt-1);
				}
			}
		}
	}
	/*
	for(int i=0;i<N;++i)
		for(int j=0;j<(1<<N);++j)
			cout << "F[" << i << "][" << j << "]=" << F[i][j] << endl;
	*/
	for(int i=0;i<N;++i)
		cout << fixed << setprecision(6) << F[i][0] << " ";
	cout << endl;
	return 0;
}