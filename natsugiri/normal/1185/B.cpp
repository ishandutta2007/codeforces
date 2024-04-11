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

char buf[1000111];;

vector<pair<char, int> > get() {
    scanf("%s", buf);
    int len = strlen(buf);
    vector<pair<char, int> > ret;
    for (int i=0; i<len; ) {
	int j = i;
	while (j < len && buf[i] == buf[j]) j++;
	ret.emplace_back(buf[i], j-i);
	i = j;
    }
    return ret;
}

void MAIN() {
    auto s = get();
    auto t = get();
    bool yes = true;
    if (yes) if (s.size() != t.size()) yes = false;
    if (yes) {
	REP (i, s.size()) {
	    if (s[i].first != t[i].first) yes = false;
	    if (s[i].second > t[i].second) yes = false;
	}
    }
    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}