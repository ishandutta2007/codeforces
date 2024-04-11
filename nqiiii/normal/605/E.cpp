#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int n;
double a[maxn + 10][maxn + 10], f[maxn + 10];
double e[maxn + 10], np[maxn + 10];
bool vis[maxn + 10];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			scanf("%lf", &a[i][j]); a[i][j] /= 100;
		}
	for (int i = 1; i <= n; ++i) {
		np[i] = 1; e[i] = 0;
	}
	for (int i = 0; i <= n; ++i)
		f[i] = i == n ? 0 : 1. / 0.;
	for (int i = 1; i <= n; ++i) {
		int p = 0;
		for (int j = 1; j <= n; ++j)
			if (!vis[j] && f[j] < f[p]) p = j;
		vis[p] = 1;
		for (int j = 1; j <= n; ++j)
			if (!vis[j] && f[p] < f[j]) {
				e[j] += np[j] * a[j][p] * (f[p] + 1);
				np[j] *= (1 - a[j][p]);
				f[j] = (e[j] + np[j]) / (1 - np[j]);
			}
	}
	printf("%.10lf", f[1]);
}