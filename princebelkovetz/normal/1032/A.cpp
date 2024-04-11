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
	int n, k; cin >> n >> k;
	map <int, int> ok;
	int mx = 0;
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		ok[x]++;
		mx = max(mx, ok[x]);
	}
	cout << ((mx + k - 1) / k) * ok.size() * k - n << '\n';
	return 0;
}