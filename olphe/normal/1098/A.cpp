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

long long int N, M, K, H, W, L, R;

void Search(vector<vector<int>>&child, vector<int>&parent, vector<long long int>&sum, int node = 1) {
	if (sum[node] == -1) {
		sum[node] = MOD * MOD;
		for (auto i : child[node]) {
			Search(child, parent, sum, i);
			sum[node] = min(sum[node], sum[i]);
		}
	}
	else {
		for (auto i : child[node]) {
			Search(child, parent, sum, i);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<vector<int>>child(N + 1);
	vector<int>parent(N + 1);
	for (int i = 2; i <= N; i++) {
		cin >> parent[i];
		child[parent[i]].push_back(i);
	}
	vector<long long int>sum(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> sum[i];
	}
	Search(child, parent, sum);
	long long int ans = sum[1];
	for (int i = 2; i <= N; i++) {
		if (sum[i] == MOD * MOD)continue;
		if (sum[parent[i]] > sum[i]) {
			cout << -1 << endl;
			return 0;
		}
		ans += sum[i] - sum[parent[i]];
	}
	cout << ans << endl;
	return 0;
}