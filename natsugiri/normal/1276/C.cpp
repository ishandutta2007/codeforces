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
int A[400011];
int B[400011];
int sums[400011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    sort(A, A+N);

    vector<pair<int, int> > P;
    for (int i=0; i<N;) {
	int j = i;
	while (j < N && A[i] == A[j]) j++;
	P.emplace_back(j-i, A[i]);
	i = j;
    }
    sort(P.begin(), P.end());
    REP (i, P.size()) sums[i+1] = sums[i] + P[i].first;

    int ans = 0;
    for (int h=1, idx=0; ; h++) {
	while (idx < (int)P.size() && P[idx].first <= h) idx++;
	int has = sums[idx] + ((int)P.size() - idx) * h;
	int w = has/h;

	if (h <= w && ans < h*w) {
	    ans = h*w;
	}
	if (w < h) break;
    }

    for (int h=1, idx=0; ; h++) {
	while (idx < (int)P.size() && P[idx].first <= h) idx++;
	int has = sums[idx] + ((int)P.size() - idx) * h;
	int w = has/h;

	if (h*w == ans) {
	    int cnt = 0;
	    vector<pair<int, int> > P2;
	    REP (i, P.size()) {
		int g = min(h, min(ans - cnt, P[i].first));
		if (g) {
		    P2.emplace_back(g, P[i].second);
		    cnt += g;
		}
	    }
	    sort(P2.begin(), P2.end());
	    reverse(P2.begin(), P2.end());
	    VI v;
	    EACH (e, P2) REP (i, e->first) v.push_back(e->second);

	    printf("%d\n%d %d\n", ans, h, w);
	    cnt = 0;
	    REP (j, w) {
		int a = 0, b = j;
		REP (k, h) {
		    B[a*w+b] = v[cnt++];
		    a++; b++;
		    if (a == h) a = 0;
		    if (b == w) b = 0;
		}
	    }
	    REP (i, h) REP (j, w) {
		printf("%d%c", B[i*w+j], " \n"[j==w-1]);
	    }

	    return;
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}