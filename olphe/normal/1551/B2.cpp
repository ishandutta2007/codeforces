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

void Solve() {
	cin >> N >> K;
	vector<int>v;
	vector<vector<int>>box(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> M;
		box[M].push_back(i);
	}
	vector<int>ans(N);
	for (int i = 1; i <= N; i++) {
		if (box[i].size() >= K) {
			for (int j = 0; j < K; j++) {
				v.push_back(box[i][j]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (box[i].size() < K) {
			for (int j = 0; j < box[i].size(); j++) {
				v.push_back(box[i][j]);
			}
		}
	}
	for (int i = 0; i < v.size()/K*K; i++) {
		ans[v[i]] = i % K + 1;
	}
	for (auto i : ans)cout << i << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}