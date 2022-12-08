#include <iostream>
#include <iomanip>

using namespace std;

const int MAXN=100111;

int N, S;

int Deg[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> S;
	
	for(int i=1, a, b;i<N;++i){
		cin >> a >> b;
		++Deg[a];++Deg[b];
	}
	
	int Cnt=0;
	for(int i=1;i<=N;++i)	if(Deg[i]==1)	++Cnt;
	
	double Ans=2.0*(double)(S)/(double)(Cnt);
	cout << fixed << setprecision(10) << Ans << endl;
	
	return 0;
}