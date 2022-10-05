#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int n, m, p1 = 0, p2 = 0, l, r, x, a[200000], b[200000];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	while (p2 < n) {
		if (a[p1] == a[p2]) p2++;
		else b[p1] = p2, p1++;
	}
	while (m--) {
		cin >> l >> r >> x;
		l--, r--;
		if (l >= p1 || b[l] > r) {
			if (a[l] != x) cout << l + 1 << endl;
			else cout << -1 << endl;
		}
		else {
			if (a[l] != x) cout << l + 1 << endl;
			else cout << b[l] + 1 << endl;
		}
	}
	return 0;
}