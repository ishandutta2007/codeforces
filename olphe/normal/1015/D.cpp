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
const long double EPS = 1e-9;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	if (M > K || (N - 1)*M < K) {
		cout << "NO\n";
		return 0;
	}
	int p = 1;
	cout << "YES\n";
	for (int i = 0; i < M; i++) {
		if (i < K%M) {
			if (i % 2 == 0) {
				p += K / M + 1;
			}
			else {
				p -= K / M + 1;
			}
		}
		else {
			if (i % 2 == 0) {
				p += K / M;
			}
			else {
				p -= K / M;
			}
		}
		cout << p << " ";
	}
	cout << endl;
	return 0;
}