#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int a[100005];
 
main() {
	int t, n;
	cin >> t;
	while (t--) {
		int xs = 0, s = 0;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i], xs ^= a[i], s += a[i];
		cout << "2\n";
		cout << xs << ' ';
		s += xs;
		cout << s << '\n';
	}
}