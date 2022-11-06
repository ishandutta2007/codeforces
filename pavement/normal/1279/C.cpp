#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[100005], b[100005], pos[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m;
	cin >> t;
	while (t--) {
		int k = 0, mpos = -1;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			pos[a[i]] = i;
		}
		for (int i = 0; i < m; i++) cin >> b[i];
		for (int i = 0; i < m; i++) {
			if (pos[b[i]] < mpos) k++;
			else k += (pos[b[i]] - i) * 2 + 1;
			mpos = max(mpos, pos[b[i]]);
		}
		cout << k << '\n';
	}
}