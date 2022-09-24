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

pair<int, int> calc(const string &s) {
    pair<int, int> ret(0, 0);
    int cnt = 0;
    int m = s.size();
    REP (i, m) {
	if (s[i] == '(') cnt--;
	else cnt++;
	amax(ret.first, cnt);
    }

    cnt = 0;
    REP (i, m) {
	if (s[m-1-i] == ')') cnt--;
	else cnt++;
	amax(ret.second, cnt);
    }
    return ret;
}

int N;
char buf[500111];
int C[500111];

void MAIN() {
    scanf("%d", &N);

    int ans = 0;
    REP (i, N) {
	scanf("%s", buf);
	pair<int, int> p = calc(buf);

	if (p.first == 0) {
	    if (C[p.second] > 0) ans++;
	    C[p.second]--;
	} else if (p.second == 0) {
	    if (C[p.first] < 0) ans++;
	    C[p.first]++;
	}
    }

    ans += abs(C[0]) / 2;
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}