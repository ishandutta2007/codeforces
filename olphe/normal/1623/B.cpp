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
	vector<int>l(N);
	vector<int>r(N);
	for (int i = 0; i < N; i++) {
		cin >> l[i] >> r[i];
	}
	for (int i = 0; i < N; i++) {
		if (l[i] == r[i]) {
			cout << l[i] << " " << r[i] << " " << l[i] << endl;
			continue;
		}
		int ans = -1;
		for (int j = 0; j < N; j++) {
			if (l[j] == l[i] + 1 && r[j] == r[i]) {
				ans = l[i];
				break;
			}
			if (l[i] == l[j] && r[j]<r[i]) {
				ans = max(ans, r[j] + 1);
			}
		}
		cout << l[i] << " " << r[i] << " " << ans << endl;
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