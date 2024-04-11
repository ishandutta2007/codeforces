#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)
struct Manacher {
    vector<int>rad;

    Manacher(){}

    Manacher(const string &t) {
	int n = t.size(), i, j, k;
	rad = vector<int>(2*n);
	for (i=0, j=0; i<2*n; i+=k, j=max(j-k, 0)) {
	    while (i-j >= 0 && i+j+1 < 2*n && t[(i-j)/2] == t[(i+j+1)/2]) j++;
	    rad[i] = j;
	    for (k=1; i-k >= 0 && rad[i]-k >= 0 && rad[i-k] != rad[i]-k; k++)
		rad[i+k] = min(rad[i-k], rad[i]-k);
	}
    }

    template<class Iter> Manacher(Iter a, Iter a_end) {
	int n = a_end - a, i, j, k;
	rad = vector<int>(2*n);
	for (i=0, j=0; i<2*n; i+=k, j=max(j-k, 0)) {
	    while (i-j >= 0 && i+j+1 < 2*n && a[(i-j)/2] == a[(i+j+1)/2]) j++;
	    rad[i] = j;
	    for (k=1; i-k >= 0 && rad[i]-k >= 0 && rad[i-k] != rad[i]-k; k++)
		rad[i+k] = min(rad[i-k], rad[i]-k);
	}
    }

    bool ok(int l, int r) { // [l, r)
        return r-l <= rad[l+r-1];
    }

    pair<int, int> span(int mid, bool ev/*=even length str*/) { 
	if (ev) { // [mid-2, mid-1, mid, mid+1]
	    // assert: 1 <= mid < |t|;
	    assert(mid);
	    return make_pair(mid - rad[mid*2-1]/2, mid + rad[mid*2-1]/2);
	} else { // [mid-1, mid, mid+1]
	    return make_pair(mid - rad[mid*2]/2, mid + rad[mid*2]/2 + 1);
	}
    }
};

int N;
char S[500011];

void MAIN() {
    scanf("%d%s", &N, S);
    Manacher M(S);

    int remain = -1;
    int num = 0;

    for (int i=0; ; ) {
	int depth = 0;
	for (int j=i; j<=N; j++) {
	    if (j == N) {
		remain = N - i;
		goto OUT;
	    }

	    if (S[j] == '(') depth++;
	    else depth--;

	    if ((S[i] == '(' && depth == 0) || (j-i >= 1 && M.ok(i, j+1))) {
		num++;
		i = j+1;
		break;
	    }
	}
    }

OUT:
    printf("%d %d\n", num, remain);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}