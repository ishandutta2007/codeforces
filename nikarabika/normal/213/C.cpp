//sobskdrbhvk
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

const int maxn = 300;
const int Inf = 1000 * 1000 * 1000 + 7;
int dp[maxn * 2][maxn][maxn];
int a[maxn][maxn];
int n;

int DP(int s, int i1, int i2){
	if(i1 > i2)
		swap(i1, i2);
	if(i1 < 0 or i2 >= n or s - i2 < 0 or s - i2 >= n)
		return -Inf;
	if(dp[s][i1][i2] != -Inf) return dp[s][i1][i2];
	if(i1 == i2)
		return dp[s][i1][i2] = a[i1][s-i1] + max(DP(s - 1, i1, i1 - 1), max(DP(s - 1, i1, i1), DP(s - 1, i1 - 1, i1 - 1)));
	dp[s][i1][i2] = -Inf;
	for(int i = i1 - 1; i <= i1; i++)
		for(int ii = i2 - 1; ii <= i2; ii++)
			smax(dp[s][i1][i2], DP(s - 1, i, ii));
	return dp[s][i1][i2] += a[i1][s - i1] + a[i2][s - i2];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0; i < maxn + maxn; i++)
		for(int j = 0; j < maxn; j++)
			for(int k = 0; k < maxn; k++)
				dp[i][j][k] = -Inf;
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	dp[0][0][0] = a[0][0];
	cout << DP(2*n-2, n - 1, n - 1) << endl;
	return 0;
}