#define ll long long
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct point
{
	int x, y;
	point operator-(const point& z) const
	{
		point a;
		a.x = x - z.x;
		a.y = y - z.y;
		return a;
	}
	ll operator ^(const point& z) const
	{
		return static_cast<ll>(x) * z.y - static_cast<ll>(y) * z.x;
	}
	double lth() const
	{
		return sqrt(static_cast<double>(x) * x + static_cast<double>(y) * y);
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<point> p(n);
	vector<vector<point>> diff(n);
	vector<vector<double>> lths(n);
	double M = 100000000000ll;
	for (int i = 0; i < n; ++i)
		cin >> p[i].x >> p[i].y;
	for (int i = 0; i < n; ++i)
	{
		diff[i].resize(n);
		lths[i].resize(n);
		for (int j = 0; j < n; ++j)
		{
			diff[i][j] = p[i] - p[j];
			lths[i][j] = diff[i][j].lth();
		}
	}
	for (int i = 1; i < n; ++i)
	//for (int j = 1; j < i; ++j)
	for (int j = i - 1, k = 0; k < n; ++k)
	{
		if ((j != i) && (j != k) && (i != k))
		{
			ll two_s = abs(diff[i][j] ^ diff[i][k]);
			double t = two_s / max(max(lths[i][j], lths[i][k]), lths[j][k]);
			if (t < M)
				M = t;
		}
	}
	cout << setprecision(10) << setiosflags(ios::fixed) << M / 2 << endl;
	//system("pause");
	return 0;
}

/*
4
0 0
0 1
1 1
1 0

6
5 0
10 0
12 -4
10 -8
5 -8
3 -4
*/