#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define popcount __builtin_popcount
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()
#define max3(a,b,c) max((a), max((b),(c)))

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int INF = 1000*1000*1000;

int n, k;
K dp[203][33][33];
int perm[33];

int main(){
	scanf("%d %d", &n, &k);
	FWD(i,0,n) FWD(j,0,n) dp[0][i][j] = (i < j ? 0 : 1);
	FWD(s,1,k+1){
		FWD(i,0,n)
			FWD(j,0,n)
				FWD(x,0,n)
					FWD(y,x,n){
						int pi = (x <= i && i <= y ? x + y - i : i);
						int pj = (x <= j && j <= y ? x + y - j : j);
						dp[s][i][j] += dp[s-1][pi][pj] * 2 / n / (n+1);
					}
	}
	K res = 0;
	FWD(i,0,n) scanf("%d", &perm[i]);
	FWD(i,0,n)
		FWD(j,i+1,n)
			if(perm[i] < perm[j])
				res += dp[k][i][j];
			else
				res += dp[k][j][i];
	cout.precision(9);
	cout << fixed << res << endl;
	return 0;
}