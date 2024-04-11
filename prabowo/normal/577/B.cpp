#include <cstdio>
#include <cstring>

const int N = 1005;

int n, m;
int a[N];

int dp[N][N];
int f(int x, int rem) {
	if (rem == 0) return 1;
	if (x == n) return 0;
	if (~dp[x][rem]) return dp[x][rem];
	
	return dp[x][rem] = (f(x+1, rem) | f(x+1, (rem + a[x]) % m));
}

int main () {
	
	scanf ("%d %d", &n, &m);
	if (n >= m) return 0 * printf ("YES\n");
	
	memset (dp, -1, sizeof dp);
	for (int i=0; i<n; i++) scanf ("%d", a + i);
	if (f(0, m)) printf ("YES\n");
	else printf ("NO\n");
	
	return 0;
}