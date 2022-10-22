#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0}, dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int n, x0, y0, x1, y1;
set<pair<int, int>> squares;
map<pair<int, int>, int> d;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> x0 >> y0 >> x1 >> y1 >> n;
	for (int i = 0; i < n; ++i) {
		int r, x, y; cin >> r >> x >> y;
		for (int j = x; j <= y; ++j) squares.emplace(r, j);
	}
	d[{x0, y0}] = 0;
	queue<pair<int, int>> q;
	q.emplace(x0, y0);
	while(!q.empty()) {
		pair<int, int> u = q.front(); q.pop();
		int i = u.first, j = u.second;
		int cur = d[{i, j}];
		for (int k = 0; k < 8; ++k) {
			int a = i + dx[k], b = j + dy[k];
			if (squares.find({a, b}) != squares.end() && d.find({a, b}) == d.end()) {
				d[{a, b}] = cur + 1;
				q.emplace(a, b);
			}
		}
	}
	int ans = -1;
	if (d.find({x1, y1}) != d.end()) ans = d[{x1, y1}];
	cout << ans;
	return 0;
}