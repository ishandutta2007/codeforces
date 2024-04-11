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
int Q;
char S[100011];
int nxt[100011][26];

int dp[255][255][255]; 
string A, B, C;

inline void update(int &dst, int idx, char c) {
    if (idx < N) {
	amin(dst, nxt[idx][c-'a']+1);
    }
}

const int INF = 1<<29;

void MAIN() {
    scanf("%d%d", &N, &Q);
    scanf("%s", S);

    REP (c, 26) nxt[N][c] = N;
    for (int i=N; i--;) {
	REP (c, 26) nxt[i][c] = nxt[i+1][c];
	nxt[i][S[i]-'a'] = i;
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0] = 0;

    REP ($, Q) {
	char op[11];
	scanf("%s", op);
	if (*op == '+') {
	    int id; char h[11];
	    scanf("%d%s", &id, h);
	    id--;

	    int alo = 0, ahi = A.size();
	    int blo = 0, bhi = B.size();
	    int clo = 0, chi = C.size();

	    if (false) ;
	    else if (id == 0) { A.push_back(*h); alo = ahi = A.size(); }
	    else if (id == 1) { B.push_back(*h); blo = bhi = B.size(); }
	    else if (id == 2) { C.push_back(*h); clo = chi = C.size(); }

	    for (int i=alo; i<=ahi; i++) for (int j=blo; j<=bhi; j++) for (int k=clo; k<=chi; k++) {
		if (i) update(dp[i][j][k], dp[i-1][j][k], A[i-1]);
		if (j) update(dp[i][j][k], dp[i][j-1][k], B[j-1]);
		if (k) update(dp[i][j][k], dp[i][j][k-1], C[k-1]);
	    }
	} else {
	    int id;
	    scanf("%d", &id);
	    id--;

	    int alo = 0, ahi = A.size();
	    int blo = 0, bhi = B.size();
	    int clo = 0, chi = C.size();

	    if (false) ;
	    else if (id == 0) { alo = ahi; A.pop_back();}
	    else if (id == 1) { blo = bhi; B.pop_back();}
	    else if (id == 2) { clo = chi; C.pop_back();}

	    for (int i=alo; i<=ahi; i++) for (int j=blo; j<=bhi; j++) for (int k=clo; k<=chi; k++) {
		dp[i][j][k] = INF;
	    }
	}

	if (dp[A.size()][B.size()][C.size()] <= N) {
	    puts("YES");
	} else {
	    puts("NO");
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}