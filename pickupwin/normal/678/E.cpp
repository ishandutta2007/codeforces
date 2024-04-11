#include <iostream>
#include <iomanip>
using namespace std;
const int MAXN=20;
const int MAXM=277777;
int N;
double F[MAXN][MAXM], Map[MAXN][MAXN], ANS;
int Queue[MAXM], Tail=0, Head=0;
bool inQ[MAXM];
double dmax(double a, double b){
	return (a>b)?a:b;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			cin >> Map[i][j];
	F[0][(1<<N)-1]=1.0;
	for(int i=1;i<N;++i)
		F[i][(1<<N)-1]=0.0;
	for(int i=0, k;i<N;++i){
		k=(1<<N)-1-(1<<i);
		Queue[Tail++]=k;
		inQ[k]=true;
	}
	int at;
	while(Head<Tail){
		at=Queue[Head++];
		inQ[at]=false;
		for(int i=0;i<N;++i){
			F[i][at]=0.0;
			if(!((at>>i)&1))	continue;
			for(int j=0;j<N;++j){
				if((at>>j)&1)	continue;
				F[i][at]=dmax(F[i][at], F[i][at+(1<<j)]*Map[i][j]+F[j][at+(1<<j)]*Map[j][i]);
			}
		}
		for(int i=0, k;i<N;++i){
			if((at>>i)&1){
				k=at-(1<<i);
				if(!inQ[k]){
					Queue[Tail++]=k;
					inQ[k]=true;
				}
			}
		}
	}
	double ANS=0.0;
	/*
	for(int i=1;i<(1<<N);++i)
		for(int j=0;j<N;++j)
			cout << "F[" << j << "][" << i << "]=" << F[j][i] << endl;
	*/
	for(int i=0;i<N;++i){
		ANS=dmax(ANS, F[i][(1<<i)]);
	}
	cout << fixed << setprecision(15) << ANS << endl;
	return 0;
}