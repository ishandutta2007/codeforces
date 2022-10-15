#include <iostream>
#include <vector>

using namespace std;

int n, m;
int a[1111], b[1111];
int u[1111];
vector<vector<int>> v;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1) {a[l]++; b[r]++;}
		v.push_back({t,l,r});
	}
	int x = 2000;
	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (c == 0) x--;
		u[i] = x;
		c += a[i];
		c -= b[i];
	}
	for (auto r : v) {
		if (r[0] == 1 && u[r[1]] == u[r[2]]) continue;
		if (r[0] == 0 && u[r[1]] > u[r[2]]) continue;
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int i = 1; i <= n; i++) cout << u[i] << " ";
	cout << "\n";
}