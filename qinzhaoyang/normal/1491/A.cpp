#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int n, q, a[100010];
int cnt[2];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		if(x == 1) {
			if(a[y] == 1)
				a[y] = 0, cnt[0]++, cnt[1]--;
			else
				a[y] = 1, cnt[1]++, cnt[0]--;
		}
		else {
			if(y <= cnt[1]) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	return 0;
}