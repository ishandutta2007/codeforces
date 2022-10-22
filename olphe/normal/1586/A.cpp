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

//constexpr long long MOD = 1000000007;
constexpr long long MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int p[33333];

void Solve() {
	cin >> N;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	int sum = accumulate(v.begin(), v.end(), 0);
	if (p[sum] != sum) {
		cout << N << endl;
		for (int i = 1; i <= N; i++) {
			cout << i << " ";
		}
		cout << endl;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (p[sum - v[i]] != sum - v[i]) {
				cout << N - 1 << endl;
				for (int j = 1; j <= N; j++) {
					if (i+1 == j)continue;
					cout << j << " ";
				}
				cout << endl;
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i < 33333; i++) {
		if (p[i])continue;
		p[i] = i;
		for (int j = i * 2; j < 33333; j += i) {
			p[j] = i;
		}
	}
	cin >> T;
	while (T--) {
		Solve();
	}
}