#include<cassert>
#include<tuple>
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
string S[301][301];
string T[301][301];
char buf[100111];

typedef tuple<int, int, int, int> Four;
vector<Four> ans, tail;

int zero(const string &s) {
    return count(s.begin(), s.end(), '0');
}
int one(const string &s) {
    return count(s.begin(), s.end(), '1');
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) REP (j, M) {
	scanf("%s", buf);
	S[i][j] = buf;
    }
    REP (i, N) REP (j, M) {
	scanf("%s", buf);
	T[i][j] = buf;
    }

    string s = S[0][0];
    for (int k=s.size(); k--;) {
	if (s[k] == '0') {
	    ans.emplace_back(0, 0, 1, 0);
	    tail.emplace_back(1, 0, 0, 0);
	} else {
	    ans.emplace_back(0, 0, 0, 1);
	}
    }
    s = S[0][1];
    for (int k=s.size(); k--;) {
	if (s[k] == '0') {
	    ans.emplace_back(0, 1, 0, 0);
	} else {
	    ans.emplace_back(0, 1, 1, 1);
	    tail.emplace_back(1, 1, 0, 1);
	}
    }

    REP (i, N) REP (j, M) {
	if (j < 2) continue;
	s = S[i][j];

	for (int k=s.size(); k--;) {
	    if (s[k] == '0') {
		ans.emplace_back(i, j, i, 0);
		if (i) tail.emplace_back(i, 0, 0, 0);
	    } else {
		ans.emplace_back(i, j, i, 1);
		if (i) tail.emplace_back(i, 1, 0, 1);
	    }
	}
    }

    for (int i=1; i<N; i++) {
	s = S[i][0];
	for (int k=s.size(); k--;) {
	    if (s[k] == '0') {
		ans.emplace_back(i, 0, 0, 0);
	    } else {
		ans.emplace_back(i, 0, i, 1);
		tail.emplace_back(i, 1, 0, 1);
	    }
	}

	s = S[i][1];
	for (int k=s.size(); k--;) {
	    if (s[k] == '0') {
		ans.emplace_back(i, 1, i, 0);
		tail.emplace_back(i, 0, 0, 0);
	    } else {
		ans.emplace_back(i, 1, 0, 1);
	    }
	}
    }

    ans.insert(ans.end(), tail.begin(), tail.end());
    tail.clear();

    REP (i, N) REP (j, M) {
	if (j < 2) continue;
	s = T[i][j];
	for (int k=s.size(); k--;) {
	    if (s[k] == '0') {
		if (i) ans.emplace_back(0, 0, i, 0);
		ans.emplace_back(i, 0, i, j);
	    } else {
		if (i) ans.emplace_back(0, 1, i, 1);
		ans.emplace_back(i, 1, i, j);
	    }
	}
    }

    REP (k, zero(T[0][0])) {
	ans.emplace_back(0, 0, 1, 0);
    }
    REP (k, one(T[0][1])) {
	ans.emplace_back(0, 1, 1, 1);
    }

    for (int i=1; i<N; i++) {
	REP (k, one(T[i][0])) {
	    ans.emplace_back(0, 1, i, 1);
	}
	REP (k, zero(T[i][1])) {
	    ans.emplace_back(0, 0, i, 0);
	}
	s = T[i][0];
	for (int k=s.size(); k--;) {
	    if (s[k] == '0') {
		ans.emplace_back(0, 0, i, 0);
	    } else {
		ans.emplace_back(i, 1, i, 0);
	    }
	}
	s = T[i][1];
	for (int k=s.size(); k--;) {
	    if (s[k] == '0') {
		ans.emplace_back(i, 0, i, 1);
	    } else {
		ans.emplace_back(0, 1, i, 1);
	    }
	}
    }

    s = T[0][0];
    for (int k=s.size(); k--;) {
	if (s[k] == '0') {
	    ans.emplace_back(1, 0, 0, 0);
	} else {
	    ans.emplace_back(0, 1, 0, 0);
	}
    }
    s = T[0][1];
    for (int k=s.size(); k--;) {
	if (s[k] == '0') {
	    ans.emplace_back(0, 0, 0, 1);
	} else {
	    ans.emplace_back(1, 1, 0, 1);
	}
    }

    printf("%d\n", (int)ans.size());
    EACH (e, ans) {
	int a, b, c, d;
	tie(a, b, c, d) = *e;
	assert((a == c && b != d) || (a != c && b == d));
	a++; b++; c++; d++;
	printf("%d %d %d %d\n", a, b, c, d);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}