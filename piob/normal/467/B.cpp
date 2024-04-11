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

int n, m, k;
int X[1010];

int main(){
	scanf("%d %d %d", &n, &m, &k);
	FWD(i,0,m) scanf("%d", &X[i]);
	int x;
	scanf("%d", &x);
	int r = 0;
	FWD(i,0,m) if(__builtin_popcount(x^X[i]) <= k) ++r;
	printf("%d\n", r);
	return 0;
}