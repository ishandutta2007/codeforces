#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, m;
vector<string> a, b;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		--x;
		cout << a[x % n] << b[x % m] << endl;
	}
}