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

	cin >> N;
	for (int i = 19;; i++) {
		int box = i;
		int bag = 0;
		while (box) {
			bag += box % 10;
			box /= 10;
		}
		if (bag == 10) {
			M++;
			if (N == M) {
				cout << i << endl;
				return 0;
			}
		}
	}
	return 0;
}