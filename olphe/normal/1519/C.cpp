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
constexpr double EPS = 1e-5;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<vector<long long int>>box(N + 1);
	vector<int>a(N);
	vector<int>b(N);
	for (auto& i : a)cin >> i;
	for (auto& i : b)cin >> i;
	for (int i = 0; i < N; i++) {
		box[a[i]].push_back(b[i]);
	}
	for (int i = 0; i <= N; i++) {
		sort(box[i].rbegin(), box[i].rend());
		box[i].insert(box[i].begin(), 0);
	}
	vector<long long int>ans(N + 1);
	for (int i = 0; i <= N; i++) {
		for (int j = 1; j < box[i].size(); j++) {
			box[i][j] += box[i][j - 1];
			for (int k = 1; k * k <= j; k++) {
				if (j % k)continue;
				ans[k] += box[i][j] - box[i][j-k];
				if (j / k != k) {
					ans[j / k] += box[i][j] - box[i][j-j / k];
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
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