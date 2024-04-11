#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long
const int mod = 1e9;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0, x; j < m; ++j) {
			cin >> x;
			cout << 720720 + ((i + j) & 1 ? 0 : x * x * x * x) << ' ';
		}
		cout << '\n';
	}
	return 0;
}