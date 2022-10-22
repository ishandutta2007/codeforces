#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		map <int, int> a;
		int mx = 0, cnt = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x; a[x]++;
			if (a[x] == mx) cnt++;
			if (a[x] > mx) {
				mx = a[x];
				cnt = 1;
			}
		}
		int ans = n - cnt;
		cout << ans / (mx - 1) - 1 << "\n";
	}
}