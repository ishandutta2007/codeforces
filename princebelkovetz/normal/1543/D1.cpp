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
		int n, k; cin >> n >> k;
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			cout << (i ^ cur) << endl;
			int res; cin >> res;
			cur = i;
			if (res) break;
		}
	}
	return 0;
}