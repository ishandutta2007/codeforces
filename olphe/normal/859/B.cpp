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
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;
const long double PI = 3.1415926535897932384626433;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		if (i*i >= N) {
			if (i*(i - 1) >= N) {
				cout << 4 * i - 2 << endl;
			}
			else {
				cout << 4 * i << endl;
			}
			return 0;
		}
	}
	return 0;
}