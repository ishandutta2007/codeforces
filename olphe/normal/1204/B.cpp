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
#include "functional"

using namespace std;

//constexpr long long int MOD = 1000000007;
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> L >> R;
	vector<int>v(N, 1);
	for (int i = 1; i < L; i++) {
		v[i] = 1 << i;
	}
	vector<int>w(N, 1 << (R - 1));
	for (int i = 1; i < R; i++) {
		w[i] = 1 << (i - 1);
	}
	cout << accumulate(v.begin(), v.end(), 0) << " " << accumulate(w.begin(), w.end(), 0) << endl;
}