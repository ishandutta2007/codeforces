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

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> M;
		if (M & 1) {
			cout << (M + 1) / 2 << endl;
		}
		else {
			M = N - M / 2;
			while (M % 2 == 0) {
				M /= 2;
			}
			M++;
			M /= 2;
			cout << N + 1 - M << endl;
		}
	}
	return 0;
}