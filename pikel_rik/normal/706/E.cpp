#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;

int n, m, q, v[N][N];
pair<int, int> r[N][N], d[N][N];

void go_down(pair<int, int> &p) {
	p = d[p.first][p.second];
}

void go_right(pair<int, int> &p) {
	p = r[p.first][p.second];
}

pair<int, int> get_point(int i, int j) {
	pair<int, int> p = {i, 0};
	while (j--) {
		go_right(p);
	}
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			r[i][j] = make_pair(i, j + 1);
			d[i][j] = make_pair(i + 1, j);
		}
	}

	int x1, y1, x2, y2, h, w;
	while (q--) {
		cin >> x1 >> y1 >> x2 >> y2 >> h >> w;

		pair<int, int> p0 = get_point(x1 - 1, y1), p1 = get_point(x2 - 1, y2);
		pair<int, int> p2 = get_point(x1 + h - 1, y1), p3 = get_point(x2 + h - 1, y2);
		pair<int, int> p4 = get_point(x1, y1 + w - 1), p5 = get_point(x2, y2 + w - 1);
		pair<int, int> p6 = get_point(x1, y1 - 1), p7 = get_point(x2, y2 - 1);


		for (int i = 0; i < w; i++) {
			swap(d[p0.first][p0.second], d[p1.first][p1.second]);
			go_right(p0), go_right(p1);
		}

		for (int i = 0; i < w; i++) {
			swap(d[p2.first][p2.second], d[p3.first][p3.second]);
			go_right(p2), go_right(p3);
		}

		for (int i = 0; i < h; i++) {
			swap(r[p4.first][p4.second], r[p5.first][p5.second]);
			go_down(p4), go_down(p5);
		}

		for (int i = 0; i < h; i++) {
			swap(r[p6.first][p6.second], r[p7.first][p7.second]);
			go_down(p6), go_down(p7);
		}
	}

	for (int i = 1; i <= n; i++) {
		pair<int, int> p = {i, 0};
		for (int j = 1; j <= m; j++) {
			go_right(p);
			cout << v[p.first][p.second] << ' ';
		}
		cout << '\n';
	}
	return 0;
}