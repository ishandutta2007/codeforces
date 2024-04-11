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
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<int>used(N);
	vector<int>ans(N);
	for (int i = 0; i < N; i++) {
		if (used[i])continue;
		vector<int>box;
		while (1) {
			cout << "? " << i + 1 << endl;
			cin >> K;
			if (box.size() && box.front() == K) {
				box.push_back(K);
				break;
			}
			box.push_back(K);
		}
		for (auto j : box) {
			used[j - 1] = 1;
		}
		for (int i = 1; i < box.size(); i++) {
			ans[box[i - 1] - 1] = box[i];
		}
	}
	cout << "!";
	for (auto i : ans)cout << " " << i;
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