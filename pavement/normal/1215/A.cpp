#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a1, a2, k1, k2, n;
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	if (k1 > k2) swap(k1, k2), swap(a1, a2);
	cout << min(a1 + a2, max(0ll, n - ((k2 - 1) * a2 + (k1 - 1) * a1))) << ' ' << (n >= a1 * k1 ? a1 + min(a2,(n - (a1 * k1)) / k2) : n / k1);
}