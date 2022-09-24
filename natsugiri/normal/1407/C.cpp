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

int N;
bool use[100011];
int ans[100011];

int p[100011];

void init() {
#ifdef LOCAL
    REP (i, N) p[i] = i+1;
    random_shuffle(p, p+N);
    rprintf("%d", p, p+N);
#endif
}

int query(int x, int y) {
    printf("? %d %d\n", x+1, y+1);
    fflush(stdout);

#ifdef LOCAL
    eprintf("--> %d\n", p[x] % p[y]);
    return p[x] % p[y];
#else
    int ret;
    scanf("%d", &ret);
    return ret;
#endif
}

void MAIN() {
    scanf("%d", &N);

    init();

    VI cur, nxt;
    cur.reserve(N);
    REP (i, N) cur.push_back(i);

    while (cur.size() >= 2u) {
	nxt.clear();
	int i;
	for (i=0; i+2<=(int)cur.size(); i+=2) {
	    int a = cur[i];
	    int b = cur[i+1];
	    int ab = query(a, b);
	    int ba = query(b, a);
	    if (ab < ba) {
		ans[b] = ba;
		use[ba] = true;
		nxt.push_back(a);
	    } else {
		ans[a] = ab;
		use[ab] = true;
		nxt.push_back(b);
	    }

	}

	if (i < (int)cur.size()) nxt.push_back(cur[i]);

	swap(cur, nxt);
    }

    for (int x=1; x<=N; x++) if (!use[x]) {
	ans[cur[0]] = x;
    }

    printf("! ");
    rprintf("%d", ans, ans+N);

#ifdef LOCAL
    REP (i, N) assert(p[i] == ans[i]);
#endif
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}