#include <bits/stdc++.h>
using namespace std;
 
int a[105], b[105];
 
int main() {
	int t, n, k1, k2;
	cin >> t;
	while (t--) {
		cin >> n >> k1 >> k2;
		for (int i = 0; i < k1; i++) cin >> a[i];
		for (int i = 0; i < k2; i++) cin >> b[i];
		sort(a, a + k1, greater<int>());
		sort(b, b + k2, greater<int>());
		if (a[0] > b[0]) cout << "YES\n";
		else cout << "NO\n";
	}
}