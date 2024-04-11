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
const int mod = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	string s; cin >> s;
	int n = s.size();
	int cur = 0, now = 20;
	while (cur * now < n) ++cur;
	while (cur * now >= n) --now;
	++now;
	cout << cur << ' ' << now << '\n';
		int st = cur * now - n;
	int m = (st + cur - 1) / cur;
	int ind = 0;
	for (int i = 0; i < cur; ++i) {
		int len = 0;
		for (int j = 0; j < min(st, m); ++j, len++) {
			cout << "*";
		}
		st -= min(st, m);
		while (len != now) {
			++len;
			cout << s[ind++];
		}
		cout << '\n';
	}
	return 0;
}