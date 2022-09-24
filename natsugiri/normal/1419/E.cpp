#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

int N;
vector<pair<int, int> > F;
int cst;
VI ans;

int X[10011];
VI B[10011];
VI D;

void MAIN() {
    scanf("%d", &N);
    int m = N;
    F.clear();

    for (int i=2; i*i<=m; i++) {
	int cnt = 0;
	while (m % i == 0) {
	    cnt++;
	    m /= i;
	}
	if (cnt) {
	    F.emplace_back(i, cnt);
	}
    }
    if (m > 1) {
	F.emplace_back(m, 1);
    }

    cst = 0;
    ans.clear();

    if (F.size() == 1u) {
	cst = 0;
	int p = 1;
	REP (i, F[0].second) {
	    p *= F[0].first;
	    ans.push_back(p);
	}
    } else if (F.size() == 2u && F[0].second == 1 && F[1].second == 1) {
	cst = 1;
	int p = F[0].first;
	int q = F[1].first;
	ans.push_back(p);
	ans.push_back(q);
	ans.push_back(p*q);
    } else {
	cst = 0;
	int len = 0;

	if (F.size() >= 3u) {
	    REP (i, F.size()) {
		int p = F[i].first;
		int q;
		if (i+1 == (int)F.size()) q = F[0].first;
		else q = F[i+1].first;
		X[len++] = p;
		X[len++] = p * q;
	    }
	} else {
	    int p = F[0].first;
	    int q = F[1].first;
	    if (F[1].second == 1) swap(p, q);
	    X[len++] = p;
	    X[len++] = p * q;
	    X[len++] = q;
	    X[len++] = p * q * q;
	}

	D.clear();
	for (int i=1; i*i<=N; i++) if (N % i == 0) {
	    if (i != 1) D.push_back(i);
	    if (i * i != N) D.push_back(N / i);
	}

	REP (i, len) B[i].clear();
	EACH (e, D) {
	    bool find = false;
	    REP (i, len) if (*e == X[i]) {
		find = true;
		B[i].push_back(*e);
		break;
	    }

	    if (!find) {
		REP (i, len) if (*e %  X[i] == 0) {
		    B[i].push_back(*e);
		    break;
		}
	    }
	}

	REP (i, len) ans.insert(ans.end(), B[i].begin(), B[i].end());
    }

    rprintf("%d", ans.begin(), ans.end());
    printf("%d\n", cst);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}