#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <set>
#include <map>
#include <random>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>

typedef long long ll;
typedef long double ld;
using namespace std;

struct pt {
	int x, y;
	pt() : x(0), y(0) {}
	pt(int x, int y) : x(x), y(y) {}

	pt rot() {
		return {y, -x};
	}
	pt operator+(pt p) {
		return {x + p.x, y + p.y};
	}
	pt operator-(pt p) {
		return {x - p.x, y - p.y};
	}
};

const int N = 20;
int a[N][N], used[N][N];
int n, m;
vector<vector<int>> ans;
void c(vector<pt> w) {
	ans.emplace_back();	
	for (pt p : w)
		ans.back().push_back(a[p.x][p.y]);
	int t = a[w.back().x][w.back().y];
	for (int i = (int) w.size() - 1; i > 0; i--) {
		a[w[i].x][w[i].y] = a[w[i - 1].x][w[i - 1].y];
	}
	a[w[0].x][w[0].y] = t;
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
}

void cyc(pt a1, pt a2, pt a4) {
	pt a3 = a2 + a2 - a1;
	pt v = a4 - a1;
	pt a6 = a3 + v;
	pt a5 = a2 + v;
	c({a1, a2, a5, a4});
	c({a2, a3, a6, a5});
	c({a4, a5, a6, a3, a2, a1});
}

void sw(pt a1, pt a2) {
	pt a3 = a2 + a2 - a1;
	if (a3.x < 0 || a3.x >= n || a3.y < 0 || a3.y >= m)
		swap(a1, a2);
	pt v = (a1 - a2).rot(), a4 = a1 + v;
	if (a4.x < 0 || a4.x >= n || a4.y < 0 || a4.y >= m)
		a4 = a1 - v;
	cyc(a1, a2, a4);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i < n * m; i++) {
		pt p1, p2 = {i / m, i % m};
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				if (a[j][k] == i + 1) {
					p1 = {j, k};
				}
		int cx, cy, nx = i / m, ny = i % m;
		while (p1.y < p2.y) {
			if (p1.x < n - 1)
				c({p1, p1 + pt(0, 1), p1 + pt(1, 1), p1 + pt(1, 0)});
			else if (p1.x > p2.x + 1)
				c({p1, p1 + pt(0, 1), p1 + pt(-1, 1), p1 + pt(-1, 0)});
			else
				sw(p1, p1 + pt(0, 1));
			p1.y++;
		}
		while (p1.y > p2.y) {
			if (p1.x < n - 1)
				c({p1, p1 + pt(0, -1), p1 + pt(1, -1), p1 + pt(1, 0)});
			else if (p1.x > p2.x + 1)
				c({p1, p1 + pt(0, -1), p1 + pt(-1, -1), p1 + pt(-1, 0)});
			else
				sw(p1, p1 + pt(0, -1));
			p1.y--;
		}
		while (p1.x > p2.x) {
			if (p1.y < m - 1)
				c({p1, p1 + pt(-1, 0), p1 + pt(-1, 1), p1 + pt(0, 1)});
			else
				sw(p1, p1 - pt(1, 0));
			p1.x--;
		}
		used[p2.x][p2.y] = 1;
	}
	cout << ans.size() << '\n';
	for (auto &f : ans) {
		cout << f.size() << ' ';
		for (int i : f)
			cout << i << ' ';
		cout << '\n';
	}
}