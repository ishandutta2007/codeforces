#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef double db;
const db eps = 1e-9;
const int N = 2e3 + 10;

struct Point {
	db x, y;
}	s, mid2, a[N];

inline Point operator + (Point a, Point b) {
	return (Point){a.x + b.x, a.y + b.y};
}
inline Point operator - (Point a, Point b) {
	return (Point){a.x - b.x, a.y - b.y};
}
inline Point operator * (Point a, int b) {
	return (Point){a.x * b, a.y * b};
}
inline int operator == (Point a, Point b) {
	return abs(a.x - b.x) <= eps && abs(a.y - b.y) <= eps;
}

int T, n, vis[N];
vector <pair<double,int> > k;

int check(int x, int y) {
	k.clear();
	mid2 = a[x] + a[y] - s * 2;
	mid2 = (Point){mid2.y, -mid2.x};
	for (int i = 1; i <= n; i++)
		k.push_back(make_pair(mid2.x * a[i].x + mid2.y * a[i].y, i));
	sort (k.begin(), k.end());
	for (int i = 1; i <= n; i++)
		vis[k[i - 1].second] = i;
	if (vis[x] + vis[y] != n + 1) return 0;
	double tmp = k[0].first + k[n - 1].first;
	for (int i = 1; i <= n; i++)
		if (abs(tmp - (k[i - 1].first + k[n - i].first)) > eps)
			return 0;
	return 1;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf", &a[i].x, &a[i].y);
	s = (Point){0, 0};
	for (int i = 1; i <= n; i++) s = s + a[i];
	s.x /= n, s.y /= n;
	int id = 0;
	for (int i = 1; i <= n; i++) {
		int flag = 1;
		for (int j = 1; j <= n; j++)
			if (a[i] + a[j] == s * 2)
				flag = 0;
		if (flag) id = i;
	}
	if (!id) return puts("-1"), void();
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (check(i, id)) ans++;
	printf("%d\n", ans);
}

int main() {
	solve();
	//freopen("life.in", "r", stdin);
	//freopen("life.out", "w", stdout);
	//for (scanf("%d", &T); T; T--) solve();
	return 0;
}