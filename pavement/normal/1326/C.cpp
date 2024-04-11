#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int M = 998244353;
int p[200005], t[200005], L[200005], R[200005];
set<int> chose;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, st =0, tt = 1, last = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> p[i], t[i] = p[i];
	sort(t + 1, t + 1 + n, greater<int>());
	for (int i = 1; i <= k; i++) {
		st += t[i];
		chose.insert(t[i]);
	}
	cout << st << ' ';
	for (int i = 1, lef = 1; i <= n; i++) {
		if (chose.count(p[i])) {
			L[i] = lef;
			last = i;
			lef = i + 1;
		}
	}
	for (int i = n, ri = n; i >= 1; i--) {
		if (chose.count(p[i])) {
			R[i] = ri;
			ri = i - 1;
		}
	}
	for (int i = 1; i < n; i++)
		if (L[i] && i != last) tt *= (R[i] - i + 1), tt %= M;
	cout << tt << '\n';
}