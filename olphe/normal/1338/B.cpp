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
	vector<int>near_leaf(N);
	for (int i = 0; i < N; i++) {
		if (edge[i].size() == 1) {
			near_leaf[edge[i][0]]++;
		}
	}
	bool even = true;
	int o = 0, e = 0;
	for (int i = 0; i < N; i++) {
		if (edge[i].size() == 1 && dis[i] % 2)o++;
		if (edge[i].size() == 1 && dis[i] % 2 == 0)e++;
	}
	if (o&&e)even = false;
	int ret = N - 1;
	for (auto i : near_leaf) {
		ret -= max(0, i - 1);
	}
	if (even)cout << 1;
	else cout << 3;
	cout << " " << ret << endl;
}