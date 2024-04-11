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
#include "iomanip"
#include "cmath"
#include "random"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	if (K == 1) {
		cout << N << endl;
	}
	else {
		long long int box = 1;
		while (box <= N) {
			box *= 2;
		}
		cout << box - 1 << endl;
	}
	return 0;
}