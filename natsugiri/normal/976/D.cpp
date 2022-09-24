#include<random>
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

mt19937 engine;

int S, N;
int D[333];
int A[1011];
int idx[1011];
bool use[1011];

int sums[1011];
pair<int, int> X[1011];

bool valid() {
    REP (i, N) sums[i+1] = sums[i] + A[i];
    if (sums[N] & 1) return false;

    REP (i, N-1) {
	int left = sums[i+1];

	int lo = i, hi = N;
	while (hi - lo > 1) {
	    int mid = (lo + hi) / 2;
	    if (A[mid] < i+1) hi = mid;
	    else lo = mid;
	}
	// [i+1, hi) [hi, N);
	int right = i*(i+1) + (i+1)*(hi-i-1) + sums[N] - sums[hi];
	if (left > right) return false;
    }
    return true;
}

void MAIN() {
    scanf("%d", &S);
    REP (i, S) scanf("%d", D+i);
    reverse(D, D+S);

    N = D[0]+1;
    REP (i, N-1) idx[i] = i+1;
    while (1) {
	shuffle(idx, idx+N-1, engine);
	memset(use, 0, sizeof use);
	REP (i, S-1) use[idx[i]] = true;

	int cnt = 0;
	REP (i, N) {
	    if (use[i]) cnt++;
	    A[i] = D[cnt];
	}
	if (valid()) break;
    }

//    rprintf("%d", A, A+N);
//
    REP (i, N) X[i] = make_pair(A[i], i);
    vector<pair<int, int> > ans;
    for (int t=N-1; t>0; t--) {
	sort(X, X+t+1);
	int pos = t-1;
	while (X[t].first) {
	    ans.emplace_back(X[t].second, X[pos].second);
	    X[t].first--;
	    X[pos].first--;
	    pos--;
	}
    }

    printf("%d\n", (int)ans.size());
    EACH (e, ans) printf("%d %d\n", e->first + 1, e->second + 1);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}