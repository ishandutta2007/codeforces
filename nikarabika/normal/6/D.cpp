//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

const int maxn = 15, maxval = 20;
int dp[maxn][maxval][maxval],
	par[maxn][maxval][maxval],
	h[maxn],
	n, a, b;

int DP(int pos, int pre = h[0], int cur = h[1]){
	pre = max(-1, pre);
	cur = max(-1, cur);
	if(~dp[pos][pre + 1][cur + 1])
		return dp[pos][pre + 1][cur + 1];
	dp[pos][pre + 1][cur + 1] = 1000 * 1000 * 1000;
	int mincnt;
	if(pos == n - 2){
		mincnt = max(max((pre + b) / b, (cur + a) / a), (h[pos + 1] + b) / b);
		par[pos][pre + 1][cur + 1] = mincnt;
		return dp[pos][pre + 1][cur + 1] = mincnt;
	}
	mincnt = (pre + b) / b;
	int maxcnt = max(mincnt, max((cur + a) / a, (h[pos + 1] + b) / b));
	for(int i = mincnt; i <= maxcnt; i++)
		if(DP(pos + 1, cur - a * i, h[pos + 1] - b * i) + i < dp[pos][pre + 1][cur + 1]){
			dp[pos][pre + 1][cur + 1] = DP(pos + 1, cur - a * i, h[pos + 1] - b * i) + i;
			par[pos][pre + 1][cur + 1] = i;
		}
	return DP(pos, pre, cur);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++)
		cin >> h[i];
	cout << DP(1) << '\n';
	int row = 1, pre = h[0], cur = h[1];
	while(row < n - 1){
		int cnt = par[row][pre + 1][cur + 1];
		for(int i = 0; i < cnt; i++)
			cout << row + 1 << ' ';
		row++;
		pre = max(-1, cur - a * cnt);
		cur = max(-1, h[row] - b * cnt);
	}
	cout << '\n';
	return 0;
}