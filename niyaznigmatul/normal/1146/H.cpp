/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

struct point {
	int x, y;

	point operator - (point const &p) const {
		return {x - p.x, y - p.y};
	}

	long long vmul(point const &p) const {
		return (long long) x * p.y - (long long) y * p.x;
	}
};


long long solve(point c, vector<point> p) {
	int n = (int) p.size();
	for (int i = 0; i < n; i++) {
		p[i] = p[i] - c;
	}
	sort(p.begin(), p.end(), [](point a, point b) {
		return a.vmul(b) > 0;
	});
	vector<vector<vector<long long> > > dp(3, vector<vector<long long> >(n, vector<long long> (n)));
	long long ans = 0;
	vector<int> forI, toI;
	for (int i = 0; i < n; i++) {
		forI.resize(n - i - 1);
		for (int j = 0; j < n - i - 1; j++) forI[j] = j + i + 1;
		toI.resize(i);
		for (int j = 0; j < i; j++) toI[j] = j;
		sort(forI.begin(), forI.end(), [&](int c, int d) {
			point pc = p[c] - p[i];
			point pd = p[d] - p[i];
			return pc.vmul(pd) > 0;
		});
		sort(toI.begin(), toI.end(), [&](int c, int d) {
			point pc = p[i] - p[c];
			point pd = p[i] - p[d];
			return pc.vmul(pd) > 0;
		});
		for (int step = 0; step < 2; step++) {
			long long current = 0;
			int pos = 0;
			for (int j : forI) {
				while (pos < (int) toI.size() && (p[j] - p[i]).vmul(p[i] - p[toI[pos]]) < 0) {
					current += dp[step][toI[pos]][i];
					pos++;
				}
				dp[step + 1][i][j] = current;
			}
		}
		for (int j : forI) {
			dp[0][i][j] = 1;
			ans += dp[2][i][j];
		}
		// for (int j = i + 1; j < n; j++) {
		// 	dp[0][i][j] = 1;
		// 	point v = p[j] - p[i];
		// 	for (int k = i - 1; k >= 0; k--) {
		// 		if ((p[i] - p[k]).vmul(v) < 0) continue;
		// 		for (int step = 0; step < 2; step++) {
		// 			dp[step + 1][i][j] += dp[step][k][i];
		// 		}
		// 	}
		// 	ans += dp[2][i][j];
		// }
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	vector<point> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	sort(p.begin(), p.end(), [](point const &a, point const &b) {
		if (a.x != b.x) return a.x < b.x;
		return a.y < b.y;
	});
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += solve(p[i], vector<point>(p.begin() + i + 1, p.end()));
	}
	cout << ans << endl;
}