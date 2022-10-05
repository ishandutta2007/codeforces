#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

struct some {
	int a, b, i;
	some() {}
	some(int aa, int bb, int ii) {
		a = aa;
		b = bb;
		i = ii;
	}
	bool operator < (const some &a) const {
		return b > a.b;
	}
};

int n;
vector<some> a, b;
vector<int> ans;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x < y) a.push_back(some(x, y, i));
		else b.push_back(some(y, x, i));
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (b.size() > a.size()) {
		for (const auto &i : b) ans.push_back(i.i);
		reverse(ans.begin(), ans.end());
	}
	else {
		for (const auto &i : a) ans.push_back(i.i);
	}
	cout << ans.size() << '\n';
	for (const auto &i : ans) cout << 1 + i << " "; cout << '\n';
}