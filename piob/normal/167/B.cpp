#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
typedef long double K;

const K PI = acos((long double)-1);

int n, m, k;
K dp[2][210][210];
int P[210];
int S[210];

int main(){
	scanf("%d %d %d", &n, &m, &k);
	dp[1][0][k] = 1;
	FWD(i,0,n) scanf("%d", &P[i]);
	FWD(i,0,n) scanf("%d", &S[i]);
	FWD(i,0,n){
		int x = (i&1);
		int y = 1-x;
		FWD(p,0,201) FWD(s,0,201) dp[x][p][s] = (100-P[i]) * dp[y][p][s] / 100; 
		if(S[i] == -1){
			FWD(p,0,201) FWD(s,0,201)
				dp[x][min(200,p+1)][s] += P[i] * dp[y][p][s] / 100;
		}else{
			FWD(p,0,201) FWD(s,0,201)
				dp[x][min(200,p+1)][min(200,s+S[i]+1)] += P[i] * dp[y][p][s] / 100;
		}
	}
	int x = 1-(n&1);
	K res = 0;
	FWD(p,m,201) FWD(s,p,201)
		res += dp[x][p][s];
	cout << res << endl;
}