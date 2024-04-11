#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int INF = 2000000000;
const int N = 1005;
 
int n, m, k;
char a[N], b[N];
 
int dp[N][N][11][2];
int f(int n, int m, int k, bool take) {
	if (k < 0) return -INF;
	if (n < 0 || m < 0) {
		if (k == 0) return 0;
		return -INF;
	}
 
	int &ret = dp[n][m][k][take];
	if (~ret) return ret;
 
	ret = 0;
	ret = max(ret, max(f(n-1, m, k, 0), f(n, m-1, k, 0)));
	if (a[n] == b[m]) {
		ret = max(ret, 1 + f(n-1, m-1, k-1, 1));
		if (take) ret = max(ret, 1 + f(n-1, m-1, k, 1));
	}
 
	return ret;
}
 
int main() {
	scanf ("%d %d %d", &n, &m, &k);
	gets(a);
	gets(a); gets(b);
 
	memset (dp, -1, sizeof dp);
	printf ("%d\n", f(n-1, m-1, k, 0));
	return 0;
}