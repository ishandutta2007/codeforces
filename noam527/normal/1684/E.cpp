#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const int OO = 1;
using namespace std;

int n, k;
vector<int> a;
vector<int> has;
vector<pair<int, int>> c;

int sum;
multiset<int> S;

void insert(int val) {
	S.insert(val);
	sum += val;
	while (S.size() && sum > k) {
		int x = *S.rbegin();
		sum -= x;
		S.erase(S.find(x));
	}
}

void solve() {
	cin >> n >> k;
	a.resize(n);
	has.resize(n);
	c.clear();
	for (auto &i : a) cin >> i;
	sort(a.begin(), a.end());

	for (auto &i : has) i = 0;
	for (auto &i : a)
		if (i < n)
			has[i] = 1;

	c.emplace_back(a[0], 1);
	for (int i = 1; i < n; i++) {
		if (a[i] == c.back().first)
			c.back().second++;
		else
			c.emplace_back(a[i], 1);
	}

	int lim = -1, cnt = 0;
	for (int x = 0; x <= n; x++) {
		if (cnt > k)
			break;
		lim = x;
		if (!has[x]) cnt++;
	}
	// x is in [0, lim]
	S.clear();
	sum = 0;

	int nxtc = (int)c.size() - 1;
	int ans = md;
	for (int x = lim; x >= 0; x--) {
		while (nxtc >= 0 && c[nxtc].first >= x) {
			insert(c[nxtc].second);
			nxtc--;
		}
		int diffx = (int)c.size() - 1 - nxtc;
		ans = min(ans, diffx - (int)S.size());
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}