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

const int mod = 1e9 + 7, N = 3e6 + 5, bb = 32;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int tt; cin >> tt;

	while (tt --> 0) {
		int n; cin >> n;
		string s; cin >> s;
		for (auto& x : s) cout << (x == 'U' or x == 'D' ? (char)('D' + 'U' - x) : x);
		cout << '\n';
	}
	return 0;
}