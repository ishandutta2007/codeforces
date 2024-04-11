#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct point {
  	double x, y;
  	point() {
  	 	x = y = 0;
  	}
  	point(int _x, int _y) {
  	 	x = _x;
  	 	y = _y;
  	}
  	void read() {
  	 	scanf("%lf%lf", &x, &y);
  	}
};

double dist(point p1, point p2) {
 	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	point a, b, t;
	a.read();
	b.read();
	t.read();

	int n;
	scanf("%d", &n);
	vector<point> inp;
	double tot = 0;
	for (int i = 0; i < n; ++i) {
	 	point p;
	 	p.read();
	 	inp.puba(p);
	 	tot += dist(t, p) * 2;
	}

	vector<pair<double, double>> opt;
	for (int i = 0; i < n; ++i) {
	 	opt.puba({-dist(t, inp[i]) + dist(a, inp[i]), -dist(t, inp[i]) + dist(b, inp[i])});
	}

	double ans = 1e100;
	for (int qwe = 0; qwe < 2; ++qwe) {
    	vector<double> pref(n + 1), suff(n + 1);

    	pref[0] = 1e100;
    	suff[n] = 1e100;

    	for (int i = 0; i < n; ++i) {
    	 	pref[i + 1] = min(pref[i], opt[i].ss);
    	}

    	for (int i = n - 1; i >= 0; --i) {
    	 	suff[i] = min(suff[i + 1], opt[i].ss);
    	}

    	for (int i = 0; i < n; ++i) {
    	 	ans = min(ans, tot + opt[i].ff + min(0.0, min(pref[i], suff[i + 1])));
    	}

    	for (auto& p: opt) {
    	 	swap(p.ff, p.ss);
    	}
	}

	printf("%.15f\n", ans);
	return 0;
}