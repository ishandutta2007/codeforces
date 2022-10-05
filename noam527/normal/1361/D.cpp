#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

struct point {
	ll x, y;
	int r;
	point() {}
	point(ll xx, ll yy) {
		x = xx;
		y = yy;
		if (y > 0 || (y == 0 && x > 0)) r = 0;
		else r = 1;
	}
	bool operator == (const point &a) const {
		return r == a.r && x * a.y - y * a.x == 0;
	}
	bool operator < (const point &a) const {
		if (r != a.r) return r < a.r;
		return x * a.y - y * a.x < 0;
	}
};

struct info {
	ldb x;
	int i, j;
	info() {}
	info(ldb xx, int ii, int jj) {
		x = xx;
		i = ii;
		j = jj;
	}
	bool operator < (const info &a) const {
		return x < a.x;
	}
};

ldb dist(const point &p) {
	return sqrtl(p.x * p.x + p.y * p.y);
}

int n, k, m;
vector<vector<ldb>> dis, opt;
vector<point> a;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	n--;
	for (int i = 0; i < n + 1; i++) {
		ll x, y;
		cin >> x >> y;
		if (x != 0 || y != 0) a.push_back(point(x, y));
	}
	vector<point> un = a;
	sort(un.begin(), un.end());
	un.resize(unique(un.begin(), un.end()) - un.begin());
	m = un.size();
	dis.resize(m);
	opt.resize(m);
	for (const auto &i : a) {
		dis[lower_bound(un.begin(), un.end(), i) - un.begin()].push_back(dist(i));
	}
	for (int i = 0; i < m; i++) {
		sort(dis[i].begin(), dis[i].end());
	}
	if (OO) {
		cout << "dis:\n";
		for (const auto &i : dis) {
			cout << i.size() << ": ";
			for (const auto &j : i) cout << j << " "; cout << endl;
		}
	}

	for (int i = 0; i < m; i++) {
		
		int l = dis[i].size();
		vector<ldb> pairp(l + 1), pairs(l + 1);
		vector<ldb> sump(l + 1), sums(l + 1);

		ldb sum = 0, pa = 0;
		for (int j = 0; j < l; j++) {
			pa += j * dis[i][j] - sum;
			sum += dis[i][j];
			pairp[j + 1] = pa;
			sump[j + 1] = sum;
		}
		sum = 0, pa = 0;
		for (int j = 0; j < l; j++) {
			pa += sum - j * dis[i][l - 1 - j];
			sum += dis[i][l - 1 - j];
			pairs[j + 1] = pa;
			sums[j + 1] = sum;
		}

		if (OO) {
			cout << "pairp pairs:\n";
			for (const auto &i : pairp) cout << i << " "; cout << endl;
			for (const auto &i : pairs) cout << i << " "; cout << endl;
			cout << "sump sums:\n";
			for (const auto &i : sump) cout << i << " "; cout << endl;
			for (const auto &i : sums) cout << i << " "; cout << endl;
		}

		for (int x = 1; x <= l && x <= k; x++) {
			int lo = 0, hi = x, mid;
			while (lo < hi) {
				mid = (lo + hi) / 2;
				ldb cost = pairp[mid] + pairs[x - mid];
				cost += mid * sums[x - mid] - (x - mid) * sump[mid];
				cost += (k - x) * (sump[mid] + sums[x - mid]);
				mid++;
				ldb cost2 = pairp[mid] + pairs[x - mid];
				cost2 += mid * sums[x - mid] - (x - mid) * sump[mid];
				cost2 += (k - x) * (sump[mid] + sums[x - mid]);
				mid--;

				if (cost < cost2) lo = mid + 1;
				else hi = mid;
			}

			if (OO && i == 1) {
				cout << "x lo " << x << " " << lo << endl;
			}

			mid = lo;
			ldb cost = pairp[mid] + pairs[x - mid];
			cost += mid * sums[x - mid] - (x - mid) * sump[mid];
			cost += (k - x) * (sump[mid] + sums[x - mid]);
			//mid++;
			//ldb cost2 = pairp[mid] + pairs[x - mid];
			//cost2 += mid * sums[x - mid] - (x - mid) * sump[mid];
			//cost2 += (k - x) * (sump[mid] + sums[x - mid]);
			//mid--;

			if (OO && i == 1) {
				cout << "cost1 " << cost << endl;
				//cout << "cost2 " << cost2 << endl;
			}

			opt[i].push_back(cost);
		}
		
		/*
		if (OO) cout << "start " << i << endl;
		ldb up = 0, down = 0;
		ldb pad = 0;
		int cntl = 0, cntr = 0;
		int l = 0, r = (int)dis[i].size() - 1;
		int len = dis[i].size();
		for (int x = 1; x <= len && x <= k; x++) {
			if (OO) cout << "start x " << x << endl;
			ldb costl = 0, costr = 0;
			costl = (k - x) * dis[i][l] + up - cntr * dis[i][l] + cntl * dis[i][l] - down;
			costr = (k - x) * dis[i][r] + up - cntr * dis[i][r] + cntl * dis[i][r] - down;
			if (costl > costr) {
				down += dis[i][l];
				cntl++;
				pad += up - cntr * dis[i][l] + cntl * dis[i][l] - down;
				l++;
			}
			else {
				up += dis[i][r];
				cntr++;
				pad += up - cntr * dis[i][r] + cntl * dis[i][r] - down;
				r--;
			}
			opt[i].push_back(pad + (down + up) * (k - x));
		}
		*/
		for (int j = (int)opt[i].size() - 1; j > 0; j--)
			opt[i][j] -= opt[i][j - 1];
	}

	if (OO) {
		cout << "opt:\n";
		for (const auto &i : opt) {
			cout << i.size() << ": ";
			for (const auto &j : i) cout << j << " "; cout << endl;
		}
	}
	ldb sum = 0;
	ldb ans = 0;
	priority_queue<info> q;
	for (int i = 0; i < m; i++) {
		q.push(info(opt[i][0], i, 0));
	}
	for (int i = 0; i < k && i < n; i++) {
		auto x = q.top();
		q.pop();
		sum += x.x;
		if (x.j + 1 < opt[x.i].size()) {
			x.j++;
			q.push(info(opt[x.i][x.j], x.i, x.j));
		}
		if (i >= k - 2)
			ans = max(ans, sum);
	}
	cout.precision(8);
	cout << fixed << ans << endl;
}