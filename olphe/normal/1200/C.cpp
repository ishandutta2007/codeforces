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

	cin >> N >> M >> K;
	L = gcd(N, M);
	H = N / L;
	W = M / L;
	while (K--) {
		long long int a, b, c, d;
		cin >> a >> b >> c >> d;
		b--;
		d--;
		//cout << H << " " << W << endl;
		if (a == 1)b /= H;
		else b /= W;
		if (c == 1)d /= H;
		else d /= W;
		//cout << a << " " << b << " " << c << " " << d << endl;
		if (b == d) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}