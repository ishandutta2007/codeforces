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

using namespace std;

//const long long int MOD = 1000000007;
//const long long int MOD = 1000003;
//const int MOD = 998244353;
const long long int MOD = 998244353;

int N, M, K, H, W, L, R;
//long long int N, M, K, H, W, L, R;

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

long long int by[300001];

void Search(vector<vector<int>>&edge, vector<int>&depth, vector<long long int>&dp, vector<int>&sum, int node) {
	dp[node] = 1;
	sum[node] = 1;
	int c = 0;
	for (auto i : edge[node]) {
		if (depth[i] < depth[node])continue;
		c++;
		Search(edge, depth, dp, sum, i);
		sum[node] += sum[i];
		dp[node] *= dp[i];
		dp[node] %= MOD;
	}
	if (node == 0) {
		dp[node] *= by[c];
	}
	else {
		dp[node] *= by[c + 1];
	}
	dp[node] %= MOD;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<vector<int>>edge(N);
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		L--;
		R--;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	by[0] = 1;
	for (int i = 1; i <= 300000; i++) {
		by[i] = by[i - 1] * i;
		by[i] %= MOD;
	}
	vector<int>depth(N, MOD);
	vector<int>sum(N, 0);
	Calculate_Depth(edge, depth, 0);
	vector<long long int>dp(N);
	Search(edge, depth, dp,sum, 0);
	long long int ans = dp[0];
	//for (int i = 0; i < N; i++)cout << i << " " << dp[i] <<" "<<sum[i]<< endl;
	ans *= N;
	ans %= MOD;
	cout << ans << endl;
}