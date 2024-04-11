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
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

void Calculate_Depth(vector<vector<int>>&edge, vector<int>&depth, int stnode) {
	depth[stnode] = 0;
	queue<int>Q;
	Q.push(stnode);
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		for (auto i : edge[cn]) {
			if (depth[i] > depth[cn] + 1) {
				depth[i] = depth[cn] + 1;
				Q.push(i);
			}
		}
	}
	return;
}

int ans = 0;

void Search(vector<vector<int>>&edge, vector<int>&dis, vector<vector<int>>&dp, int node = 0) {
	int add = 0;
	int m = 0;
	for (auto i : edge[node]) {
		if (dis[i] < dis[node])continue;
		Search(edge, dis, dp, i);
		dp[node][0]++;
		ans = max(ans, m + dp[i][0] + 1);
		m = max(m,dp[i][0]);
		ans = max(ans, add + max(dp[i][0], dp[i][1]) + (int)edge[node].size() - 2);
		add = max({ add,dp[i][0], dp[i][1] });
		dp[node][1] = max(dp[node][1], dp[i][0]);
	}
	dp[node][1]++;
	dp[node][0] += add;
	dp[node][0]--;
	dp[node][0] = max(dp[node][0], 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<vector<int>>edge(N);
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		L--, R--;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	vector<int>dis(N, MOD);
	Calculate_Depth(edge, dis, 0);
	vector<vector<int>>dp(N, vector<int>(2,0));
	Search(edge, dis, dp);
	for (auto i : dp)for (auto j : i)ans = max(ans, j);
	cout << ans << endl;
}