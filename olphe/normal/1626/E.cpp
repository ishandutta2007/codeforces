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
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int func(vector<vector<int>>& edge,vector<int>&v, vector<int>& dis, vector<vector<int>>& box, int node = 0, int p = -1) {
	int ret = v[node];
	for (auto i : edge[node]) {
		if (i == p)continue;
		auto add= func(edge, v, dis, box, i, node);
		ret += add;
		if (add > 1) {
			box[i].push_back(node);
		}
	}
	if (ret + 1 < M) {
		box[p].push_back(node);
	}
	return ret;
}

void Solve() {
	cin >> N;
	vector<int>v(N);
	vector<int>dis(N, MOD);
	queue<int>Q;
	vector<int>ans(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		M += v[i];
		if (v[i] == 1) {
			ans[i] = 1;
			Q.push(i);
			dis[i] = 0;
		}
	}
	vector<vector<int>>edge(N);
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		L--, R--;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		for (auto i : edge[cn]) {
			if (dis[i] > dis[cn] + 1) {
				dis[i] = dis[cn] + 1;
				Q.push(i);
				if (dis[i] == 1) {
					ans[i] = 1;
				}
			}
		}
	}
	vector<vector<int>>box(N);
	func(edge, v, dis, box);
	for (int i = 0; i < N; i++) {
		if (ans[i] == 1) {
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		for (auto i : box[cn]) {
			if (ans[i] == 0) {
				ans[i] = 1;
				Q.push(i);
			}
		}
	}
	for (auto i : ans)cout << i << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//cin >> T;
	while (T--) {
		Solve();
	}
}