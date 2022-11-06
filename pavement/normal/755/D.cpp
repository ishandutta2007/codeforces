#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k, ft[1000005];

inline int ls(int x) {
	return x & -x;
}

int qry(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r += ft[p];
	return r;
}

void upd(int p) {
	for (; p <= n; p += ls(p)) ft[p]++;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	k = min(k, n - k);
	int p = 1, s = 1;
	for (int i = 0; i < n; i++) {
		s++;
		int j = (p + k <= n ? p + k : p + k - n);
		if (j > p) s += qry(j - 1) - qry(p);
		else s += qry(n) - qry(p) + qry(j - 1);
		upd(p), upd(j);
		cout << s << ' ';
		p = j;
	}
	cout << '\n';
}