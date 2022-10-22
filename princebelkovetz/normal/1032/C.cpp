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
	int n; cin >> n;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	vector <vector <int>> dp(n, vector <int>(5, -1));
	for (int i = 0; i < 5; ++i)
		dp[0][i] = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < 5; ++k) {
				if ((a[i] > a[i - 1] and j > k) or (a[i] < a[i - 1] and j < k) or (a[i] == a[i - 1] and j != k)) {
					if (dp[i - 1][k] != -1) {
						dp[i][j] = k;
						break;
					}
				}
			}
		}
	}
	vector <int> ans;
	int ind = -1, len = n - 1;
	for (int i = 0; i < 5; ++i) {
		if (dp[n - 1][i] != -1)
			ind = i;
	}
	if (ind == -1) {
		cout << ind << '\n';
		return 0;
	}
	else {
		while (len > -1) {
			ans.push_back(ind);
			ind = dp[len][ind];
			--len;
		}
		reverse(ans.begin(), ans.end());
		for (auto x : ans) 
			cout << x + 1 << ' ';
	}
	return 0;
}