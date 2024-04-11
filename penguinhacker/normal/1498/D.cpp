#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, d[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	d[0] = 0;
	fill(d + 1, d + m + 1, -1);
	for (int i = 1, t; i <= n; ++i) {
		ll x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			x = (x + 99999) / 100000;
			vector<int> last(x, -1);
			for (int j = 0; j <= m; ++j) {
				if (d[j] == -1) {
					if (last[j % x] != -1 && j / x - last[j % x] <= y)
						d[j] = i;
				}
				else {
					last[j % x] = j / x;
				}
			}
		}
		else if (t == 2) {
			vector<int> last(m + 1, -1);
			for (int j = 0; j <= m; ++j)
				if (d[j] != -1)
					last[j] = 0;
			for (int j = 0; j <= m; ++j) {
				if (last[j] == -1)
					continue;
				ll nxt = (j * x + 99999) / 100000;
				if (nxt > m)
					continue;
				if (last[nxt] == -1 ||  last[j] + 1 < last[nxt])
					last[nxt] = last[j] + 1;
			}
			for (int j = 0; j <= m; ++j)
				if (d[j] == -1 && last[j] != -1 && last[j] <= y)
					d[j] = i;
		}
	}
	for (int i = 1; i <= m; ++i)
		cout << d[i] << " ";
	return 0;
}