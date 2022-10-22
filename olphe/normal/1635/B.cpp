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
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	vector<int>box;
	for (int i = 1; i + 1 < N; i++) {
		if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
			box.push_back(i);
		}
	}
	int ans = 0;
	for (int i = 0; i < box.size(); i++) {
		if (i + 1 < box.size() && box[i] + 2 == box[i + 1]) {
			ans++;
			v[box[i] + 1] = max(v[box[i]], v[box[i + 1]]);
			i++;
		}
		else {
			ans++;
			v[box[i]] = max(v[box[i] - 1], v[box[i] + 1]);
		}
	}
	cout << ans << endl;
	for (auto i : v)cout << i << " ";
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