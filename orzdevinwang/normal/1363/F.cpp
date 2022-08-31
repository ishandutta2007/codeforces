#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define pll pair<ll, ll> 
#define mkp make_pair
#define ll long long
using namespace std;
const int N = 2e3 + 7;
const int inf = 1e9 + 7;
int T, n, dp[N][N], cnt[N], qzs[N][26], qzt[N][26];
char s[N], t[N];
void Min(int &x, int y) {
	if(x > y) x = y;
}
void Main() {
	fill(cnt, cnt + 26, 0);
	scanf("%d", &n);
	L(i, 0, n) L(j, 0, n) dp[i][j] = inf;
	scanf("%s%s", s + 1, t + 1);
	L(i, 1, n) cnt[s[i] - 'a'] ++, cnt[t[i] - 'a'] --;
	L(i, 0, 25) if(cnt[i]) return puts("-1"), void();
	L(i, 1, n) L(j, 0, 25) qzs[i][j] = qzs[i - 1][j] + (s[i] == 'a' + j), qzt[i][j] = qzt[i - 1][j] + (t[i] == 'a' + j);
	L(i, 0, n) dp[0][i] = 0;
	L(i, 1, n) L(j, i, n) {
		Min(dp[i][j], dp[i - 1][j] + 1);
		if(s[i] == t[j]) Min(dp[i][j], dp[i - 1][j - 1]);
		if(qzs[i][t[j] - 'a'] < qzt[j][t[j] - 'a']) Min(dp[i][j], dp[i][j - 1]);
	}
	printf("%d\n", dp[n][n]);
}
int main() {
	scanf("%d", &T);
	while(T--) Main();
	return 0;
}