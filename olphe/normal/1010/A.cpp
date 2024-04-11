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
const long double EPS = 1e-8;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<long double >a(N);
	vector<long double >b(N);
	for (int i = 0; i < N; i++)cin >> a[i];
	for (int i = 0; i < N; i++)cin >> b[i];
	long double l = M;
	long double r = MOD * 2;
	for (int i = 0; i < 100; i++) {
		long double mid = (l + r) / 2;
		long double sum = mid;
		for (int j = 0; j < N; j++) {
			sum -= sum / a[j];
			sum -= sum / b[(j + 1) % N];
		}
		if (sum >= M) {
			r = mid;
		}
		else l = mid;
	}
	if (abs(l - MOD * 2) <= EPS) {
		cout << -1 << endl;
		return 0;
	}
	cout << setprecision(15) << l - M << endl;
	return 0;
}