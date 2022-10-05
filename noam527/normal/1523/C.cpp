#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
vector<int> a;

void prn(const vector<int> &lst) {
	cout << lst[0];
	for (int i = 1; i < lst.size(); i++) {
		cout << "." << lst[i];
	}
	cout << '\n';
}

void solve() {
	cin >> n;
	vector<int> lst;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		if (x == 1) {
			lst.push_back(1);
		}
		else {
			while (lst.size() && lst.back() != x - 1) lst.pop_back();
			if (lst.size() == 0) lst.push_back(x);
			else {
				lst.pop_back();
				lst.push_back(x);
			}
		}
		prn(lst);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}