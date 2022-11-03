#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
constexpr long double PI = std::acos(-1.0L);
int main() {
	int n = ri();
	std::pair<long double, int> pts[n];
	for (int i = 0; i < n; i++) {
		int x = ri();
		int y = ri();
		pts[i].first = std::atan2((long double) y, (long double) x);
		if (pts[i].first < 0) pts[i].first += 2 * PI;
		pts[i].second = i;
	}
	std::sort(pts, pts + n);
	long double min = 2 * PI + pts[0].first - pts[n - 1].first;
	std::pair<int, int> res{pts[0].second, pts[n - 1].second};
	for (int i = 0; i + 1 < n; i++) if (min > pts[i + 1].first - pts[i].first)
		min = pts[i + 1].first - pts[i].first, res = {pts[i].second, pts[i + 1].second};
	printf("%d %d\n", res.first + 1, res.second + 1);
	return 0;
}