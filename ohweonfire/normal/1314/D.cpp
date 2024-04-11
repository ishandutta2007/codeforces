#include <bits/stdc++.h>
using namespace std;

const int maxn = 111;
const int MAGIC = 30000;
const int inf = 0x3f3f3f3f;
int n, k, col[maxn], a[maxn][maxn], ans;

mt19937 rng;
int dp[maxn], ndp[maxn];
void solve()
{
	for(int i=1; i<n; i++) col[i] = static_cast<unsigned>(rng()) % 2;
	memset(dp, inf, sizeof(dp));
	dp[0] = 0;
	for(int i=0; i<k; i++)
	{
		memset(ndp, inf, sizeof(ndp));
		for(int j=0; j<n; j++) for(int k=0; k<n; k++) if(col[j] != col[k])
			ndp[k] = min(ndp[k], dp[j] + a[j][k]);
		memcpy(dp, ndp, sizeof(dp));
	}
	ans = min(ans, dp[0]);
}

int main()
{
	rng = mt19937(chrono::high_resolution_clock().now().time_since_epoch().count());
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", a[i]+j);
	
	ans = inf;
	for(int i=0; i<MAGIC; i++) solve();
	printf("%d\n", ans);
	return 0;
}