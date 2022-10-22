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

void Solve() {
	cin >> N;
	map<int, int>mp;
	for (int i = 0; i < N; i++) {
		cin >> K;
		mp[K]++;
	}
	vector<int>box;
	box.push_back(0);
	for (auto i : mp)box.push_back(i.second);
	for (int i = 1; i < box.size(); i++) {
		box[i] += box[i - 1];
	}
	vector<int>add(N + 1);
	add[0] = 1;
	for (int i = 1; i <= N; i++) {
		add[i] = add[i - 1] - 1;
		if (add[i] < 0) {
			add[i] = i - 2;
		}
	}
	int ans = add[N] + 2;
	vector<int>idx(20);
	for (int i = 0; i < box.size(); i++) {
		for (int j = 0; j < 20; j++) {
			if (box[i] <= (1 << j)) {
				idx[j] = i;
				ans = min(ans, 1 + add[box[i]] + add[N - box[i]]);
			}
		}
	}
	for (int i = 1; i < box.size(); i++) {
		for (int j = 0; j < 20; j++) {
			while (idx[j] + 1 < box.size() && box[idx[j] + 1] - box[i] <= (1 << j))idx[j]++;
			ans = min(ans, add[box[i]] + add[box[idx[j]] - box[i]] + add[N - box[idx[j]]]);
		}
	}
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