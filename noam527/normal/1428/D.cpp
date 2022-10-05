#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n;
vector<int> a;
vector<pair<int, int>> out;

void solve() {
	out.clear();
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	vector<int> pos(n, -1);
	int nxtrow = 0;
	set<int> one;
	set<int> two;
	for (int i = n - 1; i >= 0; i--) {
		int x = a[i];
		if (x == 1) {
			out.emplace_back(nxtrow, i);
			one.insert(nxtrow);
			pos[nxtrow] = i;
			nxtrow++;
		}
		else if (x == 2) {
			if (one.size() == 0) {
				cout << "-1\n";
				return;
			}
			out.emplace_back(*one.begin(), i);
			pos[*one.begin()] = i;
			two.insert(*one.begin());
			one.erase(one.begin());
		}
		else if (x == 3) {
			pos[nxtrow] = i;
			if (two.size()) {
				int j = pos[*two.begin()];
				out.emplace_back(nxtrow, i);
				out.emplace_back(nxtrow, j);
				two.insert(nxtrow);
				nxtrow++;
				two.erase(two.begin());
			}
			else if (one.size()) {
				int j = pos[*one.begin()];
				out.emplace_back(nxtrow, i);
				out.emplace_back(nxtrow, j);
				two.insert(nxtrow);
				nxtrow++;
				one.erase(one.begin());
			}
			else {
				cout << "-1\n";
				return;
			}
		}
		if (OO) {
			cout << "after " << i << ":\n";
			for (const auto &x : one) cout << x << " "; cout << '\n';
			for (const auto &x : two) cout << x << " "; cout << '\n';
		}
	}
	cout << out.size() << '\n';
	for (auto &i : out) {
		cout << n - i.first << " " << i.second + 1 << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}