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

const int mod = 1e9 + 7, N = 5e5 + 3;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n);
		int id = -1, sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			sum += a[i];
			if (a[i] & 1) id = i;
		}
		for (int i = 2; i * i <= sum; ++i)
			if (sum % i == 0) id = -1;
		cout << n - (id != -1) << '\n';
		for (int i = 1; i <= n; ++i)
			if (i != id + 1) cout << i << ' ';
		
		cout << '\n';
	}

	return 0;
}