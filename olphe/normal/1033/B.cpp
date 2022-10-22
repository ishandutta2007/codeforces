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

	cin >> N;
	for (int loop = 0; loop < N; loop++) {
		cin >> L >> R;
		if (L - R > 1) {
			cout << "NO\n";
			continue;
		}
		M = L + R;
		bool flag = true;
		for (long long int j = 2; j*j <= M; j++) {
			if (M%j)continue;
			flag = false;
		}
		if (flag) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}