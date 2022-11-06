#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

pair<int, int> co(int x, int y, int x1, int y1)
{
	int s1 = x1 - x + 1;
	int s2 = y1 - y + 1;
	if ((s1 * s2) % 2 == 0)
	{
		return {(s1 * s2) / 2, (s1 * s2) / 2};
	}
	else
	{
		if ((x - y) % 2 == 0)
		{
			return {(s1 * s2) / 2 + 1, (s1 * s2) / 2};
		}
		return {(s1 * s2) / 2, (s1 * s2) / 2 + 1};
	}
}

pair<int, int> mi(pair<int, int> p1, pair<int, int> p2)
{
	return {p1.first - p2.first, p1.second - p2.second};
}
pair<int, int> pl(pair<int, int> p1, pair<int, int> p2)
{
	return {p1.first + p2.first, p1.second + p2.second};
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		int m; cin >> m;
		int x1; cin >> x1;
		int y1; cin >> y1;
		int x2; cin >> x2;
		int y2; cin >> y2;
		int x3; cin >> x3;
		int y3; cin >> y3;
		int x4; cin >> x4;
		int y4; cin >> y4;
		pair<int, int> tt = co(1, 1, n, m);
		pair<int, int> b1n = co(x1, y1, x2, y2);
		pair<int, int> b2n = co(x3, y3, x4, y4);
		pair<int, int> b1w = {(x2 - x1 + 1) * (y2 - y1 + 1), 0};
		pair<int, int> b2b = {0, (x4 - x3 + 1) * (y4 - y3 + 1)};

		int xp2 = min(x2, x4);
		int xp1 = max(x1, x3);
		int yp2 = min(y2, y4);
		int yp1 = max(y1, y3);

		pair<int, int> b3n = co(xp1, yp1, xp2, yp2);
		pair<int, int> b3w = {(xp2 - xp1 + 1) * (yp2 - yp1 + 1), 0};

		if (xp1 > xp2 || yp1 > yp2)
		{
			b3n = {0, 0};
			b3w = {0, 0};
		}

		auto res = mi(tt, b1n);
		res = mi(res, b2n);
		res = pl(res, b3n);
		res = pl(res, b2b);
		res = pl(res, b1w);
		res = mi(res, b3w);
		cout << res.first << " " << res.second << "\n";
	}
}