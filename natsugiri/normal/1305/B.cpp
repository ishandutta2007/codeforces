#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
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
char S[1011];

void MAIN() {
    scanf("%s", S);
    N = strlen(S);
    vector<VI> ans;
    while (1) {
	VI pos;
	int l = 0;
	int r = N-1;
	while (1) {
	    while (l < N && S[l] != '(') l++;
	    while (r >= 0 && S[r] != ')') r--;
	    if (l < r) {
		pos.push_back(l+1);
		pos.push_back(r+1);
		S[l] = S[r] = '.';
	    } else {
		break;
	    }
	}
	
	if (pos.empty()) break;
	else ans.push_back(pos);
    }

    printf("%d\n", (int)ans.size());
    REP (i, ans.size()) {
	sort(ans[i].begin(), ans[i].end());
	printf("%d\n", (int)ans[i].size());
	rprintf("%d", ans[i].begin(), ans[i].end());
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}