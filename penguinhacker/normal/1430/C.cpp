#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n;
	cin >> n;
	if (n == 2) {
		cout << "2\n1 2\n";
		return;
	}
	cout << "2\n" << n - 2 << " " << n << "\n" << n - 1 << " " << n - 1 << "\n";
	for (int i = n - 1; i > 2; --i) {
		cout << i - 2 << " " << i << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}