#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;
typedef pair<unsigned, unsigned> PUU;
typedef long long LL;
typedef long double K;

const int mod = 1000000007;
const int INF = 1000000000;

LL n, a, b;
LL s, x, y;

int main(){
	scanf("%I64d %I64d %I64d", &n, &a, &b);
	n *= 6;
	s = (LL)INF*INF;
	if(a*b >= n){
		s = a*b;
		x = a;
		y = b;
	}
	for(LL d = 1; d*d <= n; ++d){
		if(s > d*((n+d-1)/d) && min(a,b) <= d && max(a,b) <= (n+d-1)/d){
			s = d*((n+d-1)/d);
			if(a < b) x = d; else y = d;
			if(a < b) y = (n+d-1)/d; else x = (n+d-1)/d;
		}
	}
	printf("%I64d %I64d %I64d\n", s, x, y);
	return 0;
}