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
#include "ctime"

using namespace std;

const long long int MOD = 1000000007;
//const long long  int MOD = 998244353;
//long long int N, M, K, H, W, L, R;

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

void Search(vector<vector<int>>&edge, vector<int>&depth, vector<int>&v, vector<int>&dp, vector<int>&flag, int node) {
	dp[node] = v[node];
	for (auto i : edge[node]) {
		if (depth[i] > depth[node]) {
			Search(edge, depth, v, dp, flag, i);
			dp[node] += dp[i];
			if (!flag[node] && flag[i])flag[node] = flag[i];
		}
	}
	if (dp[node] == M / 3 && !flag[node])flag[node] = node;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int p = 0;
	vector<vector<int>>edge(N + 1);
	vector<int>v(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> L >> R;
		if (L) {
			edge[L].push_back(i);
			edge[i].push_back(L);
		}
		else {
			p = i;
		}
		v[i] = R;
	}
	M = accumulate(v.begin(), v.end(), 0);
	if (M % 3) {
		cout << -1 << endl;
		return 0;
	}
	vector<int>depth(N + 1, MOD);
	Calculate_Depth(edge, depth, p);
	vector<int>dp(N + 1);
	vector<int>flag(N + 1);
	Search(edge, depth, v, dp, flag, p);
	vector<int>w;
	for (int i = 1; i <= N; i++) {
		if (i == p)continue;
		//cout << i << " " << dp[i] << " " << flag[i] << endl;
		if (flag[i] && dp[i] == M * 2 /3&&flag[i]!=i) {
			cout << i << " " << flag[i] << endl;
			return 0;
		}
		if (flag[i] == i)w.push_back(i);
	}
	if(w.size()>=2){
		cout << w[0] << " " << w[1] << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}