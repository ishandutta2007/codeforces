#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define db double
using namespace std;
const int N = 2005;
const db eps = 1e-8;
int n, a, b;
db vala[N], valb[N], valc[N], dp[N][N], cnt[N][N];
bool check(db x) {
	L(i, 0, n) L(j, 0, i) dp[i][j] = -1e10, cnt[i][j] = 0;
	dp[0][0] = 0;
	L(i, 1, n) L(j, 0, i) {
		if(j < i && dp[i][j] < dp[i - 1][j]) dp[i][j] = dp[i - 1][j], cnt[i][j] = cnt[i - 1][j];
		if(j && dp[i][j] < dp[i - 1][j - 1] + vala[i]) dp[i][j] = dp[i - 1][j - 1] + vala[i], cnt[i][j] = cnt[i - 1][j - 1];
		if(j < i && dp[i][j] < dp[i - 1][j] + valb[i] + x) dp[i][j] = dp[i - 1][j] + valb[i] + x, cnt[i][j] = cnt[i - 1][j] + 1;
		if(j && dp[i][j] < dp[i - 1][j - 1] + valc[i] + x) dp[i][j] = dp[i - 1][j - 1] + valc[i] + x, cnt[i][j] = cnt[i - 1][j - 1] + 1;
	}
	return cnt[n][a] < b;
}
int main() {
	scanf("%d%d%d", &n, &a, &b);
	L(i, 1, n) scanf("%lf", &vala[i]);
	L(i, 1, n) scanf("%lf", &valb[i]);
	L(i, 1, n) valc[i] = 1. - (1. - vala[i]) * (1. - valb[i]);
	db l = -1e8, r = 1e8;
	while(r - l > eps) {
		db mid = (l + r) / 2;
		if(check(mid)) l = mid;
		else r = mid;
	}
	db mid = (l + r) / 2;
	check(mid);
	printf("%.10lf\n", dp[n][a] - mid * b);
	return 0;
}