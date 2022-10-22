#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long
#define ld long double

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n, k; cin >> n >> k;
	map <int, int> bits;
	int cur = 0, cnt = 0;
	while (n) {
		if (n & 1) {
			bits[cur]++;
			cnt++;
		}
		n >>= 1;
		cur++;
	}
	if (cnt > k) {
		cout << "No\n";
		return 0;
	}
	for (int i = 60; i >= -1e18; --i) {
		if (bits.find(i) == bits.end()) continue;
		if (k - cnt < bits[i]) break;
		while (bits[i] > 0 and cnt < k) {
			cnt++;
			bits[i]--;
			bits[i - 1] += 2;
		}
	}
	while (cnt < k) {
		int ok = bits.begin()->first;
		bits[ok]--;
		bits[ok - 1] += 2;
		cnt++;
	}
	cout << "Yes\n";
	for (auto it = --bits.end(); ; it--) {
		while (it->second > 0) {
			cout << it->first << ' ';
			it->second--;
		}
		if (it == bits.begin()) break;
	}
	cout << '\n';
	return 0;
}