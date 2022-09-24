#include<map>
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

int N, K, M;
char buf[100011];
map<string, int> mp;
int C[100011];
int remap[100011];
int aux[100011];

void MAIN() {
    scanf("%d%d%d", &N, &K, &M);
    REP (i, N) {
	scanf("%s", buf);
	mp.emplace(buf, i);
    }
    REP (i, N) scanf("%d", C+i);
    REP (i, K) {
	int len;
	scanf("%d", &len);
	REP (j, len) scanf("%d", aux+j), aux[j]--;
	int m = *min_element(aux, aux+len);
	REP (j, len) {
	    remap[aux[j]] = m;
	    amin(C[m], C[aux[j]]);
	}
    }

    LL ans = 0;
    REP ($, M) {
	scanf("%s", buf);
	ans += C[remap[mp[buf]]];
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}