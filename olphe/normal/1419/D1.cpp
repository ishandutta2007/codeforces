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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	for (auto &i : v) {
		cin >> i;
	}
	sort(v.begin(), v.end());
	vector<int>w(N);
	w[0] = v[N - 2];
	w[N - 1] = v[N - 1];
	for (int i = 1; i < N - 1; i++) {
		if (i & 1) {
			w[i] = v[i / 2];
		}
		else {
			w[i] = v[i / 2 + N / 2 - 2 + (N & 1)];
		}
	}
	for (int i = 1; i < N - 1; i++) {
		if (w[i] < w[i - 1] && w[i] < w[i + 1])M++;
	}
	cout << M << endl;
	for (auto i : w)cout << i << " ";
	cout << endl;
}