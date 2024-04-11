#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <queue>
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int inf = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		set <int> a;
		for (int i = 0, x; i < n; ++i) {
			cin >> x;
			a.insert(x);
		}
		cout << (a.size() == n ? "NO" : "YES");
		cout << '\n';
	}
	return 0;
}