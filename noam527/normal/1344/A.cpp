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
vector<int> a;

void solve() {
	cin >> n;
	a.resize(n);
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(((i + a[i]) % n + n) % n);
	}
	if (s.size() == n)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}