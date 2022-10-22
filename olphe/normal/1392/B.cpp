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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N >> K;
		vector<long long int>v(N);
		for (auto &i : v)cin >> i;
		vector<long long int>w(N);
		M = *max_element(v.begin(), v.end());
		for (int i = 0; i < N; i++) {
			w[i] = M - v[i];
		}
		M = *max_element(w.begin(), w.end());
		vector<long long int>x(N);
		for (int i = 0; i < N; i++) {
			x[i] = M - w[i];
		}
		if (K & 1) {
			for (auto i : w)cout << i << " ";
			cout << endl;
		}
		else {
			for (auto i : x)cout << i << " ";
			cout << endl;
		}
	}
}