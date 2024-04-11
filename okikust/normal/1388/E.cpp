#pragma GCC optimize("O3")
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 2020
#define EPS 0.00000000000001
#define pb push_back

int main() {
	int n, k;
	int sza, szb;
	long double x1[N];
	long double x2[N];
	long double y[N];
	long double xx, yy, zz;
	long double xxx, yyy;
	vector < pair<long double, long double> >a;
	pair<long double, long double>ma[N];
	pair<long double, long double>mb[N];
	long double s, ans;
	scanf("%d", &n);
	xxx = 10000000000;
	yyy = -10000000000;
	f(i, n) {
		scanf("%Lf %Lf %Lf", &x1[i], &x2[i], &y[i]);
		if (xxx > x1[i]) xxx = x1[i];
		if (yyy < x2[i])yyy = x2[i];
	}
	f(i, n) {
		a.pb({ y[i],x2[i] });
	}
	sort(a.begin(), a.end());
	sza = 0;
	f(i, n) {
		while (sza > 1) {
			if (abs(a[i].first - ma[sza - 1].first) < 0.1) {
				sza--;
			}
			else {
				xx = (ma[sza - 1].second - a[i].second) / (a[i].first - ma[sza - 1].first);
				yy = (ma[sza - 2].second - a[i].second) / (a[i].first - ma[sza - 2].first);
				if (xx < yy)sza--;
				else break;
			}
		}
		ma[sza] = a[i];
		sza++;
	}
	a.clear();
	f(i, n) {
		a.pb({ y[i],x1[i] });
	}
	sort(a.begin(), a.end(), greater< pair<long double, long double> >());
	szb = 0;
	f(i, n) {
		while (szb > 1) {
			if (abs(a[i].first - mb[szb - 1].first) < 0.1) {
				szb--;
			}
			else {
				xx = (mb[szb - 1].second - a[i].second) / (a[i].first - mb[szb - 1].first);
				yy = (mb[szb - 2].second - a[i].second) / (a[i].first - mb[szb - 2].first);
				if (xx < yy)szb--;
				else break;
			}
		}
		mb[szb] = a[i];
		szb++;
	}
	int sz, itra, itrb;
	vector<pair<long double, int> >c;
	f(i, n) {
		f(j, i) {
			if (abs(y[i] - y[j]) > 0.1) {
				xx = (x2[j] - x1[i]) / (y[i] - y[j]);
				yy = (x1[j] - x2[i]) / (y[i] - y[j]);
				if (xx > yy)swap(xx, yy);
				c.pb({ xx + EPS,1 });
				c.pb({ yy - EPS,-1 });
			}
		}
	}
	int cur = 0;
	sort(c.begin(), c.end());
	sz = c.size();
	itra = 0;
	itrb = 0;
	ans = 1000000000000000000;
	if (sz == 0) {
		ans = yyy - xxx;
	}
	f(i, sz) {
		if (cur <= 1) {
			while (itra < (sza - 1)) {
				xx = ma[itra].first*c[i].first + ma[itra].second;
				yy = ma[itra + 1].first*c[i].first + ma[itra + 1].second;
				if (xx > yy)break;
				else itra++;
			}
			while (itrb < (szb - 1)) {
				xx = mb[itrb].first*c[i].first + mb[itrb].second;
				yy = mb[itrb + 1].first*c[i].first + mb[itrb + 1].second;
				if (xx < yy)break;
				else itrb++;
			}
		}
		if (cur == 0) {
			xx = ma[itra].first*c[i].first + ma[itra].second;
			yy = mb[itrb].first*c[i].first + mb[itrb].second;
			ans = min(ans, xx - yy);
		}
		cur += c[i].second;
		if (cur == 0) {
			xx = ma[itra].first*c[i].first + ma[itra].second;
			yy = mb[itrb].first*c[i].first + mb[itrb].second;
			ans = min(ans, xx - yy);
		}
	}

	printf("%.08Lf\n", ans);

	return 0;
}