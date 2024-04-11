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
char buf[1000011];
string S[100011];

LL cur[26], nxt[26];

void update(LL c[26], const string &s) {
    int pre = -1;
    int cnt = 0;
    REP (i, s.size()) {
	if (s[i] == pre) {
	    cnt++;
	} else {
	    pre = s[i];
	    cnt = 1;
	}
	amax(c[pre - 'a'], (LL)cnt);
    }
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%s", buf);
	S[i] = buf;
    }

    update(cur, S[0]);

    for (int i=1; i<N; i++) {

	REP (c, 26) {
	    if (cur[c]) nxt[c] = 1;
	    else nxt[c] = 0;
	}
	update(nxt, S[i]);

	int len = S[i].size();
	LL prefix = len;
	REP (j, len) if (S[i][0] != S[i][j]) {
	    prefix = j;
	    break;
	}

	LL suffix = len;
	for (int j=len-1; j>=0; j--) if (S[i].back() != S[i][j]) {
	    suffix = len - 1 - j;
	    break;
	}

	if (prefix == len) {
	    int pos = S[i][0] - 'a';
	    amax(nxt[pos], (LL)len * (cur[pos] + 1) + cur[pos]);
	} else {
	    int pos;
	    pos = S[i][0] - 'a';
	    amax(nxt[pos], (cur[pos]? 1 : 0) + prefix);

	    int ppp;
	    ppp = S[i].back() - 'a';
	    amax(nxt[ppp], (cur[ppp]? 1 : 0) + suffix);

	    if (pos == ppp && cur[ppp]) {
		amax(nxt[ppp], prefix + 1 + suffix);
	    }
	}

	REP (c, 26) cur[c] = min(1LL<<30, nxt[c]);
    }

    LL ans = *max_element(cur, cur+26);
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}