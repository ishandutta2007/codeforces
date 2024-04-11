#include<set>
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

int N, M;
struct Part {
    int a, b, i;
    Part() {}
    Part(int a_, int b_, int i_) : a(a_), b(b_), i(i_) {}
    bool operator<(const Part &y) const {
	return a < y.a;
    }
} P[100111];
struct Actor {
    int c, d, k, i;
    Actor() {}
    Actor(int c_, int d_, int k_, int i_) : c(c_), d(d_), k(k_), i(i_) {}
    bool operator<(const Actor &y) const {
	return c < y.c;
    }
} A[100111];

int ans[100111];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", &P[i].a, &P[i].b), P[i].i = i;
    scanf("%d", &M);
    REP (i, M) scanf("%d%d%d", &A[i].c, &A[i].d, &A[i].k), A[i].i = i;
    sort(P, P+N);
    sort(A, A+M);

    set<pair<int, int> > se; // (d, index)
    int p_i = 0, a_i = 0;
    bool yes = true;
    while (p_i < N) {
	while (a_i < M && A[a_i].c <= P[p_i].a) {
	    se.emplace(A[a_i].d, a_i);
	    a_i++;
	}

	while (1) {
	    auto it = se.lower_bound(make_pair(P[p_i].b, -1));
	    if (it == se.end()) {
		yes = false;
		goto END;
	    } else {
		int i = it->second;
		if (A[i].k) {
		    A[i].k--;
		    ans[P[p_i].i] = A[i].i + 1;
		    break;
		} else {
		    se.erase(make_pair(A[i].d, i));
		}
	    }
	}
	p_i++;
    }

END:;

    if (yes) {
	puts("YES");
	rprintf("%d", ans, ans+N);
    } else {
	puts("NO");
    }


    return 0;
}