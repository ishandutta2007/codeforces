#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>
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
char buf[1011];
set<string> A, B;

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) {
	scanf("%s", buf);
	A.insert(buf);
    }
    REP (i, M) {
	scanf("%s", buf);
	B.insert(buf);
    }

    int cnt = 0;
    EACH (e, A) { 
	if (B.find(*e) != B.end()) cnt++;
    }

    bool yes ;
    if (cnt & 1) {
	yes = (A.size() >= B.size());
    } else {
	yes = (A.size() > B.size());
    }
    puts(yes? "YES": "NO");


    return 0;
}