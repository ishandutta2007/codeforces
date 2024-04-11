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

const int mod = 1e9 + 7, N = 1e5 + 2;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt; cin >> tt;
	while (tt--) {
		int a, b; cin >> a >> b;

		if ((a - b) & 1) cout << -1;
		else if (a == b and a == 0) cout << 0;
		else if (a == b) cout << 1;
		else if (a == -b) cout << 1;
		else cout << 2;
		cout << '\n';

	}

	return 0;
}