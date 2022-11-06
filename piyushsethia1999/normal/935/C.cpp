#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define ld long double

using namespace std;

ld calcdi(int x, int y) {
	ld X = x;
	ld Y = y;
	return sqrt(X * X + Y * Y);
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
#ifdef PIYUSH_HOME
	I_O;
#else
#define print(...) 0
#endif
	ld R; cin >> R;
	int x1; cin >> x1;
	int y1; cin >> y1;
	int x2; cin >> x2;
	int y2; cin >> y2;
	if (x1 == x2 && y1 == y2)
	{
		ld x = (ld)(x1) + R / (ld)2;
		ld r = R / (ld)2;
		cout << x << " " << y1 << " " << r;
		exit(0);
	}
	print(R);
	print(x1, y1);
	print(x2, y2);
	print(R);
	ld d = calcdi(x1 - x2, y1 - y2);
	print(d);
	if (d < (ld)R) {
		ld X1 = x1;
		ld X2 = x2;
		ld Y1 = y1;
		ld Y2 = y2;
		ld tw = 2;
		ld r = (R + d) / tw;
		ld x = ((X1 * r) - (X2 * ((R - d) / tw))) / (d);
		ld y = ((Y1 * r) - (Y2 * ((R - d) / tw))) / (d);
		cout << x << " " << y << " " << r;
	}
	else
		cout << x1 << " " << y1 << " " << R;
}