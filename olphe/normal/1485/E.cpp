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
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

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

void Solve() {
	cin >> N;
	vector<int>p(N);
	vector<long long int>v(N);
	vector<vector<int>>edge(N);
	vector<int>dis(N, MOD);

	for (int i = 1; i < N; i++) {
		cin >> p[i];
		p[i]--;
		edge[p[i]].push_back(i);
	}
	for (int i = 1; i < N; i++) {
		cin >> v[i];
	}
	Calculate_Depth(edge, dis, 0);
	int mx = *max_element(dis.begin(), dis.end());
	long long int ans = 0;
	vector<long long int>dp(N);
	vector<vector<pair<int, int>>>num(mx + 1);
	for (int i = 0; i < N; i++) {
		num[dis[i]].emplace_back(v[i], i);
	}
	for (auto &i : num) {
		sort(i.begin(), i.end());
	}
	for (int i = mx - 1; i >= 0; i--) {
		long long int add = -MOD * MOD;
		for (auto[score, idx] : num[i + 1]) {
			dp[p[idx]] = max(dp[p[idx]], dp[idx]);
			dp[p[idx]] = max(dp[p[idx]], dp[idx] + add + v[idx]);
			add = max(add, -v[idx]);
		}
		add = -MOD * MOD;
		for (auto[score, idx] : num[i + 1]) {
			dp[p[idx]] = max(dp[p[idx]], add + v[idx]);
			add = max(add, dp[idx] - v[idx]);
		}
		reverse(num[i+1].begin(), num[i+1].end());
		add = -MOD*MOD;
		for (auto[score, idx] : num[i + 1]) {
			dp[p[idx]] = max(dp[p[idx]], dp[idx] + add - v[idx]);
			add = max(add, +v[idx]);
		}
		add = -MOD * MOD;
		for (auto[score, idx] : num[i + 1]) {
			dp[p[idx]] = max(dp[p[idx]], add - v[idx]);
			add = max(add, dp[idx] + v[idx]);
		}
	}
	cout << dp.front() << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
	
}