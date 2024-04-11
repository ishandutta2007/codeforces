#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#define mp(a,b) make_pair(a,b)

using namespace std;

typedef pair<int, int> pii;
typedef pair<double, double> pdd;

pii lns[100000];
pdd dyn[100001];
int dynp = 0;

inline void push(pdd x) {
	dyn[dynp++] = x;
}

inline void resize(int n) {
	dynp = n;
}

inline pdd last() {
	return dyn[dynp - 1];
}

inline pdd inter(pii ln, pdd a, pdd b) {
	double coeff = ln.first*(b.first - a.first) + ln.second*(b.second - a.second);
	double cons = 1 - ln.first*a.first - ln.second*a.second;
	double t = cons / coeff;
	return mp(a.first + t*(b.first - a.first), a.second + t*(b.second - a.second));
}

int main() {
//	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, p, q;
	scanf("%d %d %d", &n, &p, &q);
	for (int i = 0; i<n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		lns[i] = mp(a, b);
	}
	sort(lns, lns + n, [](const pii &x, const pii &y)->bool {return (long long)x.first*y.second<(long long)x.second*y.first; });
	push(mp(0, 1.0 / lns[0].second));
	push(mp(1.0 / lns[0].first, 0));
	int xrec = lns[0].first;
	int yrec = lns[0].second;
	for (int i = 1; i<n; i++) {
		if (xrec >= lns[i].first && yrec >= lns[i].second) {
			continue;
		}
		if (xrec <= lns[i].first && yrec <= lns[i].second) {
			resize(0);
			push(mp(0, 1.0 / lns[i].second));
			push(mp(1.0 / lns[i].first, 0));
			xrec = lns[i].first;
			yrec = lns[i].second;
			continue;
		}
		int l = 0;
		int u = dynp - 1;
		while (l != u) {
			int m = (l + u) / 2;
			if (lns[i].first*dyn[m].first + lns[i].second*dyn[m].second >= 1) {
				u = m;
			}
			else l = m + 1;
		}
		resize(l);
		push(inter(lns[i], dyn[l - 1], dyn[l]));
		push(mp(1.0 / lns[i].first, 0));
		xrec = lns[i].first;
	}

	double _max = -1;
	for (int i = 0; i<dynp; i++) {
		_max = max(_max, p*dyn[i].first + q*dyn[i].second);
	}
	printf("%.15f", _max);
}