/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

int const N = 123456;

int p[N];

int get(int x) {
	return x == p[x] ? x : (p[x] = get(p[x]));
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) p[i] = i;
	int ans = 0;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		if (get(x) != get(y)) {
			p[get(x)] = get(y);
		} else {
			ans++;
		}
	}	
	cout << ans << endl;
}