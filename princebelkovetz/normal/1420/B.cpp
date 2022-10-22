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
#include <locale>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
signed main() {
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			while (x) {
				a[i]++;
				x /= 2;
			}
		}
		map <int, int> cnt;
		for (auto x : a) cnt[x]++;
		int ans = 0;
		for (auto x : cnt)
			ans += x.second * (x.second - 1) / 2;
		cout << ans << '\n';
	}
	return 0;
}