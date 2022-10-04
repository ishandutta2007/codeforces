#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef pair<int, int> pii;

double solve_quad(double a, double b, double c) {
	if (a<0) {
		a = -a;
		b = -b;
		c = -c;
	}
	double disc = b*b - 4 * a*c;
	disc = sqrt(disc);
	if (-b - disc<0) return (-b + disc) / a / 2;
	else return (-b - disc) / a / 2;
}

double dist(double x1, double y1, double x2, double y2) {
	double dx = x1 - x2;
	double dy = y1 - y2;
	return sqrt(dx*dx + dy*dy);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x1, x2, y1, y2, vm, t, vx, vy, ux, uy;
	scanf("%d %d %d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &vm, &t, &vx, &vy, &ux, &uy);
	if (dist(x1 + t*vx, y1 + t*vy, x2, y2) < t*vm) {
		printf("%.15f", solve_quad(vx*vx + vy*vy - vm*vm, 2 * vx*(x1 - x2) + 2 * vy*(y1 - y2), (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
	}
	else {
		double xc = x1 + t*vx-x2;
		double yc = y1 + t*vy-y2;
		double r = t*vm;
		printf("%.15f", t + solve_quad(ux*ux + uy*uy - vm*vm, 2 * ux*xc + 2 * uy*yc - 2 *r*vm, xc*xc + yc*yc - r*r));
	}
}