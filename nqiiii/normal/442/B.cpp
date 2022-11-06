#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5;
int n;
double a[maxn + 10];
double f0 = 1, f1;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%lf", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; --i) {
		double w = f1 * (1 - a[i]) + f0 * a[i];
		if (w > f1) {
			f1 = f1 * (1 - a[i]) + f0 * a[i];
			f0 = f0 * (1 - a[i]);
		}
	}
	printf("%.10lf", f1);
}