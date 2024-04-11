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

	cin >> N;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	if (N > 1) {
		cout << 1 << " " << N - 1 << endl;
		for (int i = 0; i < N - 1; i++) {
			cout << (v[i] + MOD * N) % (N)*((N - 1)) << " ";
			v[i] += (v[i] + MOD * N) % (N)*((N - 1));
		}
		cout << endl;
		cout << N << " " << N << endl;
		cout << (v.back() + MOD * N) % N*(-1) << endl;
		v.back() += (v.back() + MOD * N) % N*-1;
		cout << 1 << " " << N << endl;
		for (auto i : v)cout << -i << " ";
		cout << endl;
	}
	else {
		for (int i = 0; i < 3; i++) {
			cout << "1 1" << endl;
			cout << -v[0] << endl;
			v[0] = 0;
		}
	}
}