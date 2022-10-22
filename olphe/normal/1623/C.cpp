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
	vector<long long>v(N);
	for (auto& i : v)cin >> i;
	long long ok = 0, ng = 1111111111;
	while (ng - ok > 1) {
		int mid = (ng + ok) / 2;
		auto w = v;
		for (int i = N - 1; i >= 2; i--) {
			long long amari = max(0LL, min(v[i], w[i] - mid));
			amari = amari / 3;
			w[i] -= amari * 3;
			w[i - 1] += amari;
			w[i - 2] += amari * 2;
		}
		if (*min_element(w.begin(), w.end()) >= mid)ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
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