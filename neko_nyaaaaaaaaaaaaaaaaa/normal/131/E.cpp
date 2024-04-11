#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans[20];

int row[2][200008];
int col[2][200008];
int dia[2][200008];
int di2[2][200008];

void update(int x, int y) {
	row[0][x] = min(row[0][x], y);
	row[1][x] = max(row[1][x], y);
	
	col[0][y] = min(col[0][y], x);
	col[1][y] = max(col[1][y], x);
	
	dia[0][x + y] = min(dia[0][x + y], x);
	dia[1][x + y] = max(dia[1][x + y], x);
	
	di2[0][n + x - y] = min(di2[0][n + x - y], y);
	di2[1][n + x - y] = max(di2[1][n + x - y], y);
}

int query(int x, int y) {
	int cnt = 0;
	
	cnt += y > row[0][x];
	cnt += y < row[1][x];
	
	cnt += x > col[0][y];
	cnt += x < col[1][y];
	
	cnt += x > dia[0][x + y];
	cnt += x < dia[1][x + y];
	
	cnt += y > di2[0][n + x - y];
	cnt += y < di2[1][n + x - y];
	
	return cnt;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	fill(row[0], row[0] + 200008, 1e9);
	fill(col[0], col[0] + 200008, 1e9);
	fill(dia[0], dia[0] + 200008, 1e9);
	fill(di2[0], di2[0] + 200008, 1e9);
  
	cin >> n >> m;
	vector<int> x(m), y(m);
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i];
		update(x[i], y[i]);
	}
	for (int i = 0; i < m; i++) {
		ans[query(x[i], y[i])]++;
	}
	for (int i = 0; i <= 8; i++) {
		cout << ans[i] << " ";
	}
	
	return 0;
}