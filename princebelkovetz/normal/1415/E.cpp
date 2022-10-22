#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
using namespace std;
#define int long long
#define debug(x) cout << #x << " equals " << x << '\n'; 

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n, k; cin >> n >> k;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	multiset <int> q = { 0 };
	while (k--)
		q.insert(0);
	sort(a.rbegin(), a.rend());
	int ans = 0;
	for (auto x : a) {
		auto it = q.begin();
		ans -= *it;
		int replace = *it - x;
		q.erase(it);
		q.insert(replace);
	}
	cout << ans << '\n';
}