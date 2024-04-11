
#include <bits/stdc++.h>

using namespace std;

long long const INF = 1LL << 60;

struct rect {
	int x, y;
	long long a;
};

struct line {
	long long a, b;
};

vector<line> lines;

void add(long long a, long long b) {
	line l = {a, b};
	while (lines.size() > 1) {
		auto &c = lines[lines.size() - 2];
		auto &d = lines.back();
		// long long q, p;
		// q = (d.b - c.b);
		// p = (c.b - l.b);
		long double dif = 1. * (d.b - c.b) * (l.a - c.a) - 1. * (c.b - l.b) * (c.a - d.a);
		if (dif >= 0) {
			lines.pop_back();
		} else break;
	}
	lines.push_back(l);
}

long long get(long long x) {
	int l = -1;
	int r = (int) lines.size() - 1;
	while (l < r - 1) {
		int mid = (l + r) >> 1;
		auto &e = lines[mid];
		auto &f = lines[mid + 1];
		if (x * (e.a - f.a) >= (f.b - e.b)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	return lines[r].a * x + lines[r].b;
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<rect> a(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		long long z;
		cin >> x >> y >> z;
		a[i] = {x, y, z};
	}
	sort(a.begin(), a.end(), [](rect const &a, rect const &b) {
		return a.x < b.x;
	});
	add(0, 0);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long value = get(a[i].y) + (long long) a[i].x * a[i].y - a[i].a;
		ans = std::max(ans, value);
		add(-a[i].x, value);
	}
	cout << ans << endl;
}