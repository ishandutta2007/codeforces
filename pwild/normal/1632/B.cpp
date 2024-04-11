#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	int k = 1;
	while (2*k < n) k *= 2;

	for (int i = n-1; i >= k; i--) cout << i << " ";
	for (int i = 0; i < k; i++) cout << i << " ";
	cout << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}