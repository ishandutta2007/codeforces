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



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	if (N > M)swap(N, M);
	if (N == 1) {
		int box = M % 6;
		box = max(0, box - 3);
		cout << box * 2 + (M / 6 * 6) << endl;
		return 0;
	}
	if (N == 2) {
		if (M == 2) {
			cout << 0 << endl;
			return 0;
		}
		if (M == 3) {
			cout << 4 << endl;
			return 0;
		}
		if (M == 7) {
			cout << 12 << endl;
			return 0;
		}
		long long int box = M % 6;
		long long int bag = 2 * (M / 6 * 6);
		if (box == 1)bag += 2;
		if (box == 2)bag += 4;
		if (box == 3)bag += 6;
		if (box == 4)bag += 8;
		if (box == 5)bag += 10;
		cout << bag << endl;
		return 0;
	}
	cout << N * M - ((N & 1)&(M & 1)) << endl;
	return 0;
}