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
//constexpr double EPS = 1e-12;

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

void func2(vector<vector<int>>&edge, vector<int>&depth, vector<int>&up, int mid, bool &ret, int node = 0) {
	bool leaf = true;
	vector<int>box;
	for (auto i : edge[node]) {
		if (depth[i] < depth[node])continue;
		leaf = false;
		func2(edge, depth, up, mid, ret, i);
		box.push_back(up[i]);
	}
	if (leaf) {
		up[node] = depth[node];
		return;
	}
	sort(box.begin(), box.end());
	up[node] = box.front();
	//cout << node << endl;
	//for (auto i : box)cout << " " << i << endl;
	if (node) {
		if (box.back() - depth[node] + 1 > mid) {
			ret = false;
			return;
		}
	}
	else {
		if (box.back() - depth[node] > mid) {
			ret = false;
			return;
		}
		if (box.size() > 1) {
			if (box[box.size() - 2] - depth[node] + 1 > mid) {
				ret = false;
				return;
			}
		}
	}
}

bool func(vector<vector<int>>&edge, vector<int>&depth, int mid) {
	bool ret = true;
	vector<int>up(N, MOD);
	func2(edge, depth, up, mid, ret);
	return ret;
}

void Solve() {
	cin >> N;
	vector<vector<int>>edge(N);
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		L--, R--;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	vector<int>depth(N, MOD);
	Calculate_Depth(edge, depth, 0);
	int ok = N, ng = 0;
	while (abs(ok - ng) > 1) {
		int mid = (ok + ng) / 2;
		if (func(edge, depth, mid))ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}