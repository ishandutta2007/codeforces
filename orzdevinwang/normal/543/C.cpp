#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 21;
const int C = 27;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while('0' <= ch && ch <= '9') x = x * 10 + (ch ^ '0'), ch = getchar();
	return x * f;
}
int n, m, a[N][N], msk[C], sum[C], mx[C], dp[1 << N];
char s[N][N];
int main() {
	n = read(), m = read();
	L(i, 1, n) scanf("%s", s[i] + 1);
	L(i, 1, n) L(j, 1, m) a[i][j] = read();
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	L(i, 1, m) {
		L(j, 0, 25) msk[j] = sum[j] = mx[j] = 0;
		L(j, 1, n) msk[s[j][i] - 'a'] |= (1 << (j - 1)), sum[s[j][i] - 'a'] += a[j][i], mx[s[j][i] - 'a'] = max(mx[s[j][i] - 'a'], a[j][i]);
		L(j, 0, 25) sum[j] -= mx[j];
		L(j, 1, n) L(t, 0, (1 << n) - 1) if(! (t >> (j - 1) & 1)) dp[t | (1 << (j - 1))] = min(dp[t | (1 << (j - 1))], dp[t] + a[j][i]);
		L(j, 0, 25) if(msk[j]) L(t, 0, (1 << n) - 1) dp[t | msk[j]] = min(dp[t | msk[j]], dp[t] + sum[j]);
	}
	printf("%d\n", dp[(1 << n) - 1]);
	return 0;
}