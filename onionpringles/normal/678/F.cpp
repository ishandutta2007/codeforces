#pragma warning(disable:4996)

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <complex>
#include <iterator>
#include <random>
#include <time.h>
#include <tuple>
#include <functional>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mul(x,y) ((ll)(x)*(y)%mod)
#define mtp make_tuple
#define add(x,y) ((ll)(x)+(y))%mod
#define F(i,n) for(int i = 0; i < n; i++)
#define FF(i,n) for(int i = 1; i <= n; i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 300000;
const int B = 1 << 19;
const long long ninf = -9000000000000000000LL;
class Query {
public:
	int tp, a, b;
	union {
		int e;
		int q;
	};
} q[N];
vector<int> tr[B << 1];
void upd(int l, int r, int v) {
	for (l += B, r += B; l / 2 != r / 2; l /= 2, r /= 2) {
		if (!(l & 1)) tr[l + 1].push_back(v);
		if (r & 1) tr[r - 1].push_back(v);
	}
}

class Frac {
public:
	long long x, y;
	Frac(long long xx, long long yy) {
		if (yy < 0) {
			xx = -xx;
			yy = -yy;
		}
		x = xx;
		y = yy;
	}
	bool operator<(const Frac& f) const {
		return x*f.y < f.x*y;
	}
};
Frac inter(int i, int j) {
	return Frac(q[i].b - q[j].b, q[j].a - q[i].a);
}
long long getval(int nd, int qq) {
	auto& V = tr[nd];
	int sz = V.size();
	if (!sz) return ninf;
	int l = 0; int r = sz - 1;
	while (l ^ r) {
		int m = (l + r) / 2;
		auto cur = inter(V[m], V[m + 1]);
		if (!(cur < Frac(qq, 1))) r = m;
		else l = m + 1;
	}
	int good = V[l];
	return (ll)qq*q[good].a + q[good].b;
}
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> srt;
	int n; ni(n);
	F(i, n) {
		int t; ni(t);
		q[i].tp = t;
		if (t == 1) {
			nii(q[i].a, q[i].b);
			q[i].e = n - 1;
			srt.push_back(i);
		}
		else if (t == 2) {
			int j; ni(j); j--;
			q[j].e = i;
		}
		else {
			ni(q[i].q);
		}
	}
	sort(srt.begin(), srt.end(), [&](int i, int j) {
		auto& x = q[i]; auto& y = q[j];
		return x.a < y.a || x.a == y.a && x.b < y.b;
	});
	for (auto &x : srt) {
		upd(x - 1, q[x].e + 1, x);
	}
	F(i, 2 * B) {
		if (tr[i].empty()) continue;
		vector<int>& orig = tr[i];
		int sz = orig.size();
		int sp = 0;
		F(j, sz) {
			if (j < sz - 1 && q[orig[j]].a == q[orig[j + 1]].a) continue;
			int cur = orig[j];
			while (1) {
				if (sp < 2) break;
				int t1 = orig[sp - 1];
				int t2 = orig[sp - 2];
				if (inter(t2, t1) < inter(t1, cur)) break;
				else {
					sp--;
				}
			}
			orig[sp++] = cur;
		}
		orig.resize(sp);
	}
	F(i, n) {
		if (q[i].tp == 3) {
			long long ans = ninf;
			for (int j = i + B; j; j /= 2) {
				ans = max(ans, getval(j, q[i].q));
			}
			if (ans == ninf) puts("EMPTY SET");
			else printf("%I64d\n", ans);
		}
	}
	return 0;
}