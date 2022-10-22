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

void Search(vector<vector<int>>&edge, vector<int>&depth, vector<int>&dp, vector<char>&ans, int node) {
	vector<int>num(26);
	for (auto i : edge[node]) {
		if (depth[i] < depth[node])continue;
		Search(edge, depth, dp, ans, i);
		for (int j = 0; j < 26; j++) {
			if ((dp[i] >> j) & 1)num[j]++;
		}
	}
	int box = 26;
	for (int i = 25; i >= 0; i--) {
		if (num[i] >= 2)box = i;
	}
	int bag = 0;
	for (int i = 0; i < box; i++) {
		if (!num[i])bag = i;
	}
	dp[node] = 1 << (bag);
	ans[node] = 'A' + bag;
	for (int i = 0; i < bag; i++) {
		if (num[i])dp[node] += 1 << i;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<vector<int>>edge(N + 1);
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	vector<int>depth(N + 1, MOD);
	Calculate_Depth(edge, depth, 1);
	vector<char>ans(N + 1);
	vector<int>dp(N + 1);
	Search(edge, depth, dp, ans, 1);
	for (int i = 1; i <= N; i++)cout << ans[i] << " ";
	cout << endl;
	return 0;
}