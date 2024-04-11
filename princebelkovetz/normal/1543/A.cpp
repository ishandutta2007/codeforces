#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int a, b; cin >> a >> b;
		if (a == b) cout << "0 0";
		else {
			if (a < b) swap(a, b);
			int d = a - b;
			cout << d << ' ' << min(a % d, d - a % d);
		}
		cout << '\n';
	}
	return 0;
}