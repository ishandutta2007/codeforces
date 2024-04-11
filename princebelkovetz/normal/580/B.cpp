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
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	int n, d; cin >> n >> d;
	vector <pair <int, int>> a(n);
	for (auto& x : a)
		cin >> x.first >> x.second;
	sort(a.begin(), a.end());
	int cur = 0;
	int ans = 0;
	int j = 0;
	for (int i = 0; i < n; ++i) {
		for (; j < n and a[j].first - a[i].first < d; ++j) {
			cur += a[j].second;
		}
		ans = max(ans, cur);
		cur -= a[i].second;
	}
	cout << ans << '\n';
}