#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 3000 * 100 + 10, maxk = 5010;
LL INF;
LL dp[maxk][maxk];
LL a[maxn];
int sz1, sz2, n, k;

LL DP(int x, int y){
	if(dp[x][y] != INF)
		return dp[x][y];
	int last = x * sz1 + y * sz2;
	if(x == 0 and y == 0)
		return dp[x][y] = 0;
	if(x == 0)
		return dp[x][y] = DP(x, y - 1) + a[last] - a[last - sz2 + 1];
	if(y == 0)
		return dp[x][y] = DP(x - 1, y) + a[last] - a[last - sz1 + 1];
	return dp[x][y] = min(DP(x - 1, y) + a[last] - a[last - sz1 + 1],
			DP(x, y - 1) + a[last] - a[last - sz2 + 1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(dp, 63, sizeof dp);
	INF = dp[0][0];
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	sz1 = n / k;
	sz2 = (n + k - 1) / k;
	cout << DP(k - (n % k), n % k) << endl;
	return 0;
}