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
#define f(i,n) for(int i=0;i<int(n);i++)
#define N (1<<19)
#define INIT 0
#define INIT2 0
#define INIT3 -10000000000000000
long long a[(2 * N)];
long long laz[(2 * N)];
long long b[(2 * N)];
long long lbz[(2 * N)];
int l[(2 * N)];
int r[(2 * N)];

long long f1(long long x, long long y) {
	return (x + y);
}
long long f2(long long k, long long x, long long y) {
	return (x + y);
}
long long f3(long long x, long long y) {
	return max(x, y);
}


void init(void) {
	f(i, (2 * N)) {
		a[i] = INIT2;
		laz[i] = INIT;
		b[i] = INIT2;
		lbz[i] = INIT;
	}
	l[1] = 0;
	r[1] = N;
	for (int i = 1; i < N; i++) {
		l[(2 * i)] = l[i];
		r[(2 * i)] = (l[i] + r[i]) / 2;
		l[(2 * i) + 1] = (l[i] + r[i]) / 2;
		r[(2 * i) + 1] = r[i];
	}
	return;
}
long long changeb(int ll, int rr, int k, long long x) {
	long long vl, vr;
	if ((rr <= l[k]) || (r[k] <= ll))return f2(k, lbz[k], b[k]);
	if (lbz[k] != INIT) {
		b[k] = f2(k, lbz[k], b[k]);
		if (k < N) {
			lbz[(2 * k)] = f1(lbz[k], lbz[(2 * k)]);
			lbz[(2 * k) + 1] = f1(lbz[k], lbz[(2 * k) + 1]);
		}
		lbz[k] = INIT;
	}
	if ((ll <= l[k]) && (r[k] <= rr)) {
		lbz[k] = f1(x, lbz[k]);
		return f2(k, lbz[k], b[k]);
	}
	else {
		int mm = (l[k] + r[k]) / 2;
		if ((l[k] < rr) && (ll < mm)) {
			vl = changeb(ll, rr, 2 * k, x);
		}
		else vl = f2((2 * k), lbz[(2 * k)], b[(2 * k)]);

		if ((mm < rr) && (ll < r[k])) {
			vr = changeb(ll, rr, (2 * k) + 1, x);
		}
		else vr = f2((2 * k) + 1, lbz[(2 * k) + 1], b[(2 * k + 1)]);

		b[k] = f3(vl, vr);
		return f2(k, lbz[k], b[k]);
	}
}


long long changea(int ll, int rr, int k, long long x) {
	long long vl, vr;
	if ((rr <= l[k]) || (r[k] <= ll))return f2(k, laz[k], a[k]);
	if (laz[k] != INIT) {
		a[k] = f2(k, laz[k], a[k]);
		if (k < N) {
			laz[(2 * k)] = f1(laz[k], laz[(2 * k)]);
			laz[(2 * k) + 1] = f1(laz[k], laz[(2 * k) + 1]);
		}
		laz[k] = INIT;
	}
	if ((ll <= l[k]) && (r[k] <= rr)) {
		laz[k] = f1(x, laz[k]);
		return f2(k, laz[k], a[k]);
	}
	else {
		int mm = (l[k] + r[k]) / 2;
		if ((l[k] < rr) && (ll < mm)) {
			vl = changea(ll, rr, 2 * k, x);
		}
		else vl = f2((2 * k), laz[(2 * k)], a[(2 * k)]);

		if ((mm < rr) && (ll < r[k])) {
			vr = changea(ll, rr, (2 * k) + 1, x);
		}
		else vr = f2((2 * k) + 1, laz[(2 * k) + 1], a[(2 * k + 1)]);

		a[k] = f3(vl, vr);
		return f2(k, laz[k], a[k]);
	}
}


long long searcha(int ll, int rr, int k) {
	if (laz[k] != INIT) {
		a[k] = f2(k, laz[k], a[k]);
		if (k < N) {
			laz[(2 * k)] = f1(laz[k], laz[(2 * k)]);
			laz[(2 * k) + 1] = f1(laz[k], laz[(2 * k) + 1]);
		}
		laz[k] = INIT;
	}
	long long vl, vr;
	if (rr <= l[k] || r[k] <= ll)return INIT3;
	else if (ll <= l[k] && r[k] <= rr) return f2(k, laz[k], a[k]);
	else {
		vl = searcha(ll, rr, 2 * k);
		vr = searcha(ll, rr, (2 * k) + 1);
		a[k] = f3(f2((2 * k), laz[(2 * k)], a[(2 * k)]), f2((2 * k) + 1, laz[(2 * k) + 1], a[(2 * k) + 1]));
		return f3(vl, vr);
	}
}
long long searchb(int ll, int rr, int k) {
	if (lbz[k] != INIT) {
		b[k] = f2(k, lbz[k], b[k]);
		if (k < N) {
			lbz[(2 * k)] = f1(lbz[k], lbz[(2 * k)]);
			lbz[(2 * k) + 1] = f1(lbz[k], lbz[(2 * k) + 1]);
		}
		lbz[k] = INIT;
	}
	long long vl, vr;
	if (rr <= l[k] || r[k] <= ll)return INIT3;
	else if (ll <= l[k] && r[k] <= rr) return f2(k, lbz[k], b[k]);
	else {
		vl = searchb(ll, rr, 2 * k);
		vr = searchb(ll, rr, (2 * k) + 1);
		b[k] = f3(f2((2 * k), lbz[(2 * k)], b[(2 * k)]), f2((2 * k) + 1, lbz[(2 * k) + 1], b[(2 * k) + 1]));
		return f3(vl, vr);
	}
}

int main(void) {
	int q;
	int c, x, y;
	long long k, kb, ans;
	ans = 0;
	init();
	int n, m;
	map<int, int>mp;
	vector<int>d;
	vector<pair<int, int> >e1;
	vector<pair<int, int> >e2;
	int segl[N];
	int segr[N];
	int segc[N];
	int sz, itr1, itr2, sz1, sz2;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d %d %d", &segl[i], &segr[i], &segc[i]);
		segr[i]++;
		d.push_back(segl[i]);
		d.push_back(segr[i]);
	}
	sort(d.begin(), d.end());
	mp[d[0]] = 0;
	x = 1;
	f(i, 2 * n - 1) {
		if (d[i] != d[i + 1]) {
			mp[d[i + 1]] = x;
			x++;
		}
	}
	m = x;
	f(i, n) {
		if(segc[i]==1)e1.push_back({ mp[segr[i]],mp[segl[i]] });
		else e2.push_back({ mp[segr[i]],mp[segl[i]] });
	}
	itr1 = 0;
	itr2 = 0;
	sz1 = e1.size();
	sz2 = e2.size();
	sort(e1.begin(), e1.end());
	sort(e2.begin(), e2.end());
	f(i, m) {
		while (itr1 < sz1) {
			if (e1[itr1].first > i)break;
			x = e1[itr1].second;
			changea(0, x + 1, 1, 1);
			itr1++;
		}
		while (itr2 < sz2) {
			if (e2[itr2].first > i)break;
			x = e2[itr2].second;
			changeb(0, x + 1, 1, 1);
			itr2++;
		}
		if (i > 0) {
			k = searcha(0, i, 1);
			kb = searchb(0, i, 1);
			k = max(k, kb);
			changea(i, i + 1, 1, k);
			changeb(i, i + 1, 1, k);
			ans = k;
		}
	}
	printf("%lld\n", ans);
	return 0;
}