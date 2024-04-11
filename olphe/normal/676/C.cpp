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

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	string s;
	cin >> s;
	s = 'x' + s;
	N++;
	vector<int>a(N);
	vector<int>b(N);
	for (int i = 1; i < N; i++) {
		a[i] = (s[i] == 'a');
		b[i] = (s[i] == 'b');
		a[i] += a[i - 1];
		b[i] += b[i - 1];
	}
	long long int ans = 0;
	for (int i = 0; i < N; i++) {
		L = i;
		R = N;
		while (R - L > 1) {
			int mid = (R + L + 1) / 2;
			if (a[mid] - a[i] <= K) {
				L = mid;
			}
			else {
				R = mid;
			}
		}
		ans = max(ans, L - i);
		L = i;
		R = N;
		while (R - L > 1) {
			int mid = (R + L + 1) / 2;
			if (b[mid] - b[i] <= K) {
				L = mid;
			}
			else {
				R = mid;
			}
		}
		ans = max(ans, L - i);
	}
	cout << ans << endl;
	return 0;
}