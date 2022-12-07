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

int n, m;
int a, b, c, d;
char M[51][51];

int main(){
	scanf("%d %d", &n, &m);
	a = b = 60;
	FWD(i,0,n) scanf("%s", M[i]);
	FWD(i,0,n) FWD(j,0,m)
		if(M[i][j] == '*'){
			a = min(a, i);
			b = min(b, j);
			c = max(c, i);
			d = max(d, j);
		}
	FWD(i,a,c+1){
		M[i][d+1] = 0;
		printf("%s\n", M[i]+b);
	}
	return 0;
}