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

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 1e-8;

long long int N, M, K, H, W, L, R;

int gcd(int a, int b) {
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

	cin >> N >> K;
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		v[i] %= K;
	}
	int box = v[0];
	for (int i = 1; i < N; i++) {
		box = gcd(box, v[i]);
	}
	box = gcd(box, K);
	cout << K / box << endl;
	for (int i = 0; i < K; i += box) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}