#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, k;

void solve() {
	cin >> n >> k;
	cout << (n/k)*k + min(n%k, k/2) << '\n';
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