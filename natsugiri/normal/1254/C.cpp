#include<map>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

#ifdef MYTEST
LL X[] = {-2, 3, -2, 1, 0, 2};
LL Y[] = {1, -1, -1, -2, 3, 2};
LL area2_(int i, int j, int k) {
    LL x0 = X[j] - X[i];
    LL y0 = Y[j] - Y[i];
    LL x1 = X[k] - X[i];
    LL y1 = Y[k] - Y[i];
    return x0 * y1 - x1 * y0;
}
#endif

LL AREA2(int i, int j, int k) {
#ifdef MYTEST
    printf("1 %d %d %d\n", i+1, j+1, k+1);
    return abs(area2_(i, j, k));
#else
    printf("1 %d %d %d\n", i+1, j+1, k+1);
    fflush(stdout);
    LL ret;
    scanf("%lld", &ret);
    return ret;
#endif
}

int SIGN(int i, int j, int k) {
#ifdef MYTEST
    printf("2 %d %d %d\n", i+1, j+1, k+1);
    LL tmp = area2_(i, j, k);
    if (tmp < 0) return -1;
    else if (tmp > 0) return 1;
    else assert(false);
#else
    printf("2 %d %d %d\n", i+1, j+1, k+1);
    fflush(stdout);
    LL ret;
    scanf("%lld", &ret);
    return ret;
#endif
}

int N;

VI solve(const map<LL, VI> &mp) {
    if (mp.empty()) return {};

    VI v0, v1;

    auto it = mp.rbegin();
    int top = it->second[0];
    EACH (e, mp) EACH (f, e->second) {
	if (*f == top) continue;
	int s = SIGN(0, top, *f);
	if (s == 1) {
	    // left ... *f ... top;
	    v0.push_back(*f);
	} else {
	    // top ... *f ... right;
	    v1.push_back(*f);
	}
    }

    v0.push_back(top);
    reverse(v1.begin(), v1.end());
    v0.insert(v0.end(), v1.begin(), v1.end());
    return v0;
}
map<LL, VI> mpP, mpN;

void MAIN() {
    scanf("%d", &N);

    for (int k=2; k<N; k++) {
	LL a = AREA2(0, 1, k);
	LL s = SIGN(0, 1, k);
	if (s == 1) {
	    mpP[a].push_back(k);
	} else {
	    mpN[a].push_back(k);
	}
    }

    VI v0 = solve(mpP);
    VI v1 = solve(mpN);
    VI ans;
    ans.insert(ans.end(), v0.begin(), v0.end());
    ans.push_back(1);
    ans.insert(ans.end(), v1.begin(), v1.end());
    ans.push_back(0);

    EACH (e, ans) *e += 1;
    reverse(ans.begin(), ans.end());

    printf("0 ");
    rprintf("%d", ans.begin(), ans.end());
    fflush(stdout);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}