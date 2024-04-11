#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

int ord(char c) {
    if (isalpha(c)) return c - 'a';
    assert(c == '_');
    return 26;
}

int encode(const string &s) {
    int ret = 0;
    REP (i, s.size()) {
	ret = ret * 27 + ord(s[i]);
    }
    return ret;
}

int N, M, K;
int P[100011];

int idx[540011];

string S[100011];
int MT[100011];

char buf[111];


VI G[100011];

int deg[100011];


bool ok;
void rec(const string &s, int mt, int I, int p) {
    if (I == K) {
	if (idx[p] == -1) return;
	if (idx[p] == mt) {
	    ok = true;
	} else {
	    G[mt].push_back(idx[p]);
	}
    } else {
	rec(s, mt, I+1, p * 27 + ord(s[I]));
	rec(s, mt, I+1, p * 27 + ord('_'));
    }
}

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);

    memset(idx, -1, sizeof idx);

    REP (i, N) {
	scanf("%s", buf);
	int p = encode(buf);
	P[i] = p;
	idx[p] = i;
    }

    bool yes = true;

    REP (i, M) {
	int mt;
	scanf("%s%d", buf, &mt);
	S[i] = buf;
	MT[i] = mt-1;

	ok = false;
	rec(S[i], MT[i], 0, 0);

	if (!ok) {
	    yes = false;
	}
    }

    if (yes) {
	REP (i, N) {
	    EACH (e, G[i]) deg[*e]++;
	}

	VI que;
	REP (i, N) if (deg[i] == 0) que.push_back(i);
	for (int i=0; i<(int)que.size(); i++) {
	    int v = que[i];
	    EACH (e, G[v]) {
		deg[*e]--;
		if (deg[*e] == 0) que.push_back(*e);
	    }
	}

	if ((int)que.size() == N) {
	    puts("YES");
	    EACH (e, que) (*e)++;
	    rprintf("%d", que.begin(), que.end());
	    return;
	}
    }

    puts("NO");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}