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
	vector<long long int>v(N*2);
	for (auto& i : v)cin >> i;
	sort(v.begin(), v.end());
	if (v[0] == 0) {
		cout << "NO\n";
		return;
	}
	vector<long long int>box;
	box.push_back(0);
	for (int i = 0; i < N * 2; i += 2) {
		if (v[i] != v[i + 1]) {
			cout << "NO\n";
			return ;
		}
		if (v[i] & 1) {
			cout << "NO\n";
			return;
		}
		if (i) {
			if ((v[i] - v[i - 2]) % i) {
				cout << "NO\n";
				return;
			}
			if (v[i] == v[i - 2]) {
				cout << "NO\n";
				return;
			}
			box.push_back((v[i] - v[i - 2]) / i);
		}
	}
	long long int sum = 0;
	for (int i = 1; i < box.size(); i++) {
		box[i] += box[i - 1];
	}
	for (int i = 0; i < box.size(); i++) {
		sum += box.back() + box[i];
		sum += box.back() - box[i];
		if (sum >= v.back())sum = v.back();
	}
	if (sum < v.back() && (v.back() - sum) % (2 * N) == 0) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
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