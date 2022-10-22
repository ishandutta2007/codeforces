#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define int long long
#define debug(x) cout << #x << " equals " << x << '\n'; 
const int mod = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int testcases;
	cin >> testcases;
	while (testcases --> 0) {
		int n; cin >> n;
		vector <vector <int>> a(n, vector <int>(n));
		for (int i = 0; i < n; ++i) {
			string s; cin >> s;
			for (int j = 0; j < n; ++j)
				a[i][j] = s[j] - '0';
		}
		vector <vector <bool>> hr(10, vector <bool>(n));
		vector <vector <bool>> hc(10, vector <bool>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				hr[a[i][j]][i] = true;
				hc[a[i][j]][j] = true;
			}
		}
		vector <vector <int>> fr(10, vector <int>(n));
		vector <vector <int>> fc(10, vector <int>(n));
		for (int k = 0; k < 10; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (hr[k][j]) fr[k][i] = max(fr[k][i], abs(i - j));
					if (hc[k][j]) fc[k][i] = max(fc[k][i], abs(i - j));
				}
			}
		}
		vector <int> ans(10);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int r1 = fr[a[i][j]][i];
				r1 *= max(j, n - j - 1);
				int r2 = fc[a[i][j]][j];
				r2 *= max(i, n - i - 1);
				ans[a[i][j]] = max(ans[a[i][j]], max(r1, r2));
			}
		}
		
		for (auto x : ans) cout << x << ' ';
		cout << '\n';
	}
}