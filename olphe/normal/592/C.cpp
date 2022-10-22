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
#include "ctime"

using namespace std;

//const long long int MOD = 1000000007;
const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
unsigned long long int N, M, K, H, W, L, R;

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
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
	unsigned long long int box = gcd(M, K);
	if (M / box > ULLONG_MAX / K) {
		L = min({ N,M - 1, K - 1 });
	}
	else {
		R = M / box * K;
		L = (min({ N,M - 1,K - 1 })+1)*(N / R) + min({ N%R,M-1,K-1 });
	}
	box = gcd(L, N);
	L /= box;
	N /= box;
	cout << L << "/" << N << endl;
	return 0;
}