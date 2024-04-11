#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, q;
vector<int> a;
map<int, int> f;
vector<pair<int, int>> b;

int freq(int l, int r) {
	map<int, int> tmp;
	for (int i = l; i <= r; i++)
		tmp[a[i]]++;
	int ans = 0;
	for (auto &i : tmp)
		ans = max(ans, i.second);
	return ans;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (!f.count(a[i])) f[a[i]] = i;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (f.count(a[i])) {
			b.emplace_back(f[a[i]], i);
			f.erase(a[i]);
		}
	}
	sort(b.begin(), b.end());
	vector<pair<int, int>> c;
	for (auto &i : b) {
		if (!c.size() || c.back().second < i.first) c.push_back(i);
		else c.back().second = max(c.back().second, i.second);
	}
	int ans = n;
	for (auto &i : c)
		ans -= freq(i.first, i.second);
	finish(ans);
}