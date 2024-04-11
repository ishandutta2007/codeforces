#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair 
using namespace std;
const int N = 5005;
int n, s, e;
ll dp[N][N], x[N], a[N], b[N], c[N], d[N];
int main() {
	scanf("%d%d%d", &n, &s, &e);
	L(i, 1, n) scanf("%lld", &x[i]);
	L(i, 1, n) scanf("%lld", &a[i]);
	L(i, 1, n) scanf("%lld", &b[i]);
	L(i, 1, n) scanf("%lld", &c[i]);
	L(i, 1, n) scanf("%lld", &d[i]);
	L(i, 0, n) fill(dp[i], dp[i] + n + 4, 1e16);
	dp[0][0] = 0;
	L(i, 1, n) {
		if(i == s) { 
			L(j, 0, n) dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + x[i] + c[i]); //  
			L(j, 1, n) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] - x[i] + d[i]); //  
			continue;
		}
		if(i == e) { 
			L(j, 0, n + 1) dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + x[i] + a[i]); //  
			L(j, 1, n) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] - x[i] + b[i]); //  
			continue; 
		}
		L(j, 2 + (i != 1), n) dp[i][j] = min(dp[i][j], dp[i - 1][j - 2] - x[i] * 2 + b[i] + d[i]);
		L(j, 2 - (i > s), n) dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i] + d[i]);
		L(j, 2 - (i > e), n) dp[i][j] = min(dp[i][j], dp[i - 1][j] + b[i] + c[i]);
		L(j, 0, n) dp[i][j] = min(dp[i][j], dp[i - 1][j + 2] + x[i] * 2 + a[i] + c[i]);
	}
	printf("%lld\n", dp[n][0]);
	return 0;
}