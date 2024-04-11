#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <iomanip>

using namespace std;

#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int a, b; cin >> a >> b;
		cout << a * b / 3 + !!(a * b % 3) << '\n';
	}
}