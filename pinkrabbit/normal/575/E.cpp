#include <cstdio>
#include <cmath>
#include <algorithm>

typedef long long LL;
const int V = 100000;
const int MN = 100005;

struct point {
	int x, y;
	point(int X = 0, int Y = 0) : x(X), y(Y) {}
	friend point operator - (point a, point b) { return point(a.x - b.x, a.y - b.y); }
	friend LL operator / (point a, point b) { return (LL)a.x * b.y - (LL)a.y * b.x; }
	LL len() { return (LL)x * x + (LL)y * y; }
	void print() { printf("%d %d\n", x, y); }
};

int N, cnt, top;
point p[MN * 6];
void Add(int x, int y) { p[++cnt] = point(x, y); }
point c[MN * 6];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		if (x < v) Add(0, std::max(y - v + x, 0)), Add(0, std::min(y + v - x, V));
		else Add(x - v, y);
		if (y < v) Add(std::max(x - v + y, 0), 0), Add(std::min(x + v - y, V), 0);
		else Add(x, y - v);
		if (x > V - v) Add(V, std::max(y - x - v + V, 0)), Add(V, std::min(y + x + v - V, V));
		else Add(x + v, y);
		if (y > V - v) Add(std::max(x - y - v + V, 0), V), Add(std::min(x + y + v - V, V), V);
		else Add(x, y + v);
	}
	std::sort(p + 1, p + cnt + 1, [](point a, point b) {
		return a.y == b.y ? a.x < b.x : a.y < b.y;
	});
	cnt = std::unique(p + 1, p + cnt + 1, [](point a, point b) {
		return a.x == b.x && a.y == b.y;
	}) - p - 1;
	std::sort(p + 2, p + cnt + 1, [](point a, point b) {
		LL cr = (a - p[1]) / (b - p[1]);
		return cr == 0 ? (a - p[1]).len() < (b - p[1]).len() : cr > 0;
	});
	c[1] = p[1], c[top = 2] = p[2];
	for (int i = 3; i <= cnt; ++i) {
		while (top > 1 && (p[i] - c[top - 1]) / (c[top] - c[top - 1]) >= 0) --top;
		c[++top] = p[i];
	}
	c[0] = c[top], c[top + 1] = c[1];
	double ans = 0; int a = 0;
	for (int i = 1; i <= top; ++i) {
		point x = c[i - 1] - c[i], y = c[i + 1] - c[i], z = c[i + 1] - c[i - 1];
		double rad = sqrt(x.len()) * sqrt(y.len()) * sqrt(z.len()) / (y / x * 2);
		if (rad > ans) ans = rad, a = i;
	}
	c[a - 1].print(), c[a].print(), c[a + 1].print();
	return 0;
}