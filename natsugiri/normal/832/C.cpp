#include<cmath>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

const double EPS = 1e-9;
int N;
int S;

VI XL, VL, XR, VR;


void MAIN() {
    scanf("%d%d", &N, &S);
    REP (i, N) {
	int x, v, t;
	scanf("%d%d%d", &x, &v, &t);
	if (t == 1) {
	    XL.push_back(x);
	    VL.push_back(v);
	} else {
	    XR.push_back(x);
	    VR.push_back(v);
	}
    }

    double lo = 0, hi = 1e6;
    vector<pair<int, int> > PL, PR;
    REP (_, 60) {
	double mid = (lo + hi) / 2;

	PL.clear();
	REP (i, XL.size()) {
	    if ((double)XL[i] / VL[i] <= mid) {
		PL.clear();
		PL.emplace_back(0, 1e6);
		break;
	    } else if ((double)XL[i]/(VL[i]+S) > mid) {
	    } else {
//		x/(VL+S) + (XL-x)/VL = mid;
//		x VL + (XL-x)(VL+S) = mid VL(VL+S);
//		xS = (XL-mid VL) (VL+S);
		double x = (XL[i] - mid * VL[i]) / S * (VL[i] + S);
		if (0 <= x && x <= XL[i]) {
		    double t = (XL[i] - x) / VL[i];
		    int x2 = min(1e6, floor(x + t * S + EPS));
		    if (XL[i] <= x2) {
			PL.emplace_back(XL[i], x2);
		    }
		}
	    }
	}
	sort(PL.begin(), PL.end());

	PR.clear();
	REP (i, XR.size()) {
	    double xr = 1e6 - XR[i];
	    if (xr / VR[i] <= mid) {
		PR.clear();
		PR.emplace_back(0, 1e6);
	    } else if (xr/(VR[i]+S) > mid) {
	    } else {
		double x = (xr - mid * VR[i]) / S * (VR[i] + S);
		if (0 <= x && x <= xr) {
		    double t = (xr - x) / VR[i];
		    int x2 = min(1e6, floor(x + t * S + EPS));
		    if (xr <= x2) {
			PR.emplace_back(1e6-x2, XR[i]);
		    }
		}
	    }
	}
	sort(PR.begin(), PR.end());

	bool yes = false;
	for (int i=0, j=0; i<(int)PL.size() && j<(int)PR.size(); ) {
	    if (PL[i].first <= PR[j].second && PR[j].first <= PL[i].second) {
		yes = true;
		break;
	    } else if (PL[i].second < PR[j].first) {
		i++;
	    } else {
		j++;
	    }
	}

	(yes? hi: lo) = mid;
    }

    printf("%.9f\n", (hi + lo) / 2);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}