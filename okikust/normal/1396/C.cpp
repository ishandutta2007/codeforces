#pragma GCC optimize("O3")
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 1001000


int main() {
	long long n;
	long long x[N];
	long long y[N];
	long long z[N];
	long long a, b, c, d;
	long long dp[N];
	long long dp2[N];
	long long xx, yy, zz, ans;
	scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &c, &d);
	f(i, n) {
		scanf("%lld", &x[i]);
		y[i] = x[i] * a + c;
		z[i] = min((x[i] + 1)*a, b);
	}
	dp[0] = 0;
	dp[1] = min(y[0], z[0] + d + d + a);
	dp[2] = min(z[0] + d + z[1] + d + a + d + a, dp[1] + min(d + y[1], d + z[1] + d + d + a));
	for (int i = 2; i < n; i++) {
		xx = d + z[i - 1] + d + z[i] + d + a + d + a;
		yy = min(d + y[i], d + z[i] + d + d + a);
		dp[i + 1] = min(dp[i - 1] + xx, dp[i] + yy);
	}
	dp2[n] = 0;
	dp2[n - 1] = 0;
	dp2[n - 2] = min(d + min(y[n - 2], z[n - 2] + a) + d + y[n - 1] + d, d + min(y[n - 2], z[n - 2] + a) + d + z[n - 1] + d + d + a + d);
	for (long long i = n - 3; i >= 1; i--) {
		dp2[i] = dp2[i + 1] + d + d + min(y[i], z[i] + a);
	}
	if (n > 2)dp2[0] = dp2[1] + d + min(y[0], z[0] + a);
	else dp2[0]= min(min(y[n - 2], z[n - 2] + a) + d + y[n - 1] + d, min(y[n - 2], z[n - 2] + a) + d + z[n - 1] + d + d + a + d);
	ans = dp[n];
	f(i, n - 1) {
		ans = min(ans, dp[i] + dp2[i]);
	}
	printf("%lld\n", ans);
	return 0;
}