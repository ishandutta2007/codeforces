#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

ll sq(int x) { return (ll)x * x; }
double sq(double x) { return x * x; }

int main() {
	const double PI = acos(-1.);
	int x0; int y0; int v; int T;
	while(~scanf("%d%d%d%d", &x0, &y0, &v, &T)) {
		int n;
		scanf("%d", &n);
		bool contained = false;
		vector<pair<double, int>> events;
		rep(i, n) {
			int x; int y; int r;
			scanf("%d%d%d", &x, &y, &r);
			x -= x0, y -= y0;	//int
			ll dist = sq(x) + sq(y);
			if(dist <= sq(r)) {
				contained = true;
			} else if(v > 0) {
				complex<double> center(x, y);
				double a = arg(center);
				double lo = 0, up = PI / 2;
				rep(kk, 60) {
					double mid = (lo + up) / 2;
					auto pt = center * polar(1., -a + mid);
					//(x-pt.x)^2 = r^2 - pt.y^2
					double t = sq(r * 1.) - sq(pt.imag());
					bool ok;
					if(t <= 0) {
						ok = false;
					} else {
						ok = max(0., pt.real() - sqrt(t)) / v <= T;
					}
					(ok ? lo : up) = mid;
				}
				double s = (lo + up) / 2;
				if(a < 0) a += 2 * PI;
				if(a - s < 0) {
					events.emplace_back(0., +1);
					events.emplace_back(a + s, -1);
					events.emplace_back(a - s + 2 * PI, +1);
					events.emplace_back(2 * PI, -1);
				} else if(a + s > 2 * PI) {
					events.emplace_back(a - s, +1);
					events.emplace_back(2 * PI, -1);
					events.emplace_back(0., +1);
					events.emplace_back(a + s - 2 * PI, -1);
				} else {
					events.emplace_back(a - s, +1);
					events.emplace_back(a + s, -1);
				}
			}
		}
		sort(events.begin(), events.end());
		int num = 0; double left = 1e99;
		double ans = 0;
		for(auto e : events) {
			if(num == 0)
				left = e.first;
			num += e.second;
			if(num == 0 && left != 1e99) {
				ans += e.first - left;
				left = 1e99;
			}
		}
		ans /= 2 * PI;
		if(contained)
			ans = 1;
		printf("%.10f\n", ans);
	}
	return 0;
}