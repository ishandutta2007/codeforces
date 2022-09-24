#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<bitset>
#include<set>

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

int P[1000011];
pair<int, int> X[500011];

VI G[1000011];
bool use[1000011];
bool take[1000011];


void MAIN() {
    scanf("%d", &N);

    if (N % 2 == 1) {
	puts("Second");
	fflush(stdout);

#ifdef LOCAL
	REP (i, N*2) P[i] = i / 2 + 1;
	random_shuffle(P, P+N*2);
	// rprintf("%d", P, P+N*2);
#else
	REP (i, N*2) scanf("%d", P+i);
#endif

	REP (i, N) X[i] = make_pair(-1, -1);

	REP (i, 2*N) {
	    int k = P[i] - 1;
	    if (X[k].first == -1) X[k].first = i;
	    else if (X[k].second == -1) X[k].second = i;
	    else assert(false);
	}
	// i -- i+N;
	// X[k].first -- X[k].second;
	//
	REP (i, N) {
	    G[i].push_back(i+N);
	    G[i+N].push_back(i);
	}
	REP (k, N) {
	    int x = X[k].first;
	    int y = X[k].second;
	    G[x].push_back(y);
	    G[y].push_back(x);
	}

	LL sum = 0;
	REP (i, N*2) if (!use[i]) {
	    int x = i;
	    VI cycle;
	    while (1) {
		cycle.push_back(x);
		use[x] = true;
		int y = -1;
		EACH (e, G[x]) if (!use[*e]) {
		    y = *e;
		    break;
		}
		if (y == -1) break;
		x = y;
	    }

	    for (int j=0; j<(int)cycle.size(); j+=2) {
		take[cycle[j]] = true;
		sum += cycle[j] + 1;
	    }
	}

	if (sum % (2*N)) {
	    REP (i, 2*N) take[i] = !take[i];
	}
	VI ans;
	sum = 0;
	REP (i, 2*N) if (take[i]) {
	    ans.push_back(i+1);
	    sum += i+1;
	}
	rprintf("%d", ans.begin(), ans.end());
	fflush(stdout);
    } else {
	puts("First");
	REP (i, N*2) P[i] = i / 2 + 1;
	swap(P[N-1], P[N*2-2]);
	rprintf("%d", P, P+N*2);
	fflush(stdout);
    }

    int ret;
    scanf("%d", &ret);
    assert(ret == 0);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}