#include <iostream>
#include <set>

using namespace std;

int n;
int a[202020];
int b[202020];
set<int> s;

void lol(int x) {
	for (int u = 2; u*u <= x; u++) {
		if (x%u == 0) {
			s.insert(u);
			while (x%u == 0) x /= u;
		}
	}
	if (x != 1) s.insert(x);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	lol(a[1]);
	lol(b[1]);
	for (auto x : s) {
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			if (a[i]%x == 0 || b[i]%x == 0) continue;
			ok = false;
			break;
		}
		if (ok) {
			cout << x << "\n";
			return 0;
		}
	}
	cout << "-1\n";
}