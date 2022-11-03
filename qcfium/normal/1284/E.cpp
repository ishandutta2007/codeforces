#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
const double PI = acos(-1.0);

struct Vec {
	int x;
	int y;
	bool more;
	double atan2;
	void update() {
		atan2 = std::atan2(y, x);
		if (atan2 < 0) atan2 += 2 * PI;
	}
};

struct Comp {
	bool operator () (Vec a, Vec b) {
		if (a.more != b.more) return a.more < b.more;
		if (std::abs(a.atan2 - b.atan2) > 0.2) return a.atan2 < b.atan2;
		else return (int64_t) a.y * b.x < (int64_t) b.y * a.x;
	}
};

int main() {
	int n = ri();
	int x[n], y[n];
	for (int i = 0; i < n; i++) x[i] = ri(), y[i] = ri();
	int64_t res = 0;
	for (int i = 0; i < n; i++) {
		std::vector<Vec> all;
		for (int j = 0; j < n; j++) if (i != j) all.push_back({x[j] - x[i], y[j] - y[i], false});
		for (auto &i : all) i.update();
		std::sort(all.begin(), all.end(), Comp());
		for (int j = 0; j + 1 < n; j++) all.push_back({all[j].x, all[j].y, true});
		for (auto &i : all) i.update();
		res += (int64_t) (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
		for (int j = 0; j + 1 < n; j++) {
			auto next = all[j];
			if (next.y < 0 || (next.y == 0 && next.x < 0)) next.more = true;
			next.x *= -1;
			next.y *= -1;
			next.update();
			int num = (all.begin() + j + n - 1) - std::upper_bound(all.begin(), all.end(), next, Comp());
			if (num >= 3) res -= (int64_t) num * (num - 1) * (num - 2) / 6;
		}
	}
	std::cout << res << std::endl;
	return 0;
}