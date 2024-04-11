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

int n, m, a, b;

int main(){
	scanf("%d %d %d %d", &n, &m, &a, &b);
	int r = n*a;
	r = min(r, (n+m-1)/m*b);
	r = min(r, n/m*b+n%m*a);
	printf("%d\n", r);
	return 0;
}