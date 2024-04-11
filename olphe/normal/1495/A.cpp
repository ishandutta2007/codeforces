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
	cin >> N;
	vector<long double>a;
	vector<long double>b;
	for (int i = 0; i < N*2; i++) {
		cin >> L >> R;
		if (L) {
			a.push_back(L*L);
		}
		else {
			b.push_back(R*R);
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	long double ans = 0;
	for (int i = 0; i < N; i++) {
		ans += sqrtl(a[i] + b[i]);
	}
	cout << fixed << setprecision(20) << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}