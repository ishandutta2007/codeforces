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
	vector<long long int>a(N);
	vector<long long int>b(N);
	vector<long long int>c(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i] >> b[i];
		c[i] = a[i] - b[i];
	}
	sort(c.begin(), c.end());
	reverse(c.begin(), c.end());
	K = accumulate(a.begin(), a.end(), (long long int)0);
	if (K <= M) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		K -= c[i];
		if (K <= M) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}