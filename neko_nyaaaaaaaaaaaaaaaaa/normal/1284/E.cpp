#include <bits/stdc++.h>
using namespace std;

struct point{
	long long x, y;
	int q; // quadrant
};

bool cmp(point a, point b) {
	if (a.x == 0) return a.q < b.q;
	if (b.x == 0) return a.q <= b.q;
	if (a.q != b.q) return a.q < b.q;

	bool sgn1 = (a.x * b.x) > 0;
	bool sgn2 = (a.y*b.x < b.y*a.x);

	return sgn1 == sgn2;
}

long long cross(point a, point b) {
	return a.x*b.y - a.y*b.x;
} 

long long solve(int n, vector<point> P, int piv) {
	vector<point> Q;
	for (int i = 0; i < n; i++) {
		if (i != piv) {

			long long x = P[i].x - P[piv].x;
			long long y = P[i].y - P[piv].y;
			int q;

			if (x < 0) q = (y < 0 ? 1 : 4);
			else if (x > 0) q = (y < 0 ? 2 : 3);
			else q = (y < 0 ? 1 : 3);

			Q.push_back({x, y, q});
		}
	}
	sort(Q.begin(), Q.end(), cmp);

	int sz = Q.size();
	for (int i = 0; i < sz; i++) {
		Q.push_back(Q[i]);
	}

	long long ans = 1LL*sz*(sz - 1)*(sz - 2)/6;
	for (int i = 0, j = 0; i < sz; i++) {
		while (j < i+sz && cross(Q[i], Q[j]) >= 0) j++;
		long long k = (j - i - 1);
		ans -= k*(k-1)/2;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<point> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}	

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += solve(n, p, i);
	}
	cout << ans*(n-4)/2 << '\n';

	return 0;
}