#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
int n, dp[N], p, k, x, y;
char s[N];
ll ans;
void Main() {
	ans = 1e16 + 7;
	scanf("%d%d%d", &n, &p, &k);
	scanf("%s", s + 1);
	scanf("%d%d", &x, &y);
	L(i, n + 1, n + k) dp[i] = 0;
	R(i, n, 1) dp[i] = dp[i + k] + (s[i] == '0');
	L(i, p, n) ans = min(ans, 1ll * x * dp[i] + 1ll * (i - p) * y);
	printf("%lld\n", ans);
}
int main() {
	int T; scanf("%d", &T);
	while(T--) Main();
	return 0;
}