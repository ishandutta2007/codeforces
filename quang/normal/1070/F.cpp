#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

int n;
vector<int> a[4];
vector<int> p[4];

int get(const vector<int> &x, const vector<int> &y, int diff) {
	int x_pos = (int)x.size() - 1;
	int y_pos = (int)y.size() - 1;
	if (abs(x_pos - y_pos) <= diff) return x[x_pos] + y[y_pos];
	if (x_pos < y_pos) {
		y_pos = x_pos + diff;
	} else {
		x_pos = y_pos + diff;
	}
	return x[x_pos] + y[y_pos];
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string t;
		int x;
		cin >> t >> x;
		int mask = (t[0] - '0') * 2 + (t[1] - '0');
		a[mask].push_back(x);
	}

	for (int i = 0; i < 4; ++i) {
		sort(a[i].begin(), a[i].end(), greater<int>());
		a[i].insert(a[i].begin(), 0);
		p[i].resize(a[i].size());
		for (int j = 1; j < p[i].size(); ++j) {
			p[i][j] = p[i][j - 1] + a[i][j];
		}
	}
/*
	for (int i = 0; i < 4; ++i) {
		cerr << i << ": ";
		for (int v : a[i]) {
			cerr << v << ' ';
		}
		cerr << endl;
	}
*/
	int cnt_d = a[3].size() - 1;
	int ans = 0;
	for (int cnt_a = 0; cnt_a < a[0].size() && cnt_a <= cnt_d; ++cnt_a) {
		int cur = p[3][cnt_d] + p[0][cnt_a];
		int bc = get(p[1], p[2], cnt_d - cnt_a);
//		cerr << cnt_d << ' ' << cnt_a << ' ' << cur << ' ' << bc << endl;
		ans = max(ans, cur + bc);
	}

	cout << ans << endl;
	return 0;
}