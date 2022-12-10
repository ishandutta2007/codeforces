//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 100 + 5,
	  maxk = 10000 + 5;
const int Inf = 1000 * 1000 * 1000;
int dp[2][maxn][maxk];
int a[maxn],
	b[maxn],
	sum, n;

int DP(int i, int j, int k){
	if(j < 0) return -Inf;
	if(k < 0) return -Inf;
	if(dp[i][j][k] < 0) return -Inf;
	return dp[i][j][k];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n, n++;
	for(int i = 1; i < n; i++)
		cin >> a[i], sum += a[i];
	for(int i = 1; i < n; i++)
		cin >> b[i];
	memset(dp, -1, sizeof dp);
	dp[0][0][0] = 0;
	int pre = 1,
		cur = 0;
	for(int i = 1; i < n; i++){
		swap(pre, cur);
		memset(dp[cur], -1, sizeof dp[cur]);
		for(int j = 0; j <= i; j++)
			for(int k = 0; k <= sum; k++)
				dp[cur][j][k] = max(DP(pre, j, k), DP(pre, j - 1, k - a[i]) + b[i] - a[i]);
	}
	for(int j = 0; j <= n; j++)
		for(int k = sum; k >= 0; k--)
			if(dp[cur][j][k] >= sum - k){
				cout << j << ' ' << sum - k << endl;
				return 0;
			}
	return 0;
}