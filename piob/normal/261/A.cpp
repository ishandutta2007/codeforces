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
const LL INF = 2000000000LL * 2000000000LL;

int m, q, n, r;
int T[100010];

int main(){
	scanf("%d", &m);
	q = 1000000;
	FWD(i,0,m){
		int a;
		scanf("%d", &a);
		q = min(q, a);
	}
	scanf("%d", &n);
	FWD(i,0,n) scanf("%d", &T[i]);
	sort(T, T+n, greater<int>());
	int i = 0;
	while(i < n){
		FWD(j,0,q) if(i<n) r += T[i++];
		i += 2;
	}
	printf("%d", r);
	return 0;
}