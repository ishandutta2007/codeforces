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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int x, y;
	int a = 0;
	int b = 0;
	for (int i = 0; i < N; i++) {
		cin  >> x >> y;
		if (x < 0) {
			a++;
		}
		else {
			b++;
		}
	}
	if (a < 2 || b < 2) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
	return 0;
}