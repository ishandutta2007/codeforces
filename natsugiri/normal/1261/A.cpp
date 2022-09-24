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

int N, K;
char S[2011];

void MAIN() {
    scanf("%d%d%s", &N, &K, S);

    vector<pair<int, int> > ans;
    for (int i=0; i<N; ) {
	if (K == 1) {
	    while (i < N) {
		int p;
		if (S[i] == ')' && (p=find(S+i, S+N, '(')-S) < N) {
		    ans.emplace_back(i, p+1);
		    reverse(S+i, S+p+1);
		}
		i++;
	    }
	    break;
	} else {
	    if (S[i] == ')') {
		for (int j=i; j<N; j++) if (S[j] == '(') {
		    ans.emplace_back(i, j+1);
		    reverse(S+i, S+j+1);
		    break;
		}
	    }
	    i++;
	    if (S[i] == '(') {
		for (int j=i; j<N; j++) if (S[j] == ')') {
		    ans.emplace_back(i, j+1);
		    reverse(S+i, S+j+1);
		    break;
		}
	    }
	    i++;
	    K--;
	}
    }
    printf("%d\n", (int)ans.size());
    EACH (e, ans) printf("%d %d\n", e->first+1, e->second);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}