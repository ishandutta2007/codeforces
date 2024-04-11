//sobskdrbhvk
//remeber... ):(
#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

const int maxn = 100 * 1000 + 10;
LD x[maxn],
   y[maxn];
int n;

bool check(LD rad) {
	LD lans = -1e18,
	   rans = +1e18;
	for (int i = 0; i < n; i++) {
		if (y[i] > 2 * rad)
			return false;
		LD len = 2 * rad * y[i] - y[i] * y[i];
		if (len < 0)
			return false;
		len = sqrt(len);
		LD le = x[i] - len;
		LD ri = x[i] + len;
		smax(lans, le);
		smin(rans, ri);
		if (lans > rans)
			return false;
	}
	return true;
}

int main() {
	cin >> n;
	bool neg = false,
		 pos = false;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		if (y[i] < 0)
			neg = true;
		if (y[i] > 0)
			pos = true;
	}
	if (neg and pos)
		return cout << -1 << endl, 0;
	if (neg)
		for (int i = 0; i < n; i++)
			y[i] = -y[i];
	LD lo = 0,
	   hi = +1e18 + 100;
	for (int _ = 0; _ < 100; _++) {
		LD mid = (lo + hi) / 2.;
		if (check(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout.precision(10);
	cout << fixed << hi << endl;
	return 0;
}