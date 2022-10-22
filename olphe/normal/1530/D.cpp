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
	vector<int>v(N);
	for (auto& i : v) {
		cin >> i;
		i--;
	}
	vector<int>used(N);
	int score = 0;
	vector<int>ans(N, -1);
	for (int i = 0; i < N; i++) {
		if (used[v[i]])continue;
		used[v[i]] = 1;
		ans[i] = v[i];
		score++;
	}
	int idx = 0;
	for (int i = 0; i < N; i++) {
		if (ans[i] != -1)continue;
		while (used[idx] == 1) {
			idx++;
		}
		ans[i] = idx;
		used[idx] = 1;
	}
	vector<int>same;
	for (int i = 0; i < N; i++) {
		if (ans[i] == i)same.push_back(i);
	}
	if (same.size()) {
		if (same.size() == 1) {
			for (int i = 0; i < N; i++) {
				if (ans[i] == v[same[0]]) {
					swap(ans[i], ans[same[0]]);
					break;
				}
			}
		}
		else {
			same.push_back(same.front());
			for (int i = 0; i+1 < same.size(); i++) {
				ans[same[i]] = same[i + 1];
			}
		}
	}
	cout << score << endl;
	for (auto i : ans)cout << i + 1 << " ";
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