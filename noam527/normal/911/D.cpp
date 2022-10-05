#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0, l, r, d, a[1500];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (a[i] > a[j]) ans++;

	cin >> m;
	while (m--) {
		cin >> l >> r;
		d = r - l;
		ans ^= ((d * (d + 1) / 2) & 1);
		if (ans & 1) cout << "odd" << '\n';
		else cout << "even" << '\n';
	}
}