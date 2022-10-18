#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	bool res = false;
	for (int i = 0; i < 3; i++) {
		if (a+b == c) res = true;
		if (a == b && c%2 == 0) res = true;	
		swap(a,b), swap(b,c);
	}
	cout << (res ? "YES" : "NO") << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}