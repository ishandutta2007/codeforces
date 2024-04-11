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
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int n; cin >> n;
	vector <string> a(n, string(n, 'W'));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			if ((j & 1) ^ (i & 1)) a[i][j] = 'B';
	}
	for (auto x : a) cout << x << '\n';
	return 0;
}