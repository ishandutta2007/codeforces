#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long
#define ld long double

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int testcases; cin >> testcases;
	while (testcases --> 0) {
		int n, k; cin >> n >> k;
		vector <int> perm(k);
		for (int i = 1; i <= k; ++i)
			perm[i - 1] = i;
		reverse(perm.begin() + (2 * k - n - 1), perm.begin() + k);
		for (auto x : perm) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}