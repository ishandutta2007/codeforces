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
	L = 0, R = (N + 1) / 2;
	while (R - L > 1) {
		int mid = (R + L) / 2;
		bool flag = true;
		for (int i = 0; i < mid; i++) {
			if (v[i] >= v[N - mid + i - 1])flag = false;
		}
		if (flag)L = mid;
		else R = mid;
	}
	vector<int>w(N);
	for (int i = 0; i < L; i++) {
		w[i * 2 + 1] = v[i];
	}
	for (int i = N-L-1; i < N; i++) {
		w[(i - N+L+1) * 2] = v[i];
	}
	for (int i = L; i < N-L-1; i++) {
		w[i+L+1] = v[i];
	}
	cout << L << endl;
	for (auto i : w)cout << i << " ";
	cout << endl;
}