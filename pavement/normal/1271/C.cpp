#include <bits/stdc++.h>
using namespace std;
#define int long long

int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
pair<int, int> p[200005];

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y, mcnt = 0, ansx, ansy;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k], cnt = 0;
		for (int i = 0; i < n; i++)
			if (abs(nx - p[i].first) + abs(ny - p[i].second) + 1 == abs(x - p[i].first) + abs(y - p[i].second)) cnt++;
		if (cnt > mcnt) {
			mcnt = cnt;
			ansx = nx;
			ansy = ny;
		}
	}
	cout << mcnt << '\n' << ansx << ' ' << ansy << '\n';
}