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

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr long double EPS = 1e-12;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;

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

void Search(vector<vector<int>>&edge, vector<int>&dis, vector<vector<long long int>>&dp, int node = 0) {
	vector<long long int>box(4, 0);
	box[3] = 1;
	for (auto i : edge[node]) {
		if (dis[i] < dis[node])continue;
		Search(edge, dis, dp, i);
		if (box.front() == 0) {
			box = dp[i];
		}
		else {
			auto bag = box;
			for (auto &j : box)j = 0;
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					box[min(j, k)] += bag[j] * dp[i][k] % MOD;
				}
			}
			for (int j = 0; j < 4; j++)box[j] %= MOD;
		}
	}
	dp[node][0] = (box[1] + box[2] + box[3]) % MOD;
	dp[node][1] = (box[0] + box[1] + box[2] + box[3]) % MOD;
	dp[node][2] = (box[1]) % MOD;
	dp[node][3] = (box[0] + box[1] + box[2] + box[3]) % MOD;
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
	vector<vector<long long int>>dp(N, vector<long long int>(4));
	Search(edge, dis, dp);
	long long int ans = dp.front()[2]+dp.front()[3];
	ans += MOD - 1;
	ans %= MOD;
	cout << ans << endl;
}