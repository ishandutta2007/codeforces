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

int ans = 0;
int num = 0;

int func(vector<vector<int>>& edge, int node = 0, int p = -1) {
	bool leaf = true;
	map<int, int>mp;
	for (auto i : edge[node]) {
		if (i == p)continue;
		leaf = false;
		int box = func(edge, i, node);
		mp[box]++;
	}
	if (node == 0) {
		ans += mp[0];
		if (num&&mp[0])ans--;
		return 0;
	}
	if (leaf) {
		return 0;
	}
	if (mp[0]) {
	//	cout <<"node " << node << endl;
		if (num) {
			ans--;
		}
		ans += mp[0];
		num++;
		return -1;
	}
	else {
		return 0;
	}
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
	ans = 0;
	num = 0;
	func(edge);
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}