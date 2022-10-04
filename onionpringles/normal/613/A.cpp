#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <vector>
#define mp(a,b) make_pair(a,b)
#define ni(a) scanf("%d", &(a))
#define F(i,n) for(int (i) = 0; (i) < (n); (i)++)

using namespace std;

const double pi = 3.1415926535897932384626433832795;

long long dists[100000];
double mindist[100000];
int x[100000];
int y[100000];

long long dist(int x1, int y1, int x2, int y2) {
	long long dx = x2 - x1;
	long long dy = y2 - y1;
	return dx*dx + dy*dy;
}

double dist2(double x1, double y1, double x2, double y2) {
	double dx = x1 - x2;
	double dy = y1 - y2;
	return dx*dx + dy*dy;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, xx, yy;
	scanf("%d %d %d", &n, &xx, &yy);
	for (int i = 0; i < n; i++) {
		ni(x[i]); ni(y[i]);
		dists[i] = dist(xx, yy, x[i], y[i]);
	}
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		double l = 0; double u = 1;
		for (int k = 0; k < 70; k++) {
			double m1 = (11 * l + 10 * u) / 21;
			double m2 = (10 * l + 11 * u) / 21;
			double fm1 = dist2(m1*x[i] + (1 - m1)*x[j], m1*y[i] + (1 - m1)*y[j], xx, yy);
			double fm2 = dist2(m2*x[i] + (1 - m2)*x[j], m2*y[i] + (1 - m2)*y[j], xx, yy); 
			if (fm1 > fm2) {
				l = m1;
			}
			else u = m2;
		}
		double m = (l + u) / 2;
		mindist[i] = dist2(m*x[i] + (1 - m)*x[j], m*y[i] + (1 - m)*y[j], xx, yy);
	}
	sort(dists, dists + n);
	sort(mindist, mindist + n);
	printf("%.15f", pi*(dists[n - 1] - mindist[0]));
	return 0;
}