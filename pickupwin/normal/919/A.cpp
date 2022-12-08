#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const int MAXN=5555;

int N;
double M;
double K[MAXN];
double A, B, ANS;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	cin >> M;
	
	for(int i=1;i<=N;++i){
		cin >> A >> B;
		K[i]=A/B;
	}
	
	sort(K+1, K+N+1);
	
	ANS=K[1]*M;
	
	cout << fixed << setprecision(8) << ANS << endl;
	
	return 0;
}

/*
3 5
1 2
3 4
1 3

1.66666667

*/

/*
2 1
99 100
98 99

0.98989899

*/