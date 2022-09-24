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

int N, M;
char op[100111];
int A[100111];
int C[100111];
bool may[100111];
bool non[100111];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, M) scanf("%s%d", op+i, A+i), A[i]--;

    int cnt = 0;
    REP (i, M) {
	if (op[i] == '-' && C[A[i]] == 0) cnt++;
	C[A[i]]++;
    }

    REP (i, M) {
	if (op[i] == '+') {
	    if (cnt == 0) may[A[i]] = true;
	    else non[A[i]] = true;
	    cnt++;
	} else {
	    if (cnt == 1) may[A[i]] = true;
	    else non[A[i]] = true;
	    cnt--;
	}
    }

    cnt = 0;
    REP (i, N) if (may[i]) cnt++;
    if (cnt == 1) REP (i, N) if (may[i] && !non[i]) C[i] = 0;

    VI ans;
    REP (i, N) if (C[i] == 0) ans.push_back(i+1);
    printf("%d\n", (int) ans.size());
    if (ans.size()) rprintf("%d", ans.begin(), ans.end());


    return 0;
}