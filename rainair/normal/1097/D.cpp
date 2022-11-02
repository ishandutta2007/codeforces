#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL

inline void read(int &x){
	int k = 1; x = 0;
	char c = getchar();
	while (!isdigit(c)) 
		if (c == '-') c = getchar(), k = -1;
		else c = getchar();
	while (isdigit(c))
		x = (x << 1) + (x << 3) + (c ^ 48),
		c = getchar();
	x *= k;
}

const int p = 1e9 + 7;

int mx[10101], inv[1000040], num[1010], pos = 0, n, cnt, k;
int dp[10100][1010];
int fp[10100][1010];
int a[10101];

inline int ksm(int a, int b){
	int ans = 1;
	while (b)
	{
		if (b & 1) ans = (ans * a) % p;
		b >>= 1;
		a = (a * a) % p;
	}
	return ans;
}

void dfs(int u){
	if (u >= cnt + 1){
		int ans = 1, gl = 1;
		for (int i = 1; i <= cnt; ++i)
		{
			ans = (ans * ksm(num[i], a[i])) % p;
			gl = (gl * fp[i][a[i]]) % p;
		}
		pos = (pos + (ans * gl)%p) % p;
		return;
	}
	for (int i = 0; i <= mx[u]; ++i)
		a[u] = i, dfs(u + 1), a[u] = 0;
}

signed main()
{
	read(n), read(k);
	inv[1] = 1;
    for (int i = 2; i <= 1000000; ++i)
        inv[i] = inv[p % i] * (p - p / i) % p;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0){
			++cnt;
			memset(dp, 0, sizeof(dp));
			while (n % i == 0) n /= i, ++mx[cnt];
			dp[0][mx[cnt]] = 1, num[cnt] = i;
			for (int j = 1; j <= k; ++j)for (int l = 0; l <= mx[cnt]; ++l)for (int o = 0; o <= l; ++o)dp[j][o] = (dp[j][o] + (dp[j - 1][l] * inv[l + 1]) % p) % p;
			for (int j = 0; j <= mx[cnt]; ++j)fp[cnt][j] = dp[k][j];}
	if (n != 1){++cnt;
		mx[cnt] = 1;CLR(dp,0);
		dp[0][mx[cnt]] = 1, num[cnt] = n;
		for (int j = 1; j <= k; ++j)for (int l = 0; l <= mx[cnt]; ++l)for (int o = 0; o <= l; ++o)dp[j][o] = (dp[j][o] + (dp[j - 1][l] * inv[l + 1]) % p) % p;
		for (int j = 0; j <= mx[cnt]; ++j) fp[cnt][j] = dp[k][j];}
	dfs(1);
	printf("%I64d\n",pos);
	return 0;
}