#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	if (n>m) {
		cout << m+1 << '\n';
		for (int i=0; i<=m; ++i)
			cout << i+1 << ' ' << i << '\n';
	}
	else if (m>n) {
		cout << n+1 << '\n';
		for (int i=0; i<=n; ++i)
			cout << i << ' ' << i+1 << '\n';
	}
	else {
		cout << n+1 << '\n';
		for (int i=0; i<=n; ++i)
			cout << i << ' ' << n-i << '\n';
	}
	return 0;
}