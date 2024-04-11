#pragma warning(disable:4996)

#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#define mp(a,b) make_pair(a,b)
#define PI 3.1415926535897932384626433832795

using namespace std;

typedef pair<double, int> pdi;
typedef pair<double, double> pdd;

int lna[2000];
int lnb[2000];
int lnc[2000];

const double eps = 1.0e-12;

double atan22(int a, int b) {
	if (b == 0) return PI / 2;
	else return atan(-(double)a / b);
}


inline double mod(double deg) {
	while (deg < 0) {
		deg += PI;
	}
	while (deg >= PI) {
		deg -= PI;
	}
	return deg;
}

pdd inter(int i, int j) {
	int det = lna[i] * lnb[j] - lnb[i] * lna[j];
	double x = (double)lnc[i] * lnb[j] - (double)lnc[j] * lnb[i];
	x /= det;
	double y = -(double)lnc[i] * lna[j] + (double)lnc[j] * lna[i];
	y /= det;
	return mp(x, y);
}

inline int iszero(double x) {
	return x > -eps && x < eps;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int cnt = 0;
	scanf("%d", &n);
	int j = 0; int zcnt = 0;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (c == 0) {
			zcnt++;
			continue;
		}
		lna[j] = a;
		lnb[j] = b;
		lnc[j] = c;
		j++;
	}
	if (zcnt == 2) {
		cnt += (n - 2);
	}
	n -= zcnt;

	for (int i = 0; i < n; i++) {
		vector<pdi> v;
		for (int j = i + 1; j < n; j++) {
			pdd in = inter(i, j);
			double slp1 = atan22(lna[j], lnb[j]);
			double slp2 = atan2(in.second,in.first);
			slp2 -= slp1;
			slp2 = mod(slp2);
			v.push_back(mp(slp2, j));
		}
		sort(v.begin(), v.end());
		double cur = -1;
		int tmpcnt = 0;
		for (auto &x : v) {
			if (iszero(x.first - cur)) {
				tmpcnt++;
			}
			else {
				cnt += (tmpcnt)*(tmpcnt - 1) / 2;
				tmpcnt = 1;
				cur = x.first;
			}
		}
		cnt += (tmpcnt)*(tmpcnt - 1) / 2;
	}
	printf("%d", cnt);

}