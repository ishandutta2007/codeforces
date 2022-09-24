#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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
	if (ev) { // [mid-1, mid, mid+1, mid+2]
	    return make_pair(mid - rad[mid*2+1]/2 + 1, mid + rad[mid*2+1]/2 + 1);
	} else { // [mid-1, mid, mid+1]
	    return make_pair(mid - rad[mid*2]/2, mid + rad[mid*2]/2 + 1);
	}
    }
};

string calc(const string &S) {
    int N = S.size();
    Manacher M(S);
    int len = 0;
    REP (i, N/2) {
	if (S[i] != S[N-1-i]) break;
	len = i+1;
    }

    int best_i = -1, best_ev = 0, best_len = -1;
    REP (i, N) {
	if (i*2 < N) {
	    auto p = M.span(i, false);
	    if (p.first <= len && best_len < i*2+1) {
		best_i = i;
		best_ev = false;
		best_len = i*2+1;
	    }
	}
	if (i*2 < N-1) {
	    auto p = M.span(i, true);
	    if (p.first <= len && best_len < i*2+2) {
		best_i = i;
		best_ev = true;
		best_len = i*2+2;
	    }
	}
    }

    if (best_len <= 0) return string(1, S[0]);
    string ret = S.substr(0, best_i+1);
    if (!best_ev) ret.pop_back();
    reverse(ret.begin(), ret.end());
    ret = S.substr(0, best_i+1) + ret;
    return ret;
}

int N;
char S[100011];

void MAIN() {
    scanf("%s", S);
    N = strlen(S);

    auto a = calc(S);
    reverse(S, S+N);
    auto b = calc(S);
    if (a.size() < b.size()) {
	reverse(b.begin(), b.end());
	swap(a, b);
    }
    puts(a.c_str());
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}