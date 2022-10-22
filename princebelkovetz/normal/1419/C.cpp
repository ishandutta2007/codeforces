#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt--) {
		int n, y; cin >> n >> y;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		int cnt = 0, ok = 0;
		for (auto x : a) 
			cnt += (x == y), ok += x - y;
		if (cnt == n) cout << 0;
		else if (cnt >= 1 or ok == 0) cout << 1;
		else cout << 2;
		cout << '\n';
	}

	return 0;
}