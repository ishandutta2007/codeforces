#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iomanip>

using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		vector <int> a(n);
		map <int, int> cnt;
		int mx = 0;
		for (auto& x : a) {
			cin >> x;
			cnt[x]++;
			mx = max(mx, cnt[x]);
		}
		if (2 * mx - n >= 0) cout << 2 * mx - n;
		else cout << n % 2;
		cout << '\n';
	}
	return 0;
}