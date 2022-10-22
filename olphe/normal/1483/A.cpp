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
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N >> M;
	vector<vector<int>>box(M);
	vector<int>num(N + 1);
	vector<int>ans;
	for (auto& i : box) {
		cin >> K;
		i.resize(K);
		for (auto& j : i)cin >> j;
		ans.push_back(i.front());
		num[i.front()]++;
	}
	int idx = -1;
	for (int i = 0; i <= N; i++) {
		if (num[i] > (M + 1) / 2) {
			idx = i;
		}
	}
	for (int i = 0; i < M; i++) {
		if (ans[i] == idx) {
			if (box[i].size() > 1 && num[idx] > (M + 1) / 2) {
				ans[i] = box[i][1];
				num[idx]--;
			}
		}
	}
	if (idx>=0&&num[idx] > (M + 1) / 2) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (auto i : ans)cout << i << " ";
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