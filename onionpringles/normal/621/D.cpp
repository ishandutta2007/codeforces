#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <set>
#define mp make_pair
#define ni(n) scanf("%d", &(n))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

double dat[9];
double dat2[9];

const double eps = 1e-9;

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	double x, y, z;
	int maxind;
	scanf("%lf %lf %lf", &x, &y, &z);
	if (x <= 1 && y <= 1 && z <= 1) {
		dat[0] = pow(y, z) *log(x);
		dat[1] = pow(z, y)*log(x);
		dat[2] = y*z*log(x);
		dat[3] = pow(x, z)*log(y);
		dat[4] = pow(z, x)*log(y);
		dat[5] = z*x*log(y);
		dat[6] = pow(x, y)*log(z);
		dat[7] = pow(y, x)*log(z);
		dat[8] = y*x*log(z);

	}
	else {
		if (x <= 1) {
			dat[0] = dat[1] = dat[2] = -DBL_MAX;
		}
		else {
			dat[0] = z*log(y) + log(log(x));
			dat[1] = y*log(z) + log(log(x));
			dat[2] = log(y) + log(z) + log(log(x));


		}

		if (y <= 1) {
			dat[3] = dat[4] = dat[5] = -DBL_MAX;
		}
		else {
			dat[3] = z*log(x) + log(log(y));
			dat[4] = x*log(z) + log(log(y));
			dat[5] = log(x) + log(z) + log(log(y));
		}

		if (z <= 1) {
			dat[6] = dat[7] = dat[8] = -DBL_MAX;
		}
		else {
			dat[6] = y*log(x) + log(log(z));
			dat[7] = x*log(y) + log(log(z));
			dat[8] = log(y) + log(x) + log(log(z));

		}
	}
	double m = *max_element(dat, dat + 9);
	
	for (int i = 0; i < 9; i++) {
		if (fabs(dat[i] - m) < eps) {
			maxind = i;
			break;
		}
	}
	switch (maxind) {
	case 0:
		puts("x^y^z");
		break;
	case 1:
		puts("x^z^y");
		break;
	case 2:
		puts("(x^y)^z");
		break;
	case 3:
		puts("y^x^z");
		break;
	case 4:
		puts("y^z^x");
		break;
	case 5:
		puts("(y^x)^z");
		break;
	case 6:
		puts("z^x^y");
		break;
	case 7:
		puts("z^y^x"); break;
	case 8:
		puts("(z^x)^y");
	}
	return 0;
}