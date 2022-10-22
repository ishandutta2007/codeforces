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
#include "iomanip"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	cout << N * 3 / 2 << endl;
	for (int i = 2; i <= N; i += 2) {
		cout << i << " ";
	}
	for (int i = 1; i <= N; i += 2) {
		cout << i << " ";
	}
	for (int i = 2; i <= N; i += 2) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}