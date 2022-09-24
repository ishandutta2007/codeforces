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

int N;
int A[100111];
int nim[100111];
pair<int, int> P[100111];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
//    N = 1000;
//    REP (i, N) A[i] = i+1;
    REP (i, N) P[i] = make_pair(A[i], i);
    sort(P, P+N);
    reverse(P, P+N);

    VI v; v.reserve(N);
    REP (i, N) {
	int val = P[i].first;
	int pos = P[i].second;
	v.clear();
	for (int k=pos-val; k>=0; k-=val) {
	    if (val < A[k]) v.push_back(nim[k]);
	}
	for (int k=pos+val; k<N; k+=val) {
	    if (val < A[k]) v.push_back(nim[k]);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	v.push_back(-1);
	REP (j, v.size()) if (v[j] != j) {
	    nim[pos] = j;
	    break;
	}
    }

    REP (i, N) putchar(nim[i]? 'A': 'B');
    putchar('\n');
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}