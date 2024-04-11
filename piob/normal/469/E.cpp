#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef pair<unsigned, unsigned> PUU;
typedef long long LL;
typedef long double K;

const int mod = 1000000007;
const int INF = 1000000000;

int s(int x){
	int r = 0;
	while(x){
		r += x%10;
		x /= 10;
	}
	return r;
}

int main(){
	LL m;
	cin >> m;
	LL b = 1000 * 1000 * 1000;
	LL r = b * b;
	r = 9 * r % m;
	r = 9 * r % m;
	r = (m - (r + 1) % m) % m;
	cout << 1+r << " " << b*b+r << endl;
	return 0;
}