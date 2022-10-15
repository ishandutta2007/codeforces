/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

struct point {
	int x, y;
};

struct fenw {
	vector<int> a;
	int n;
	fenw(int n): a(n), n(n) {

	}

	void add(int x, int y) {
		for (int i = x; i < n; i |= i + 1) a[i] += y;
	}

	int get(int x) {
		int ret = 0;
		for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
			ret += a[i];
		}
		return ret;
	}

	int get(int left, int right) {
		return get(right - 1) - get(left - 1);
	}
};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	vector<point> p(n);
	vector<int> xs(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		xs[i] = p[i].x;
	}
	sort(xs.begin(), xs.end());
	xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
	for (int i = 0; i < n; i++) {
		p[i].x = (int) (lower_bound(xs.begin(), xs.end(), p[i].x) - xs.begin());
	}
	vector<int> count(xs.size());
	for (int i = 0; i < n; i++) {
		count[p[i].x]++;
	}
	fenw f((int) xs.size());
	for (int i = 0; i < (int) xs.size(); i++) {
		f.add(i, 1);
	}
	sort(p.begin(), p.end(), [](point const &a, point const &b) {
		if (a.y != b.y) return a.y < b.y;
		return a.x < b.x;
	});
	long long ans = 0;
	for (int i = 0; i < n; ) {
		int j = i;
		while (j < n && p[i].y == p[j].y) {
			++j;
		}
		int last = -1;
		for (int k = i; k < j; k++) {
			if (p[k].x != last) {
				ans += (long long) f.get(last + 1, p[k].x + 1) * f.get(p[k].x, (int) xs.size());
			}
			last = p[k].x;
		}
		while (i < j) {
			int x = p[i++].x;
			count[x]--;
			if (count[x] == 0) {
				f.add(x, -1);
			}
		}
	}
	cout << ans << endl;
}