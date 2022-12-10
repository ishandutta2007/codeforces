#include <bits/stdc++.h>

#define N 23
#define Mo 998244353 

#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;
int dp[1 << N], n, g[1 << N];

char c[100005];

int sum[1 << N][26], cnt[N][26];
 
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", c); int len = strlen(c);
		for (int j = 0; j < len; ++j) cnt[i][c[j] - 'a']++;
	}
	for (int i = 0; i < 26; ++i) sum[0][i] = 1000000;
	for (int i = 1; i < (1 << n); ++i)
	{
		int s = 0, id;
		for (int j = n - 1; j >= 0; --j) if (i & (1 << j)) id = j, s++, g[i] += (j + 1);
		g[i] *= s;
		for (int j = 0; j < 26; ++j) sum[i][j] = min(sum[i ^ (1 << id)][j], cnt[id][j]);
		dp[i] = 1;
		for (int j = 0; j < 26; ++j) dp[i] = 1ll * dp[i] * (sum[i][j] + 1) % Mo; 
		if (s % 2 == 0) dp[i] = (Mo - dp[i]) % Mo;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < (1 << n); ++j)
			if (!((j >> i) & 1)) (dp[j | (1 << i)] += dp[j]) %= Mo;
//	for (int i = 0; i < (1 << n); ++i) printf("%d %d\n", i, dp[i]);
	long long ans = 0;
	for (int i = 1; i < (1 << n); ++i) ans ^= 1ll * g[i] * dp[i]; 
	printf("%lld\n", ans);
}