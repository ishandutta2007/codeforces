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
	cin >> N;
	vector<vector<long long>>v(N);
	for (auto& i : v) {
		cin >> K;
		i.resize(K);
		for (auto& j : i)cin >> j;
	}
	cin >> M;
	vector<vector<int>>w(M, vector<int>(N));
	set<vector<int>>vs;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> w[i][j];
		}
		vs.insert(w[i]);
	}
	long long score = -1;
	vector<int>ans;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (w[i][j] == 1)continue;
			w[i][j]--;
			if (vs.find(w[i]) == vs.end()) {
				long long c = 0;
				for (int k = 0; k < N; k++) {
					c += v[k][w[i][k]-1];
				}
				if (c > score) {
					score = c;
					ans = w[i];
				}
			}
			w[i][j]++;
		}
	}
	vector<int>box(N);
	for (int i = 0; i < N; i++) {
		box[i] = v[i].size();
	}
	if (vs.find(box) == vs.end()) {
		ans = box;
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