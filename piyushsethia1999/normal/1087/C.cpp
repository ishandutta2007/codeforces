#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;
int x[3], y[3];

int man(int x1, int y1, int i) {
	return (abs(x[i] - x1) + abs(y[i] - y1));
}

std::vector<std::vector<bool> > fi(1001, std::vector<bool> (1001, false));

void pp(int h, int k) {
	cout << h << " " << k << "\n";
}

void filll(int x1, int y1, int x2, int y2) {
	int yy = y1;
	for (int i = min(x1, x2); i <= max(x2, x1); ++i)
	{
		if (!fi[i][yy])
		{
			fi[i][yy] = true;
			pp(i, yy);
		}
	}
	int xx = x2;
	for (int j = min(y1, y2); j <= max(y2, y1); ++j)
	{
		if (!fi[xx][j])
		{
			fi[xx][j] = true;
			pp(xx, j);
		}
	}
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	for (int i = 0; i < 3; ++i)
		cin >> x[i] >> y[i];
	int k, l;
	k = l = -1;
	int d = 10000000;
	for (int i = 0; i <= 1000; ++i)
	{
		for (int j = 0; j <= 1000; ++j)
		{
			if ((man(i, j, 0) + man(i, j, 1) + man(i, j, 2)) < d) {
				k = i; l = j;
				d = (man(i, j, 0) + man(i, j, 1) + man(i, j, 2));
			}
		}
	}
	cout << (man(k, l, 0) + man(k, l, 1) + man(k, l, 2) + 1) << "\n";
	for (int i = 0; i < 3; ++i)
		filll(x[i], y[i], k, l);
}