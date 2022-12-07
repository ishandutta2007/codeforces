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

int n, r;
int T[100010];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	FWD(i,0,n) scanf("%d", &T[i]);
	sort(T, T+n);
	r = n-1;
	int j = 0;
	FWD(i,0,n){
		while(j < n && T[j] <= 2*T[i]) ++j;
		r = min(r, n-(j-i));
	}
	printf("%d\n", r);
	return 0;
}