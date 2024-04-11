/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	int x = 0;
	int y = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == 'B') {
				count++;
				x += i;
				y += j;
			}
		}
	}
	x /= count;
	y /= count;
	cout << (x + 1) << ' ' << (y + 1) << endl;
}