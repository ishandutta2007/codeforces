#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <queue>
using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
const int N = 5e6 + 2, mod = 1e9 + 7, mod2 = 998244353;
set <int> d;
vector <int> resh(N);
bool check(int x) {
	vector <int> all;
	while (x != 1)
		all.push_back(resh[x]), x /= resh[x];
	for (auto x : all)
		if (d.find(x) != d.end())
			return false;
	for (auto x : all)
		d.insert(x);
	return true;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n; cin >> n;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	for (int i = 2; i < N; ++i) {
		if (resh[i]) continue;
		resh[i] = i;
		for (int j = i * i; j < N; j += i) {
			if (!resh[j]) resh[j] = i;
		}
	}
	vector <int> ans(n);
	int ind = 0;
	for (; ind < n; ++ind) {
		if (check(a[ind]))
			ans[ind] = a[ind];
		else
			break;
	}
	int last = 2;
	if (ind != n) {
		last = a[ind];
		while (!check(last)) {
			last++;
		}
		ans[ind] = last;
		last = 2;
		ind++;
	}
	for (; ind < n; ++ind) {
		while (1) {
			if (resh[last] == last and d.find(last) == d.end()) break;
			last++;
		}
		ans[ind] = last;
		last++;
	}
	for (auto x : ans) cout << x << ' ';
	cout << '\n';
	return 0;
}