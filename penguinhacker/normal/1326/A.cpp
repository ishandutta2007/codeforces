#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n;

void solve() {
	cin >> n;
	if (n==1) {
		cout << -1 << '\n';
		return;
	}
	n--;
	while (n--)
		cout << 9;
	cout << 4 << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) 
		solve();
	return 0;
}