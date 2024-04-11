#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <set>
#include <string.h>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;

const ld pi = 3.1415926535897932384626433832795L;
const int B = 65536;
const ld eps = 1e-12;

pdd lns[50000];
pii ilns[50000];
ld cnterln[50000];
int tr[4 * B];
int L[50000];

pdd inter(int i, int j) {
	ld x = ((ld)ilns[i].second - ilns[j].second) / (ilns[j].first - ilns[i].first);
	ld y = lns[i].first*x + lns[i].second;
	return mp(x, y);
}

ld dist(pdd x, pdd y) {
	ld dx = x.first - y.first;
	ld dy = x.second - y.second;
	return sqrt(dx*dx + dy*dy);
}

void upd(int i, int val) {
	tr[2 * B + i] = val;
	int cur = (2 * B + i) / 2;
	while (cur > 0) {
		tr[cur] = tr[2 * cur] + tr[2 * cur + 1];
		cur /= 2;
	}
}

int get(int nd, int ndl, int ndr, int l, int r) {
	if (r < l) return 0;
	if (l > ndr || ndl > r) return 0;
	if (l <= ndl && ndr <= r) {
		return tr[nd];
	}
	else {
		int mid = (ndl + ndr) / 2;
		return get(2 * nd, ndl, mid, l, r) + get(2 * nd + 1, mid + 1, ndr, l, r);
	}
}

pdd solve_quad(ld a, ld b, ld c, int& stat) {
	if (a<0) {
		a = -a;
		b = -b;
		c = -c;
	}
	ld disc = b*b - 4 * a*c;
	if (disc < 0) {
		stat = 1;
		return mp(0, 0);
	}
	disc = sqrt(disc);
	return mp((-b + disc) / (2 * a), (-b - disc) / (2 * a));
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cout << setprecision(30);
	int n, x, y, m;
	scanf("%d %d %d %d", &n, &x, &y, &m);
	ld dx = (ld)x / 1000;
	ld dy = (ld)y / 1000;
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		lns[i].first = (ld)a / 1000;
		lns[i].second = (ld)b / 1000;
		ilns[i].first = a;
		ilns[i].second = b;
	}
	ld l = 0;
	ld u = 4000200000.0L;

	for (int i = 0; i < 150; i++) {
		ld R = (l + u) / 2;
		vector<pair<pair<ld, int>, int > > sols;
		memset(tr, 0, sizeof(tr));
		for (int j = 0; j < n; j++) {
			int stat = 0;
			pdd sol = solve_quad(lns[j].first*lns[j].first + 1, -2 * dx + 2 * lns[j].first*lns[j].second - 2 * lns[j].first*dy,
				dx*dx + (lns[j].second - dy)*(lns[j].second - dy) - R*R, stat);
			if (stat) continue;
			ld int1 = atan2(lns[j].first*sol.first + lns[j].second - dy, sol.first - dx);
			ld int2 = atan2(lns[j].first*sol.second + lns[j].second - dy, sol.second - dx);
			if (int1 > int2) swap(int1, int2);
			sols.push_back(mp(mp(int1, 1), j));
			sols.push_back(mp(mp(int2, -1), j));
		//	cout << int1 << " " << int2 << endl;
		}
		sort(sols.begin(), sols.end());
		int k = sols.size();
		long long cnt = 0;
		for (int i = 0; i < k; i++) {
			auto &x = sols[i];
			if (x.first.second == 1) {
				upd(i, 1);
				L[x.second] = i;
			}
			else {
				int curL = L[x.second];
				int curR = i;
				cnt += get(1, 0, 2 * B - 1, curL + 1, curR - 1);
				upd(curL, 0);
			}
		}

	//	cout << R << " " << cnt << "\n";
		if (cnt >= m) u = R;
		else l = R;
	}
	if (l < eps) {
		cout << 0.0;
		return 0;
	}
	l -= eps;
	vector<pair<pair<ld, int>, int > > sols;
	for (int j = 0; j < n; j++) {
		int stat = 0;
		pdd sol = solve_quad(lns[j].first*lns[j].first + 1, -2 * dx + 2 * lns[j].first*lns[j].second - 2 * lns[j].first*dy,
			dx*dx + (lns[j].second - dy)*(lns[j].second - dy) - l*l, stat);
		if (stat) continue;
		ld int1 = atan2(lns[j].first*sol.first + lns[j].second - dy, sol.first - dx);
		ld int2 = atan2(lns[j].first*sol.second + lns[j].second - dy, sol.second - dx);
		if (int1 > int2) swap(int1, int2);
		sols.push_back(mp(mp(int1, 1), j));
		sols.push_back(mp(mp(int2, -1), j));
	}
	sort(sols.begin(), sols.end());
	int k = sols.size();
	ld ans = 0; ld maxl = -1;
	int ccnt = 0;
	set<pair<ld, int> > tr2;
	for (int i = 0; i < k; i++) {
		const auto &x = sols[i];
		if (x.first.second == 1) {
			tr2.insert(make_pair(x.first.first, x.second));
			L[x.second] = i;
		}
		else {
			auto ub = make_pair(x.first.first, x.second);
			auto it2 = tr2.insert(ub).first;
			auto lb = make_pair(sols[L[x.second]].first.first, x.second);
			auto it = tr2.upper_bound(lb);
			for (; it != it2; it++) {
				int j = it->second;
				ld diss = dist(make_pair(dx, dy), inter(x.second, j));
				ans += diss;
				maxl = max(maxl, diss);
				ccnt++;
			}
			tr2.erase(it2);
			tr2.erase(make_pair(sols[L[x.second]].first.first, x.second));
		}
	}
	if (ccnt > m) ans -= (ccnt - m)*maxl;
	else ans += (m - ccnt)*u;
	//cout << ccnt << endl;
	cout << ans;
	return 0;
}