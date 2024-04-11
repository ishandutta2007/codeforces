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

void Calculate_Depth(vector<vector<int>>& edge, vector<int>& depth, int stnode) {
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
	vector<int>a(N - 1);
	vector<int>b(N - 1);
	vector<vector<int>>edge(N);
	for (int i = 0; i < N-1; i++) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
		edge[a[i]].push_back(b[i]);
		edge[b[i]].push_back(a[i]);
	}
	for (auto i : edge) {
		if (i.size() > 2) {
			cout << -1 << endl;
			return;
		}
	}
	vector<int>dis(N, MOD);
	int st = 0;
	for (int i = 0; i < N; i++) {
		if (edge[i].size() == 1) {
			Calculate_Depth(edge, dis, i);
			st = i;
			break;
		}
	}
	for (int i = 0; i < N - 1; i++) {
		//cout << min(dis[a[i]], dis[b[i]]) << endl;
		if (min(dis[a[i]], dis[b[i]]) & 1)cout << 3 << " ";
		else cout << 2 << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}