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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>v(N + 1);
	for (int i = 1; i <= (N + 1) / 2; i++) {
		cin >> v[i];
	}
	cin >> v[(N + 3) / 2];
	for (int i = (N + 5) / 2; i <= N; i++) {
		v[i] = v[i - 1];
	}
	long long int sum = accumulate(v.begin(), v.end(), 0LL);
	if (sum > 0) {
		cout << N << endl;
		return 0;
	}
	M = v.back();
	for (int i = 1; i <= N; i++) {
		v[i] += v[i - 1];
	}
	//cout << v.back() << endl;
	long long int mx = v[0];
	for (int i = 0; i <= N / 2; i++) {
	//	cout << mx << endl;
		if (mx < v.back()) {
			cout << N - i  << endl;
			return 0;
		}
		mx += M;
		mx = max(mx, v[i + 1]);
	}
	cout<< -1 << endl;
}