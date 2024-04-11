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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

long long int gcd(long long int a, long long int b) {
	if (a < b)swap(a, b);
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
	if ((N*M * 2) % K) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	cout << "0 0\n";
	long long int bag = gcd(N * 2, K);
	if (bag != 1) {
		N = N * 2 / bag;
		K *= 2;
	}
	K /= bag;
//	cout << K << endl;
	bag = gcd(M * 2, K);
	if (bag != 1) {
		M = M * 2 / bag;
	}
	cout << N << " 0\n";
	cout << "0 " << M << endl;

	return 0;
}