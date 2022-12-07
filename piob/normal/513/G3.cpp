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
typedef double K;
typedef vector<int> VI;

const int INF = 1000*1000*1000;

int n, k;
K dp[1003][103][103];
int perm[103];

int main(){
	scanf("%d %d", &n, &k);
	k = min(k, 1000);
	FWD(r,1,k+1){
		FWD(i,0,n)
			FWD(j,i+1,n){
				dp[r][i][j] += (i*(i+1) + (j-i-1)*(j-i) + (n-1-j)*(n-j)) * dp[r-1][i][j] / 2;
				FWD(s,i,i+j){
					// pi = s-i, pj = j
					// x <= s/2
					// 0 <= x
					// x <= i
					// x <= s-i (i <= s-x)
					// s-j+1 <= x (s-x <= j-1)
					// s <= i+j-1 (s-j+1 <= i)
					dp[r][i][j] += (min(i,s-i)-max(0,s-j+1)+1) * dp[r-1][s-i][j];
				}
				FWD(s,i+j+1,j+n){
					// pi = i, pj = s-j
					// x <= s/2
					// i+1 <= x
					// x <= j
					// x <= s-j (j <= s-x)
					// s-n+1 <= x (s-x <= n-1)
					// i+j+1 <= s (i+1 <= s-j)
					dp[r][i][j] += (min(j,s-j)-max(i+1,s-n+1)+1) * dp[r-1][i][s-j];
				}
				FWD(s,j,i+n){
					// pi = s-i, pj = s-j
					// 0 <= x
					// x <= i
					// x <= s-j (j <= s-x)
					// s-n+1 <= x (s-x <= n-1)
					dp[r][i][j] += (min(i,s-j)-max(0,s-n+1)+1) * (1 - dp[r-1][s-j][s-i]);
				}
				dp[r][i][j] *= (K)2 / n / (n+1);
			}
	}
	K res = 0;
	FWD(i,0,n) scanf("%d", &perm[i]);
	FWD(i,0,n)
		FWD(j,i+1,n)
			if(perm[i] < perm[j])
				res += dp[k][i][j];
			else
				res += 1-dp[k][i][j];
	cout.precision(9);
	cout << fixed << res << endl;
	return 0;
}