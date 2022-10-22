#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cout << 3*n+4 << '\n';
	for (int i=0; i<=n+1; ++i) {
		cout << i << ' ' << i << '\n';
		if (i) {
			cout << i << ' ' << i-1 << '\n' << i-1 << ' ' << i << '\n';
		}
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/