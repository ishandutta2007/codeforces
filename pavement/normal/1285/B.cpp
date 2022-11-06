#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int ft[100005], p[100005], cp[100005], st;
 
int ls(int x) {
	return x & -x;
}

int qry(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r = max(r, ft[p]);
	return r;
}
 
void upd(int p, int v) {
	for (; p <= 100000; p += ls(p)) ft[p] = max(ft[p], v);
}
 
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		memset(ft, 0, sizeof ft);
		int smallsz = n + 1;
		for (int i = 1; i <= n; i++) cin >> p[i], p[i] += p[i - 1], cp[i] = p[i];
		sort(cp + 1, cp + 1 + n);
		for (int i = 1; i <= n; i++) {
			if (i != n && p[i] >= p[n]) {
				smallsz = 0;
				break;
			}
			auto it = upper_bound(cp + 1, cp + 1 + n, p[i] - p[n]);
			if (it == cp + 1 && p[i] - p[i - 1] >= p[n]) smallsz = 1;
			else if (it != cp + 1) {
				--it;
				int y = qry(it - (cp + 1) + 1);
				smallsz = min(smallsz, i - y);
			}
			it = lower_bound(cp + 1, cp + 1 + n, p[i]);
			upd(it - (cp + 1) + 1, i);
		}
		if (smallsz < n) cout << "NO\n";
		else cout << "YES\n";
	}
}