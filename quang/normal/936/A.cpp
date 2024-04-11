#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long)1e18 * 5;

long long k, d, t;	

long long get(long long u) {
	long long v = u / d;
	long long res = k * v + (d - k) * v / 2;
	u %= d;
	// cout << res << " " << u << endl;
	if (u <= k) {
		res += u;
	} else {
		res += k;
		res += (u - k) / 2;
	}
	return res;
}

int main() {
	cin >> k >> d >> t;
	d *= (k - 1) / d + 1;
	k <<= 1ll;
	d <<= 1ll;
	t <<= 1ll;
	long long low = -1, high = INF;
	while (high - low > 1) {
		long long mid = (low + high) >> 1ll;
		if (get(mid) >= t) {
			high = mid;
		} else {
			low = mid;
		}
		// cout << high << " " << low << endl;
	}
	// cout << get(high) << endl;
	cout << (high >> 1ll) << "." << (high % 2 ? 5 : 0) << "\n";
	return 0;
}