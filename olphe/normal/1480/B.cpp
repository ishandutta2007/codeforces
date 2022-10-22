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
	cin >> L >> R >> N;
	vector<long long int>a(N);
	vector<long long int>b(N);
	long long int damage = 0;
	long long int mx = -MOD;
	for (auto& i : a)cin >> i;
	for (auto& i : b)cin >> i;
	for (int i = 0; i < N; i++) {
		long long int num = b[i] / L + !!(b[i] % L);
		damage += num * a[i];
		mx = max(mx, a[i]);
	}
	if (damage - mx < R)cout << "YES\n";
	else cout << "NO\n";
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