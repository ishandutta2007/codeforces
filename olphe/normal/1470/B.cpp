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

long long int gcd(long long int a, long long int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int d[1000001];

void Solve() {
	cin >> N;
	map<int, int>mp;
	for (int i = 0; i < N; i++) {
		cin >> K;
		while (d[K] != K) {
			K = d[K];
		}
		mp[K]++;
	}
	int one = 0;
	int two = 0;
	for (auto i : mp) {
		one = max(one, i.second);
		if (i.first == 1) {
			two += i.second;
		}
		else if (i.second % 2 == 0) {
			two += i.second;
		}
	}
	cin >> K;
	while (K--) {
		cin >> M;
		if (M == 0) {
			cout << one << "\n";
		}
		else {
			cout << max(one, two) << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	for (int i = 1; i <= 1000000; i++) {
		d[i] = i;
	}
	for (int i = 1; i*i <= 1000000; i++) {
		for (int j = i * i; j <= 1000000; j += i * i) {
			d[j] = j / (i * i);
		}
	}
	while (T--) {
		Solve();
	}
}