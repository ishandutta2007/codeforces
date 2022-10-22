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

long long int gcd(long long int a, long long int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> L >> R;

	for (long long int i = L; i <= R; i++) {
		for (long long int j = i + 1; j <= R; j++) {
			for (long long int k = j + 1; k <= R; k++) {
				//cout << i << " " << j << " " << k << endl;
				//cout << gcd(i, j) << " " << gcd(j, k) << " " << gcd(i, k) << endl;
				if (gcd(i, j) == 1 && gcd(j, k) == 1 && gcd(i, k) != 1) {
					cout << i << " " << j << " " << k << endl;
					return 0;
				}
			}
		}
	}
	cout << "-1\n";
}