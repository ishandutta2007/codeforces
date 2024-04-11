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
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const ld eps = 1e-8;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	string s; cin >> s;
	map <char, int> let;
	map <string, int> ab;
	for (auto x : s) {
		for (auto y : let) {
			string cur = "";
			cur += y.first; cur += x;
			ab[cur] += y.second;
		}
		let[x]++;
	}
	int ans = 0;
	for (auto x : ab) ans = max(ans, x.second);
	for (auto x : let) ans = max(ans, x.second);
	cout << ans << endl;
}