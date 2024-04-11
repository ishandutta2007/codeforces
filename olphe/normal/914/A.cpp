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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int ans = -10000000;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a != (int)sqrt(a)*(int)sqrt(a)) {
			ans = max(ans, a);
		}
	}
	cout << ans << endl;
	return 0;
}