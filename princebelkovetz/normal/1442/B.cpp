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
	int tests;
	cin >> tests;
	while (tests --> 0){
		int n, k; cin >> n >> k;
		vector <int> a(n), b(k), p(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;
		for (int i = 0; i < n; ++i)
			p[a[i] - 1] = i;
		vector <bool> used(n);
		for (auto x : b)
			used[x - 1] = true;
		vector <set <int>> nb(n);
		nb[0] = { a[1] };
		nb[n - 1] = { a[n - 2] };
		for (int i = 1; i < n - 1; ++i) {
			nb[i] = { a[i - 1], a[i + 1] };
		}
		int ans = 1;
		for (auto x : b) {
			int cnt = 0;
			int nei = -1;
			used[x - 1] = false;
			for (auto y: nb[p[x - 1]]) {
				if (!used[y - 1]) {
					cnt++;
					nei = y;
				}
			}
			ans = ans * cnt % mod;
			if (!ans) break;
			nb[p[x - 1]].erase(nei);
			for (auto y : nb[p[nei - 1]]) {
				if (y != x)
					nb[p[x - 1]].insert(y);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}