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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

template<class T> void sort_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}
int N;
int A[111];
int B[111];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i), A[i]--;

    vector<VI> ans;
    VI sep;
    while (1) {
	REP (i, N) {
	    REP (j, i) if (A[j] == A[i]+1) {
		for (int k=j; k<i; k++) if (A[k] > A[k+1]) {
		    sep.clear();
		    sep.push_back(0);
		    sep.push_back(j);
		    sep.push_back(k+1);
		    sep.push_back(i+1);
		    sep.push_back(N);
		    sort_unique(sep);

		    ans.emplace_back();
		    int end = N;
		    for (int a=0; a<(int)sep.size()-1; a++) {
			ans.back().push_back(sep[a+1] - sep[a]);

			end -= sep[a+1] - sep[a];
			for (int b=sep[a], c=0; b<sep[a+1]; b++, c++) {
			    B[end+c] = A[b];
			}
		    }

		    REP (a, N) A[a] = B[a];
		    goto CONTINUE;
		}
	    }
	}

	break;
CONTINUE:

	continue;
    }

    printf("%d\n", (int)ans.size());
    REP (i, ans.size()) {
	printf("%d ", (int)ans[i].size());
	rprintf("%d", ans[i].begin(), ans[i].end());
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}