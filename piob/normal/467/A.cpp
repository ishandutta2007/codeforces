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

int n, r;

int main(){
	scanf("%d", &n);
	FWD(i,0,n){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a + 2 <= b) ++r;
	}
	printf("%d\n", r);
	return 0;
}