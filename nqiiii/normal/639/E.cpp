#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5;
int n;
ll now, tot;

struct data {
	int p, t;
	ll mn, mx;

	bool operator < (const data &o) const {
		return 1ll * t * o.p < 1ll * o.t * p;
	}
	bool operator == (const data &o) const {
		return !(o < *this) && !(*this < o);
	}

}a[maxn + 10];

bool cmp(const data &a, const data &b) {
	return a.p < b.p;
}

bool chk(double c) {
	double mx = -1e18;
	for (int i = 1, lst; i <= n; i = lst) {
		for (lst = i; lst <= n && a[lst].p == a[i].p; ++lst);
		for (int j = i; j < lst; ++j)
			if (a[j].p * (1 - 1. * c / tot * a[j].mx) < mx) return 0;
		for (int j = i; j < lst; ++j)
			mx = max(mx, a[j].p * (1 - 1. * c / tot * a[j].mn));
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i].p);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].t); tot += a[i].t;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1, lst; i <= n; i = lst) {
		for (lst = i; lst <= n && a[lst] == a[i]; ++lst);
		ll sum = 0;
		for (int j = i; j < lst; ++j) sum += a[j].t;
		for (int j = i; j < lst; ++j) {
			a[j].mn = now + a[j].t;
			a[j].mx = now + sum;
		}
		now += sum;
	}
	sort(a + 1, a + n + 1, cmp);
	double l = 0, r = 1;
	while (r - l >= 1e-7) {
		double mid = (l + r) / 2;
		if (chk(mid)) l = mid;
		else r = mid;
	}
	printf("%.10lf", l);
}