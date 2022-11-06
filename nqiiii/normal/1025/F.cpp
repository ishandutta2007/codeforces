#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2000;
const double pi = acos(-1);
int n, x[maxn + 10], y[maxn + 10], acnt;
double a[maxn * 2 + 10];
ll ans;

ll calc(ll x) {
	return x * (x - 1) / 2;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &x[i], &y[i]);
	for (int i = 1; i <= n; ++i) {
		acnt = 0;
		for (int j = 1; j <= n; ++j)
			if (i != j) a[++acnt] = atan2(y[j] - y[i], x[j] - x[i]);
		sort(a + 1, a + acnt + 1);
		for (int j = 1; j <= acnt; ++j)
			a[j + acnt] = a[j] + pi * 2;
		for (int j = 1, p = 1; j <= acnt; ++j) {
			while (a[p] - a[j] < pi) ++p;
			ans += calc(p - j - 1) * calc(acnt - p + j);
		}
	}
	printf("%lld", ans / 2);
}