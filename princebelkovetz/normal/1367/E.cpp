#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
//pragma GCC optimize("Ofast")
//pragma GCC target( "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native" )
#include <queue>
#define endl "\n";
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

void solve() {
	int n1, k, cur;
	cin >> n1 >> k;
	string s; cin >> s;
	for (int gg = n1; gg >= 0; gg--) {
		int n = gg;
		vector <int> a(n), cyc; vector <bool> used(n);
		map <char, int> m;
		for (auto x : s) m[x]++;
		for (int i = 0; i < n; ++i) {
			a[i] = (i + k) % n;
			//cout << a[i] << " ";
		}
		/*cout << endl;
		for (auto x : m) {
			cout << x.first << " " << x.second << endl;
		}*/
		bool f = true;
		for (int i = 0; i < n; ++i) {
			if (used[i]) continue;
			cur = 1;
			used[i] = true;
			for (int j = a[i]; j != i; j = a[j]) {
				cur++;
				used[j] = true;
			}
			//debug(cur);
			int mx = 0, ind;
			for (auto &x : m) {
				if (x.second >= mx) {
					mx = x.second;
					ind = x.first;
				}
			}
			//debug(mx);
			if (mx >= cur) {
				m[ind] -= cur;
				f = false;
			}
			else {
				f = true;
				break;
			}
		}
		if (f) continue;
		else {
			cout << n << endl;
			return;
		}
	}

	
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}