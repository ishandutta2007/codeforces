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
#include "cmath"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	vector<long long int>num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	num.push_back(-MOD);
	sort(num.begin(), num.end());
	long long int ans = 0;
	for (int i = 1; i <= N; i++) {
		long long int l = (num[i] / M)*M + K*M;
		if (num[i] % M == 0) {
			l -= M;
		}
		long long int r = l + M - 1;
		L = 0;
		R = N + 1;
		while (R - L > 1) {
			int mid = (R + L + 1) / 2;
			if (num[mid] < num[i]) {
				L = mid;
			}
			else {
				R = mid;
			}
		}
		long long int lft = L;
		if (r >= num[i]) {
			L = 0;
			R = N + 1;
			while (R - L > 1) {
				int mid = (R + L + 1) / 2;
				if (num[mid] <= r) {
					L = mid;
				}
				else {
					R = mid;
				}
			}
			ans += L;
			L = 0;
			R = N + 1;
			while (R - L > 1) {
				int mid = (R + L + 1) / 2;
				if (num[mid] < l) {
					L = mid;
				}
				else {
					R = mid;
				}
			}
			ans -= max(L, lft);
		}
	}
	cout << ans << endl;
	return 0;
}