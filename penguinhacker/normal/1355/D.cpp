#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	if (n>s/2) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int i=0; i<n; ++i) {
		if (i<n-1)
			cout << "2 ";
		else
			cout << s-2*(n-1) << '\n';
	}
	cout << 1;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/