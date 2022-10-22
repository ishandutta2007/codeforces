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
#define ld double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int mod = 998244353;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		for (int i = 4 * n; i > 2 * n; i -= 2) {
			cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}