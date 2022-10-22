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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	if (N > 32) {
		cout << M << endl;
		return 0;
	}
	long long int box = 1;
	for (int i = 0; i < N; i++) {
		box *= 2;
	}
	cout << M%box << endl;
	return 0;
}