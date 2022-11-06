#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
const double eps = 1e-10;
int n, w[maxn + 10], now[maxn + 10], lim[maxn + 10];
int t, q;
double ans;

struct data {
	int no, id, li;
	double v;
	bool operator < (const data &t) const {
		return v < t.v;
	}
};
priority_queue<data> a, b;

double calc(int v, int id) {
	return 1. * w[id] * v / (v + lim[id]);
}

void presolve() {
	for (int i = 1; i <= n; ++i)
		a.push((data){0, i, lim[i], calc(1, i) - calc(0, i)});
	while (t) {
		if (a.empty()) break;
		--t;
		data v = a.top(); a.pop();
		ans += v.v; ++now[v.id];
		if (now[v.id] < lim[v.id])
			a.push((data){now[v.id], v.id, lim[v.id], calc(now[v.id] + 1, v.id) - calc(now[v.id], v.id)});
	}
	for (int i = 1; i <= n; ++i)
		if (now[i]) b.push((data){now[i], i, lim[i], calc(now[i] - 1, i) - calc(now[i], i)});
}

void modify(int r) {
	if (now[r])
		b.push((data){now[r], r, lim[r], calc(now[r] - 1, r) - calc(now[r], r)});
	if (now[r] < lim[r])
		a.push((data){now[r], r, lim[r], calc(now[r] + 1, r) - calc(now[r], r)});
}

void adjust() {
	while (1) {
		while (!a.empty()) {
			data v = a.top();
			if (v.no == now[v.id] && v.li == lim[v.id]) break;
			a.pop();
		}
		while (!b.empty()) {
			data v = b.top();
			if (v.no == now[v.id] && v.li == lim[v.id]) break;
			b.pop();
		}
		if (t && !a.empty()) {
			--t;
			data v = a.top(); a.pop();
			ans += v.v; ++now[v.id];
			modify(v.id);
			continue;
		}
		if (!a.empty() && !b.empty()) {
			data x = a.top(), y = b.top();
			if (x.v + y.v < eps) break;
			ans += x.v + y.v;
			a.pop(); b.pop();
			++now[x.id]; --now[y.id];
			modify(x.id); modify(y.id);
			continue;
		}
		break;
	}
}

int main() {
	scanf("%d%d%d", &n, &t, &q);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &w[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &lim[i]);
	presolve();
	while (q--) {
		int tp, r; scanf("%d%d", &tp, &r);
		ans -= calc(now[r], r);
		if (tp == 1) ++lim[r];
		else {
			if (lim[r] > 1) --lim[r];
		}
		if (now[r] > lim[r]) {
			--now[r]; ++t;
		}
		ans += calc(now[r], r);
		modify(r);
		adjust();
		printf("%.10lf\n", ans);
	}
}