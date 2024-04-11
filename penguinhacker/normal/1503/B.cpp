#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, g[101][101];
vector<ar<int, 2>> o, e;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if ((i + j) % 2)
				o.push_back({i, j});
			else
				e.push_back({i, j});
		}
	for (int i = 1; i <= n * n; ++i) {
		int c;
		cin >> c;
		if (c == 1) {
			if (!o.empty()) {
				int i = o.back()[0], j = o.back()[1];
				o.pop_back();
				cout << "2 " << i << " " << j << endl;
			}
			else {
				int i = e.back()[0], j = e.back()[1];
				e.pop_back();
				//g[i][j] = 1;
				cout << "3 " << i << " " << j << endl;
			}
		}
		else {
			if (!e.empty()) {
				int i = e.back()[0], j = e.back()[1];
				e.pop_back();
				//g[i][j] = 1;
				cout << "1 " << i << " " << j << endl;
			}
			else {
				int x = c == 2 ? 3 : 2;
				int i = o.back()[0], j = o.back()[1];
				o.pop_back();
				cout << x << " " << i << " " << j << endl;
			}
		}
	}
	return 0;
}