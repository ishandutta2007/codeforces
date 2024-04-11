#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const ld eps = 1e-13;
string rev(string s) {
	string t = "";
	for (auto x : s) {
		if (x == '0') t += '1';
		else t += '0';
	}
	return t;
}
signed main() {
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		vector <int> a(2 * n), sums;
		for (auto& x : a) cin >> x;
		set <int> used;
		int j = 2 * n - 1;
		int mx = 2 * n;
		while (j >= 0) {
			while (used.find(mx) != used.end()) mx--;
			sums.push_back(0);
			for (; j > 0 and a[j] != mx; --j) {
				sums.back()++;
				used.insert(a[j]);
			}
			used.insert(a[j]);
			sums.back()++;
			--j;
		}
		//for (auto x : sums) cout << x << ' ';
		//cout << endl;
		vector <bool> dp(n + 1); dp[0] = true;
		for (int i = 0; i < sums.size(); ++i)
			for (int k = n; k >= 0; --k) {
				if (dp[k] and k + sums[i] <= n) {
					dp[k + sums[i]] = true;
				}
				//for (auto x : dp) cout << x << ' ';
				//cout << endl;
			}
		if (dp[n]) cout << "YES\n";
		else cout << "NO\n";
		
	}
	return 0;
}