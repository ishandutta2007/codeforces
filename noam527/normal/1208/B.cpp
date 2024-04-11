#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
vector<int> a;

bool check(int l, int r) {
	vector<int> b;
	int len = n - (r - l + 1);
	for (int i = 0; i < l; i++) b.push_back(a[i]);
	for (int i = r + 1; i < n; i++) b.push_back(a[i]);
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());
	return b.size() == len;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	set<int> tmp;
	for (auto &i : a) cin >> i, tmp.insert(i);
	if (tmp.size() == n) finish(0);
	int ans = n - 1;
	int p = 0;
	for (int i = 0; i < n; i++) {
		p = max(p, i);
		while (p < n && !check(i, p)) p++;
		if (p == n) break;
		ans = min(ans, p - i + 1);
	}
	cout << ans << '\n';
}