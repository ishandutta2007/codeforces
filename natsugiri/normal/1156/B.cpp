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
char S[111];

string ans;
vector<pair<char, int> > X;

void build() {
    EACH (e, X) REP (i, e->second) ans.push_back(e->first);
}

void MAIN() {
    scanf("%s", S);
    N = strlen(S);
    sort(S, S+N);
    X.clear();
    ans.clear();

    REP (i, N) {
	if (X.empty() || X.back().first != S[i]) {
	    X.emplace_back(S[i], 1);
	} else {
	    X.back().second++;
	}
    }

    if (X.size() == 2u) {
	if (X[0].first + 1 != X[1].first) {
	    build();
	}
    } else if (X.size() == 3u) {
	if (X[0].first + 1 == X[1].first && X[1].first + 1 == X[2].first) {
	} else if (X[0].first + 1 == X[1].first) {
	    swap(X[1], X[2]);
	    build();
	} else if (X[1].first + 1 == X[2].first) {
	    swap(X[0], X[1]);
	    build();
	} else {
	    build();
	}
    } else {
	for (int i=1; i<(int)X.size(); i+=2) REP (j, X[i].second) ans.push_back(X[i].first);
	for (int i=0; i<(int)X.size(); i+=2) REP (j, X[i].second) ans.push_back(X[i].first);
    }

    if (ans.empty()) {
	puts("No answer");
    } else {
	puts(ans.c_str());
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}