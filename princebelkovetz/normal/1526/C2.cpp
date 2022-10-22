#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <string>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

constexpr int inf = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(8);
	int n; cin >> n;
	multiset <int> a;
	int cur = 0, ans = n;
	while (n --> 0) {
		int x; cin >> x;
		a.insert(x);
		cur += x;
		if (cur < 0) {
			cur -= *a.begin();
			a.erase(a.begin());
			ans--;
		}
	}
	cout << ans << '\n';
}