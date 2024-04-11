#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25000;
const long double eps = 1e-10;
int cmp(long double A, long double B) {
	if (A - B < -eps) return -1;
	if (A - B > eps) return 1;
	return 0;
}
typedef pair<long double, long double> point;
#define X first
#define Y second
#define x1 fqwepfjqwfpoj
#define x2 fqwepfjqwrqwe
#define y1 fqwepfjqrqwej
#define y2 fqwepqweeeeoj

int ccw(point a, point b, point c) {
	return cmp(a.X*(b.Y - c.Y) + b.X*(c.Y - a.Y) + c.X*(a.Y - b.Y), 0);
}

bool onSegment(point p, point q, point r) { 
	return (q.X <= max(p.X, r.X) && q.X >= min(p.X, r.X) && q.Y <= max(p.Y, r.Y) && q.Y >= min(p.Y, r.Y));
} 

bool isSegmentCut(point p0, point p1, point p2, point p3) {
	int o1 = ccw(p0, p1, p2); 
	int o2 = ccw(p0, p1, p3); 
	int o3 = ccw(p2, p3, p0); 
	int o4 = ccw(p2, p3, p1); 

	if (o1 != o2 && o3 != o4) return 1; 

	if (o1 == 0 && onSegment(p0, p2, p1)) return 1; 
	if (o2 == 0 && onSegment(p0, p3, p1)) return 1; 
	if (o3 == 0 && onSegment(p2, p0, p3)) return 1; 
	if (o4 == 0 && onSegment(p2, p1, p3)) return 1; 

	return 0;
}

int n;
int x[MAXN], y[MAXN];
long double dx[MAXN], dy[MAXN], s[MAXN];

long double x1[MAXN], y1[MAXN];
long double x2[MAXN], y2[MAXN];

bool isSegmentCut(int i, int j) {
	return isSegmentCut(make_pair(x1[i], y1[i]), make_pair(x2[i], y2[i]), make_pair(x1[j], y1[j]), make_pair(x2[j], y2[j]));
}

bool check(long double t) {
	//cout << "Mid: " << t << '\n';
	vector<tuple<long double, int, int>> p;
	for (int i = 0; i < n; i++) {
		x1[i] = x[i], y1[i] = y[i];
		x2[i] = x[i] + t*dx[i], y2[i] = y[i] + t*dy[i];

		if (x1[i] > x2[i]) {
			swap(x1[i], x2[i]);
			swap(y1[i], y2[i]);
		}

		//cout << "Segment " << x1[i] << ' ' << y1[i] << ' ' << x2[i] << ' ' << y2[i] << '\n';

		p.emplace_back(x1[i], i, 0);
		p.emplace_back(x2[i], i, 1);
	}
	//cout << '\n';
	// 0 for left, 1 for right
	sort(p.begin(), p.end());

	set<pair<long double, int>> st;
	for (auto [x, id, tp]: p) {
		long double q = (tp ? y2[id] : y1[id]);

		auto it = st.upper_bound(make_pair(q, -1));
		for (int i = 0; i < 2; i++) {
			if (it != st.begin()) it--;
		}
		for (int i = 0; i < 5; i++) {
			if (it == st.end()) break;
			if (id != it->second && isSegmentCut(id, it->second)) return 1;
			it++;
		}

		if (tp) st.erase(st.find(make_pair(y1[id], id)));
		else st.insert(make_pair(y1[id], id));
	}
	return 0;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> dx[i] >> dy[i] >> s[i];
		long double ffs = sqrtl(dx[i]*dx[i] + dy[i]*dy[i]);
		dx[i] *= s[i]/ffs;
		dy[i] *= s[i]/ffs;
	}

	long double lo = 0, hi = 1e10;
	bool has_ans = 0;
	for (int t = 0; t < 100; t++) {
		long double mid = (lo + hi)/2;

		if (check(mid)) {
			has_ans = 1;
			hi = mid;
		} else {
			lo = mid;
		}
	}

	if (!has_ans) {
		cout << "No show :(\n";
	} else {
		cout << fixed << setprecision(9) << hi << '\n';
	}

	return 0;
}