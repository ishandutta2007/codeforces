#include <bits/stdc++.h>
using namespace std;

int cnt[200001];
int nxt[200001];

bool test(int vl, int c) {
	int val_cur = c;
	while (c) {
		if (c < vl) vl = 0;
		int gg = nxt[val_cur];
		
		if (gg == 0 && vl == 0) return 0;
		if (vl >= gg) {
			c -= vl;
			val_cur = min(c, vl);
			vl = 0;
		} else {
			int tak = min(cnt[gg], c/gg);
			c -= tak*gg;
			val_cur = min(c, gg-1);
		}
	}
	return 1;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int c, n; 
	cin >> c >> n;
	while (n--) {
		int x; cin >> x;
		cnt[x]++;
	}

	int prv = 0;
	for (int i = 1; i <= c; i++) {
		if (cnt[i]) prv = i;
		nxt[i] = prv;
	}

	for (int i = 1; i <= c; i++) {
		if (!test(i, c)) {
			cout << i << '\n';
			exit(0);
		}
	}
	cout << "Greed is good\n";

	return 0;
}