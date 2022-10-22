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
#define ull unsigned long long
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
		int n, x, y; 
		cin >> n >> x >> y;
		int d = 1, last = 1e9;
		for (int i = 1; i <= 50; ++i) {
			if ((y - x) % i or (y - x) / i + 1 > n) continue;
			int cur = (y - x) / i + 1;
			cur += min(n - cur, (x - 1) / i);
			if (y + i * (n - cur) < last) {
				d = i;
				last = y + i * (n - cur);
			}
		}
		while (n--) {
			cout << last << ' ';
			last -= d;
		}
		cout << '\n';
	}
	
}