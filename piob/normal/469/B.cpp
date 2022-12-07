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

int n, m, p, q;
vector<PII> A, B;

PII operator+(PII a, int c){
	return PII(a.x+c, a.y+c);
}

bool in(PII a, int b){
	return a.x <= b && b <= a.y;
}

bool overlap(PII a, PII b){
	return in(a, b.x) || in(a, b.y) || in(b, a.x) || in(b, a.y);
}

int main(){
	scanf("%d %d %d %d", &n, &m, &p, &q);
	FWD(i,0,n){
		int a, b;
		scanf("%d %d", &a, &b);
		A.push_back(PII(a,b));
	}
	FWD(i,0,m){
		int a, b;
		scanf("%d %d", &a, &b);
		B.push_back(PII(a,b));
	}
	int r = 0;
	FWD(t,p,q+1){
		bool ok = 0;
		for(PII a : A)
			for(PII b : B)
				if(overlap(a, b+t)){
					ok = 1;
					break;
				}
		if(ok) ++r;
	}
	printf("%d\n", r);
	return 0;
}