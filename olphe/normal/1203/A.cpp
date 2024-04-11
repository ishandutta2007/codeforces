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

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N;
		vector<int>v(N);
		for (auto &i : v)cin >> i;
		auto w = v;
		for (int i = 1; i < N; i++) {
			w[i] = v[i] - v[i - 1] + N;
			w[i] %= N;
		}
		w[0] = v[0] - v.back() + N;
		w[0] %= N;
		L = *min_element(w.begin(), w.end());
		R = *max_element(w.begin(), w.end());
		if (L == R && (L == 1 || L == N - 1))cout << "YES\n";
		else cout << "NO\n";
	}
}