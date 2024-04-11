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
char S[600011];
VI G[300011];
int Lp[600011];
int Rp[600011];

void MAIN() {
    scanf("%d", &N);
    scanf("%s", S);

    int ans, L, R;
    if (count(S, S+N, '(') * 2 != N) {
	ans = 0;
	L = R = 0;
    } else {
	REP (i, N) S[i+N] = S[i];
	int depth = 0;
	int mi = 0;
	int shift = 0;
	for (int i=N; i--;) {
	    if (S[i] == '(') depth--;
	    else depth++;
	    if (mi > depth) {
		mi = depth;
		shift = i;
	    }
	}

	VI st;
	st.push_back(0);
	int id = 1;
	depth = 0;
	REP (i, N) {
	    if (S[i+shift] == '(') {
		G[st.back()].push_back(id);
		st.push_back(id);
		Lp[id] = i + shift;
		id++;
	    } else {
		Rp[st.back()] = i + shift;
		st.pop_back();
	    }
	}

	ans = G[0].size();
	L = R = 0;

	EACH (e, G[0]) {
	    int tmp = G[*e].size() + 1;
	    if (ans < tmp) {
		ans = tmp;
		L = Lp[*e];
		R = Rp[*e];
	    }

	    EACH (f, G[*e]) {
		tmp = G[*f].size() + 1 + G[0].size();
		if (ans < tmp) {
		    ans = tmp;
		    L = Lp[*f];
		    R = Rp[*f];
		}
	    }
	}

//	REP (i, N) putchar(S[i+shift]);
//	puts("");
    }


    printf("%d\n", ans);
    printf("%d %d\n", L%N+1, R%N+1);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}