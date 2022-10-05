#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m, k, vr[1001][1001], vc[1001][1001], d[1001][1001];
string t[1001];
queue<pair<int, int>> q;

void fillr(int x, int y) {
	if (vr[x][y]) return;
	vr[x][y] = 1;
	int p = y - 1;
	while (p >= 0 && t[x][p] != '#') {
		if (d[x][p] == -1)
			d[x][p] = d[x][y] + (y - p + k - 1) / k, q.push({ x, p });
		p--, vr[x][p] = 1;
	}
	p = y + 1;
	while (p < m && t[x][p] != '#') {
		if (d[x][p] == -1)
			d[x][p] = d[x][y] + (p - y + k - 1) / k, q.push({ x, p });
		p++, vr[x][p] = 1;
	}
}
void fillc(int x, int y) {
	if (vc[x][y]) return;
	vc[x][y] = 1;
	int p = x - 1;
	while (p >= 0 && t[p][y] != '#') {
		if (d[p][y] == -1)
			d[p][y] = d[x][y] + (x - p + k - 1) / k, q.push({ p, y });
		p--, vc[p][y] = 1;
	}
	p = x + 1;
	while (p < n && t[p][y] != '#') {
		if (d[p][y] == -1)
			d[p][y] = d[x][y] + (p - x + k - 1) / k, q.push({ p, y });
		p++, vc[p][y] = 1;
	}
}

int main() {
	fast;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> t[i];

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) d[i][j] = -1, vr[i][j] = vc[i][j] = 0;

	int x, y;
	cin >> x >> y;
	q.push({ x - 1, y - 1 }), d[x - 1][y - 1] = 0;
	while (!q.empty()) {
		fillr(q.front().first, q.front().second);
		fillc(q.front().first, q.front().second);
		q.pop();
	}
	cin >> x >> y;
	cout << d[x - 1][y - 1] << endl;
}