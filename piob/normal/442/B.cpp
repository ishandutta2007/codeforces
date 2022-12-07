#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
typedef long double K;

const int mod = 1000000007;
const K eps = 1e-9;

int n;
K P[103];
K p, s;

int main(){
	cin >> n;
	FWD(i,0,n) cin >> P[i];
	sort(P, P+n);
	reverse(P, P+n);
	if(P[0] > 1-eps){
		cout << P[0] << endl;
		return 0;	
	}
	p = (1 - P[0]);
	s = P[0] / (1 - P[0]);
	FWD(i,1,n){
		if(s > 1-eps) break;
		p *= (1-P[i]);
		s += P[i] / (1 - P[i]);
	}
	cout.precision(9);
	cout << p*s << endl;
	return 0;
}