#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MN = 200000;

int a[MN];
double sum[MN + 1];
int n;

double f(double x) {
	sum[0] = 0;
	double curmin = 0;
	double curmax = 0;

	for (int i = 0; i < n; i++) {
		sum[i + 1] = sum[i] + (a[i] - x);
		curmin = min(curmin, sum[i + 1]);
		curmax = max(curmax, sum[i + 1]);
	}
	return curmax- curmin;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	double l = -10000;
	double u = 10000;
	for (int i = 0; i < 150; i++) {
		double left = (2 * l + u) / 3;
		double right = (2 * u + l) / 3;
		double fleft = f(left);
		double fright = f(right);
		if (fleft < fright) {
			u = right;
		}
		else {
			l = left;
		}
	}
	printf("%.15f", f((l + u) / 2));
	return 0;
}