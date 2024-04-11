#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 31607;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
vector<int> a;
set<int> s;

void calc(int i, int sum) {
	if (i == n) {
		s.insert(sum);
		return;
	}
	calc(i + 1, sum);
	calc(i + 1, sum + a[i]);
}

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) {
		cin >> i;
		i = abs(i);
	}
	sort(a.begin(), a.end());
	if (a[0] == 0) {
		cout << "YES\n";
		return;
	}
	s.clear();
	calc(0, 0);
	if (s.size() < (1 << n)) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
	return;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	//srand(time(NULL));
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}