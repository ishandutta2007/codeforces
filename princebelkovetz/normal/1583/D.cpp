#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 5e5 + 3;

int query(vector <int> a) {
	cout << "? ";
	for (auto& x : a) cout << x << ' ';
	cout << endl;
	int x; cin >> x;
	return x;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, lst = 0; cin >> n;
	vector <int> ans(n), q(n, n);
	q.back() = 1;
	if (query(q)) {
		lst = n;
	}
	else {
		q = vector <int>(n, 1);
		for (int i = 1; i < n; ++i) {
			q.back() = n + 1 - i;
			if (query(q)) {
				lst = i;
				break;
			}
		}
	}

	ans.back() = lst;
	for (int i = 1; i <= n; ++i) {
		if (i == lst) continue;
		q = vector <int>(n, lst);
		q.back() = i;
		ans[query(q) - 1] = i;
	}
	cout << "! ";
	for (auto& x : ans) cout << x << ' ';
	cout << endl;

	return 0;
}