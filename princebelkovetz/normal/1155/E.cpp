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
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int k = 11, mod = 1e6 + 3; 
vector <int> gauss(vector <vector <int>>& a) {
	vector <int> ans(k);
	for (int i = 0; i < k; ++i) {
		for (int j = i; j < k; ++j) {
			if (a[j][i]) {
				swap(a[j], a[i]);
				break;
			}
		}
		if (!a[i][i]) {
			continue;
		}
		int c1 = a[i][i];
		for (int j = i + 1; j < k; ++j) {
			if (!a[j][i]) continue;
			int c2 = a[j][i];
			for (int f = i; f <= k; ++f) {
				a[j][f] = (a[j][f] * c1) % mod - (a[i][f] * c2) % mod + mod;
				a[j][f] %= mod;
			}
		}
	}
	for (int i = k - 1; i >= 0; --i) {
		for (int f = 0; f < mod; ++f)
			if (a[i][i] * f % mod == a[i][k]) {
				ans[i] = f;
				break;
			}
		for (int j = 0; j < i; ++j) {
			a[j][i] = (a[j][i] * ans[i]) % mod;
			a[j][k] -= a[j][i]; 
			a[j][k] += mod; a[j][k] %= mod;
			a[j][i] = 0;
		}
	}
	return ans;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	vector <vector <int>> a(k, vector <int>(k + 1));
	for (int i = 0; i < k; ++i) {
		cout << "? " << i << endl;
		fflush(stdout);
		int x, cur = 1; cin >> x;
		a[i][k] = x;
		for (int j = k - 1; j >= 0; --j, cur = (cur * i) % mod) {
			a[i][j] = cur;
		}
	}
	vector <int> res = gauss(a);
	reverse(res.begin(), res.end());
	for (int i = 0; i < mod; ++i) {
		int cur = 1, itog = 0;
		for (int j = 0; j < k; ++j, cur = cur * i % mod) {
			itog = ((cur * res[j]) % mod + itog) % mod;
		}
		if (!itog) {
			cout << "! " << i << endl;
			fflush(stdout);
			return 0;
		}
	}
	cout << "! -1" << endl;
	return 0;
}