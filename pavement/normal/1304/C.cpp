#include <bits/stdc++.h>
using namespace std;
#define int long long

int t[105], l[105], h[105], leftv, rightv, p;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int te, n, m;
	cin >> te;
	while (te--) {
		cin >> n >> m;
		p = 0;
		leftv = rightv = m;
		bool can = 1;
		for (int i = 1; i <= n; i++)
			cin >> t[i] >> l[i] >> h[i];
		for (int i = 1; i <= n; i++) {
			int tleft = leftv - (t[i] - t[i - 1]), tright = rightv + (t[i] - t[i - 1]);
			if (tright < l[i] || tleft > h[i]) {
				can = 0;
				break;
			} else {
				leftv = max(l[i], tleft);
				rightv = min(h[i], tright);
			}
		}
		cout << (can ? "YES" : "NO") << '\n';
	}
}