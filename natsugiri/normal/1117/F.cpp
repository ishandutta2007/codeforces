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

int N, P;
char S[100011];
int A[17][17];
bool B[17][17][1<<17];

bool ban[1<<17];

bool dp[1<<17];
int C[17];

void MAIN() {
    scanf("%d%d", &N, &P);
    scanf("%s", S);
    REP (i, P) REP (j, P) scanf("%d", &A[i][j]);

    REP (i, N) C[S[i]-'a']++;

    vector<char> v;
    REP (i, N) {
	int cur = S[i] - 'a';
	int m = v.size();
	int s = 0;
	for (int j=m-2; j>=0; j--) {
	    int left = v[j] - 'a';
	    if (S[i] == v[j+1]) break;
	    s |= 1 << (v[j+1]-'a');
	    if (A[cur][left] == 0) {
		B[cur][left][s] = true;
	    }
	}
	v.erase(remove(v.begin(), v.end(), S[i]), v.end());
	v.push_back(S[i]);
    }

    REP (i, P) REP (j, P) {
	REP (t, P) if (t != i && t != j)
	    REP (s, 1<<P) if (B[i][j][s]) B[i][j][s|(1<<t)] = true;

	REP (s, 1<<P) if (B[i][j][s]) ban[s] = true;
    }

    int ans = N;

    dp[0] = true;
    REP (s, 1<<P) if (dp[s]) {
	REP (i, P) if (~s>>i&1) {
	    int t = s | (1<<i);
	    if (!ban[t]) {
		dp[t] = true;
	    }
	}

	int tmp = 0;
	REP (i, P) if (~s>>i&1) tmp += C[i];
	amin(ans, tmp);
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}