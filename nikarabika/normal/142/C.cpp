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

const int maxn = 9;
int dp[maxn][1 << maxn][1 << maxn];
int ans[maxn][maxn];
int T[4][3] = {{7, 2, 2}, {4, 7, 4}, {2, 2, 7}, {1, 7, 1}};
int n, m, tile;

int DP(int, int, int);

int build(int r, int mask1, int mask2, int mask3 = 0, int pos = 0, int put = 0){
	if(pos >= m - 2)
		return DP(r + 1, mask2, mask3) + put;
	int mx = -1;
	smax(mx, build(r, mask1, mask2, mask3, pos + 1, put));
	for(int id = 0; id < 4; id++){
		if((mask1 & (T[id][0] << pos)) or (mask2 & (T[id][1] << pos)) or (mask3 & (T[id][2] << pos)))
			continue;
		smax(mx, build(r, mask1 | (T[id][0] << pos), mask2 | (T[id][1] << pos), mask3 | (T[id][2] << pos), pos + 1, put + 1));
	}
	return mx;
}

int DP(int r, int mask1, int mask2){
	if(r >= n - 2)
		return 0;
	if(dp[r][mask1][mask2] != -1)
		return dp[r][mask1][mask2];
	return dp[r][mask1][mask2] = build(r, mask1, mask2);
}

void print_dp(int, int, int, int);

void print_build(int r, int mask1, int mask2, int mask3, int rem, int pos = 0, int put = 0){
	if(pos >= m - 2){
		print_dp(r + 1, mask2, mask3, rem - put);
		return;
	}
	if(build(r, mask1, mask2, mask3, pos + 1, put) == rem){
		print_build(r, mask1, mask2, mask3, rem, pos + 1, put);
		return;
	}
	for(int id = 0; id < 4; id++){
		if((mask1 & (T[id][0] << pos)) or (mask2 & (T[id][1] << pos)) or (mask3 & (T[id][2] << pos)))
			continue;
		if(build(r, mask1 | (T[id][0] << pos), mask2 | (T[id][1] << pos), mask3 | (T[id][2] << pos), pos + 1, put + 1) == rem){
			tile++;
			for(int i = 0; i < 3; i++)
				for(int j = 0; j < 3; j++)
					if((T[id][i] >> j) & 1)
						ans[r + i][j + pos] = tile;
			print_build(r, mask1 | (T[id][0] << pos), mask2 | (T[id][1] << pos), mask3 | (T[id][2] << pos), rem, pos + 1, put + 1);
			return;
		}
	}
	return;
}

void print_dp(int r, int mask1, int mask2, int rem){
	if(r >= n - 2)
		return;
	print_build(r, mask1, mask2, 0, rem);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n >> m;
	if(min(n, m) <= 2){
		cout << 0 << endl;
		goto bokhor;
	}
	cout << DP(0, 0, 0) << '\n';
	print_dp(0, 0, 0, dp[0][0][0]);
bokhor:
	for(int i = 0; i < n; i++, cout << '\n')
		for(int j = 0; j < m; j++)
			cout << (ans[i][j] ? char('A' + ans[i][j] - 1) : '.');
	return 0;
}