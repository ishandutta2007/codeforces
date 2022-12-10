//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 1e5;
int ix[maxn],
	iy[maxn],
	n;

int bsx(int y) {
	int lo = 0,
		hi = n;
	while (hi - lo > 1) {
		int mid = (lo + hi) >> 1;
		cout << "? 1 1 " << mid << ' ' << y << endl;
		int result;
		cin >> result;
		if (result & 1)
			hi = mid;
		else
			lo = mid;
	}
	return lo;
}

int bsy(int x) {
	int lo = 0,
		hi = n;
	while (hi - lo > 1) {
		int mid = (lo + hi) >> 1;
		cout << "? 1 1 " << x << ' ' << mid << endl;
		int result;
		cin >> result;
		if (result & 1)
			hi = mid;
		else
			lo = mid;
	}
	return lo;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i + 1 < n; i++) {
		cout << "? 1 1 " << n << ' ' << i + 1 << endl;
		cin >> iy[i];
		iy[i] &= 1;
		cout << "? 1 1 " << i + 1 << ' ' << n << endl;
		cin >> ix[i];
		ix[i] &= 1;
	}
	if (find(iy, iy + n, 1) == iy + n) {
		int x = find(ix, ix + n, 1) - ix;
		int xx = find(ix + x, ix + n, 0) - ix;
		int y = bsy(x + 1) + 1;
		cout << "! " << x + 1 << ' ' << y << ' ' << xx + 1 << ' ' << y << endl;
		return 0;
	}
	if (find(ix, ix + n, 1) == ix + n) {
		int y = find(iy, iy + n, 1) - iy;
		int yy = find(iy + y, iy + n, 0) - iy;
		int x = bsx(y + 1) + 1;
		cout << "! " << x << ' ' << y + 1 << ' ' << x << ' ' << yy + 1 << endl;
		return 0;
	}

	int x = find(ix, ix + n, 1) - ix;
	int xx = find(ix + x, ix + n, 0) - ix;
	int y = find(iy, iy + n, 1) - iy;
	int yy = find(iy + y, iy + n, 0) - iy;
	x++, y++, xx++, yy++;

	cout << "? " << x << ' ' << y << ' ' << x << ' ' << y << endl;
	int result;
	cin >> result;
	if (result & 1)
		cout << "! " << x << ' ' << y << ' ' << xx << ' ' << yy << endl;
	else
		cout << "! " << x << ' ' << yy << ' ' << xx << ' ' << y << endl;

	return 0;
}