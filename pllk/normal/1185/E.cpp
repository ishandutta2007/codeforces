#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<string> v;

int a[128][2];
int b[128][2];

void lol() {
	cin >> n >> m;
	for (int c = 'a'; c <= 'z'; c++) {
		a[c][0] = a[c][1] = -1;
		b[c][0] = b[c][1] = -1;
	}
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		for (int j = 0; j < m; j++) {
			int c = v[i][j];
			if (c == '.') continue;
			if (a[c][0] == -1) {
				a[c][0] = i; a[c][1] = j;
			}
			b[c][0] = i; b[c][1] = j;
		}
	}
	bool ok = true;
	vector<vector<int>> r;
	bool ff = false;
	for (int c = 'z'; c >= 'a'; c--) {
		if (a[c][0] == -1) {
			if (ff) r.push_back(r.back());
			continue;
		}
		ff = true;
		if (a[c][0] != b[c][0] && a[c][1] != b[c][1]) ok = false;
		if (!ok) break;
		r.push_back({a[c][0]+1,a[c][1]+1,b[c][0]+1,b[c][1]+1});
		for (int i = a[c][0]; i <= b[c][0]; i++) {
			for (int j = a[c][1]; j <= b[c][1]; j++) {
				if (v[i][j] == c) v[i][j] = '#';
				if (v[i][j] != '#') ok = false;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] != '.' && v[i][j] != '#') ok = false;
		}
	}
	if (ok) cout << "YES\n";
	else cout << "NO\n";
	if (!ok) return;
	reverse(r.begin(),r.end());
	cout << r.size() << "\n";
	for (auto x : r) {
		cout << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << "\n";
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) lol();
}