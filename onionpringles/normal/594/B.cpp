#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <math.h>
#define PI 3.1415926535897932384626433832795

using namespace std;

inline double ff(double x) {
	return x - sin(x);
}

double finv(double x) {
	double l = 0;
	double u = 2*PI;
	for (int i = 0; i < 100; i++) {
		double m = (l + u) / 2;
		if (ff(m) > x) {
			u = m;
		}
		else l = m;
	}
	return (u + l) / 2;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, r, v;
	scanf("%d %d %d", &n, &r, &v);
	double w = (double)v / r;
	for (int i = 0; i < n; i++) {
		int s, f;
		scanf("%d %d", &s, &f);
		double dist = ((double)f - s)/r;
		int q = (int)floor(dist / 2/PI);
		double rem = dist - q*2*PI;

		//printf("%d\n", q);
		
		double p1 = finv(rem / 2);
		//printf("%f\n", ff(p1));
		p1 = p1*2 + q*2*PI;
		

		double p2 = finv((2*PI - rem) / 2);
		//printf("%f\n", ff(p2));
		p2 = (q + 1)*2*PI - 2 * p2;
		//printf("%f %f\n", p1/w, p2/w);
		printf("%.15f\n", min(p1, p2)/w);
	}
	return 0;
}