#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
string s;
vector<int> a[10];
vector<int> ans;

void solve() {
	cin >> n >> s;
	ans.resize(n);
	for (int i = 0; i < 10; i++) a[i].clear();
	for (int i = 0; i < n; i++)
		a[s[i] - '0'].push_back(i);
	int lst = md, cnt = 0;
	for (int i = 0; i < 10; i++) {
		if (a[i].size() == 0) continue;
		if (a[i][0] < lst) {
			int nl = -1;
			for (auto &j : a[i])
				if (lst < j)
					ans[j] = cnt;
				else
					ans[j] = cnt + 1, nl = j;
			cnt++;
			lst = nl;
		}
		else {
			for (auto &j : a[i]) ans[j] = cnt;
			lst = a[i].back();
		}
	}
	if (cnt > 2) {
		cout << '-' << '\n';
		return;
	}
	for (const auto &i : ans) cout << i; cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst;
	cin >> tst;
	while (tst--) solve();
}