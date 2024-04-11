#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <queue>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n, t, k; cin >> n >> t >> k;
	int l = 0, r = n;
	while (l + 1 < r) {
		int m = (l + r) / 2;
		cout << "? 1 " << m << endl;
		int x; cin >> x;
		if (m - x >= k) r = m;
		else l = m;
	}
	cout << "! " << r << endl;
	return 0;
}