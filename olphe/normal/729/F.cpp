#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R

const int border = 70;

int Search(vector<vector<vector<int>>>&dp,vector<int>&v, int a, int b, int c) {
	if (dp[a][b][c] != MOD)return dp[a][b][c];
	if (2 * a + border - b + c > N)return dp[a][b][c] = v[a] - (v[N] - v[N-a - border + b]);
	if (2 * a + border - b + c == N) {
		if (b <= border)return dp[a][b][c] = v[a + c] * 2 - v[N];
		else return dp[a][b][c] = v[a] * 2 - v[N];
	}
	if (b <= border) return dp[a][b][c] = max(Search(dp,v, a + c, b + c, c), Search(dp,v, a + c + 1, b + c + 1, c + 1));
	return dp[a][b][c] = min(Search(dp,v, a, b - c, c), Search(dp,v, a, b - c - 1, c + 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N + 2);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		v[i] += v[i - 1];
	}
	vector<vector<vector<int>>>dp(N / 2 + 50, vector<vector<int>>(140, vector<int>(70, MOD)));
	cout << Search(dp,v, 0, border, 1) << endl;
	return 0;
}