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
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//
const long double eps = 1e-14L;
const int N = 1000;
pii r[N], b[N];
typedef long double ld;
typedef complex<ld> Point;
Point ri[N], bi[N];
int stk[N], sp;
ld outer(const Point& a, const Point& b) {
	return a.real()*b.imag() - a.imag()*b.real();
}
ld ccw(const Point& a, const Point& b, const Point& c) {
	return outer(a, b) + outer(b, c) + outer(c, a);
}
ld rad(Point a, Point b) {
	if (abs(a) < eps || abs(b) < eps) return 1e12;
	a = 100.0L / a; b = 100.0L / b;
	ld C = fabs(outer(a, b));
	if (C < eps) return 1e12;
	else return abs(a)*abs(b)*abs(a - b) / 2.0 / C;
}
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	ld ans = 0;
	int n, m; nii(n, m);
	F(i, n) {
		int x, y; nii(x, y);
		r[i] = mp(x, y);
	}
	F(i, m) {
		int x, y; nii(x, y);
		b[i] = mp(x, y);
	}
	n = unique(r, r + n) - r;
	m = unique(b, b + m) - b;
	F(t, m) {
		int xx = b[t].first;
		int yy = b[t].second;
		bool uni = false;
		F(i, n)r[i].first -= xx, r[i].second -= yy;
		F(i, m)b[i].first -= xx, b[i].second -= yy;
		F(i, n) {
			if (!r[i].first&&!r[i].second) {
				uni = true; break;
			}
		}
		F(i, n) {
			ri[i] = Point(r[i].first, r[i].second);
			ri[i] = 100.0L / ri[i];
		}
		F(i, m) {
			bi[i] = Point(b[i].first, b[i].second);
			if (abs(bi[i]) > eps)bi[i] = 100.0L / bi[i];
		}
		int c = 0;
		F(i, m) {
			if (bi[i].imag() < bi[c].imag()) {
				c = i;
			}
			else if (fabs(bi[i].imag() - bi[c].imag()) < eps&&bi[i].real() < bi[c].real()) c = i;
		}
		Point x = bi[c];
		sort(bi, bi + m, [&](const Point& a, const Point& b) {
			ld X = ccw(x, a, b);
			if (X > eps) return true;
			else if (X < -eps) return false;
			else {
				return abs(x-a)+eps < abs(x-b);
			}
		});
		sp = 0;
		F(i, m) {
			while (sp > 1) {
				int t = stk[sp - 1];
				int tt = stk[sp - 2];
				if (ccw(bi[tt], bi[t], bi[i]) < eps) sp--;
				else break;
			}
			stk[sp++] = i;
		}
		if (sp <= 2) {
			ans = max(ans, 1e12L);
		}
		else {
			F(i, sp) {
				ld R;
				int ni = (i + 1) % sp;
				R = rad(bi[stk[i]], bi[stk[ni]]);
				if (uni) {
					ans = max(ans, R); continue;
				}
				F(j, n) {
					ld C = ccw(bi[stk[i]],bi[stk[ni]],ri[j]);
					if (C < eps) {
						ans = max(ans, R);
						break;
					}
				}
			}
			F(i, sp) {
				int ni = (i + 1) % sp;
				int pi = (i + sp - 1) % sp;
				F(j, n) {
					ld C1 = ccw(bi[stk[i]], bi[stk[ni]], ri[j]);
					ld C2 = ccw(bi[stk[i]], bi[stk[pi]], ri[j]);
					if (C1 > -eps && C2 > -eps || C1 < -eps && C2 < -eps) {
						ans = max(ans, rad(bi[stk[i]], ri[j]));
					}
				}
			}
		}
		F(i, n)r[i].first += xx, r[i].second += yy;
		F(i, m)b[i].first += xx, b[i].second += yy;
	}
	if (ans > 1e11) {
		puts("-1"); return 0;
	}
	printf("%.15f\n", (double)ans);
}