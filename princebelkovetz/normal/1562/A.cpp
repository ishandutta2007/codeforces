#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>

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
		int l = (b - a + 1) & 1;
		cout << b % max(b / 2 + 1, a) << '\n';
	}
	
	return 0;
}