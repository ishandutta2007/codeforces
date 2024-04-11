#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 1e5 + 2, bb = 32;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin >> n >> k;

	vector <int> a(n), b(n), arr(n);

	int a1 = (1 << bb) - 1, b1 = 0, c1 = 0;

	for (int i = 1; i < n; ++i) {
		cout << "or " << 1 << ' ' << i + 1 << endl;
		cin >> a[i];
		cout << "and " << 1 << ' ' << i + 1 << endl;
		cin >> b[i];
		a1 &= a[i], b1 |= b[i];
	}

	cout << "and 2 3" << endl;
	cin >> c1;

	for (int i = 0; i < bb; ++i) {
		if ((b1 >> i) & 1) 
			arr[0] += (1 << i);
		else if ((a1 >> i) & 1) {
			if ((c1 >> i) & 1 ^ 1)
				arr[0] += (1 << i);
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < bb; ++j) {
			if ((b[i] >> j) & 1) arr[i] += (1 << j);
			else if ((arr[0] >> j) & 1 ^ 1) {
				if ((a[i] >> j) & 1) arr[i] += (1 << j);
			}
		}
	}

	sort(arr.begin(), arr.end());

	cout << "finish " << arr[--k] << endl;

	return 0;
}