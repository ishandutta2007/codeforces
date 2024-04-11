#include <bits/stdc++.h>
using namespace std;

int n;
char c[500005];
double le[500005];
double mid[500005];
double ri[500005];


double getmid(int l, int r) {
	double midsum = mid[r+1] - mid[l];
	return midsum * (l + 1);
}
int main() {
	scanf("%s",c);
	n = strlen(c);
	for (int i = 1; i <= n; i++) {
		le[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		mid[i] = mid[i-1] + (1.0/i);
	}
	for (int i = n; i >= 1; i--) {
		ri[i] = ri[i+1] + (double(n + 1 -i) / double(i));
	}
	double res = 0;
	for (int i = 0; i < n; i++) {
		if (c[i] == 'E' || c[i] == 'Y' || c[i] == 'A' || c[i] == 'O' || c[i] == 'I' || c[i] == 'U') {
			int l = i;
			int r = n - i - 1;
			int sl = min(l,r);
			int sr = max(l,r);
			res += le[sl];
			res += ri[sr+2];
			res += getmid(sl,sr);
		}
	}
	printf("%.6lf\n", res);

}