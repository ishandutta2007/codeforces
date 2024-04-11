// sto George1123 orz
// George1123's  : https://www.cnblogs.com/George1123/p/12813027.html /qq /qq /qq
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e4 + 7;
const ll inf = 1e16 + 7;
int n;
ll c, dp[2][N], s[N], p[N];
int main() {
	scanf("%d%lld", &n, &c);
	L(i, 1, n) scanf("%lld", &p[i]);
	L(i, 1, n) scanf("%lld", &s[i]);
	fill(dp[0], dp[0] + n + 1, inf);
	dp[0][0] = 0;
	L(i, 1, n) {
		int now = (i & 1);
		fill(dp[now], dp[now] + n + 1, inf);
		L(j, 0, i) dp[now][j] = dp[now ^ 1][j] + p[i] + c * j;
		L(j, 1, i) dp[now][j] = min(dp[now][j], dp[now ^ 1][j - 1] + s[i]);
	}
	ll minn = inf;
	L(i, 0, n) minn = min(dp[n & 1][i], minn);
	printf("%lld\n", minn);
	return 0;
}