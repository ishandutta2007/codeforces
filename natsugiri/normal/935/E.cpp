#include<stack>
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

char S[10011];
int P, M;
int N;

VI G[10011];
int mi[10011][111], ma[10011][111];
int C[10011];


void MAIN() {
    scanf("%s", S);
    N = strlen(S);
    scanf("%d%d", &P, &M);

    if (N == 1) {
	printf("%d\n", S[0] - '0');
	return;
    }

    stack<int> st;
    st.push(0);
    int cur = 1;
    memset(mi, 0x3f, sizeof mi);
    memset(ma, 0xc0, sizeof ma);


    for (int i=1; i<N; i++) {
	if (S[i] == '(') {
	    G[st.top()].push_back(cur);
	    st.push(cur++);
	} else if (S[i] == ')') {
	    st.pop();
	} else if (isdigit(S[i])) {
	    mi[cur][0] = ma[cur][0] = S[i] - '0';
	    G[st.top()].push_back(cur++);
	}
    }

    int ans = 0;

    if (P <= M) {
	for (int i=cur; i--;) {
	    if (G[i].size() == 2u) {
		int x = G[i][0];
		int y = G[i][1];
		C[i] = C[x] + C[y] + 1;
		REP (p, min(P, C[x])+1) {
		    REP (q, min(P, C[y])+1) {
			if (p+q+1 <= P) {
			    amin(mi[i][p+q+1], mi[x][p] + mi[y][q]);
			    amax(ma[i][p+q+1], ma[x][p] + ma[y][q]);
			}
			if (p+q <= P) {
			    amin(mi[i][p+q], mi[x][p] - ma[y][q]);
			    amax(ma[i][p+q], ma[x][p] - mi[y][q]);
			} else {
			    break;
			}
		    }
		}
	    }
	}
	ans = ma[0][P];
    } else {
	for (int i=cur; i--;) {
	    if (G[i].size() == 2u) {
		int x = G[i][0];
		int y = G[i][1];
		C[i] = C[x] + C[y] + 1;
		REP (p, min(M, C[x])+1) {
		    REP (q, min(M, C[y])+1) {
			if (p+q+1 <= M) {
			    amin(mi[i][p+q+1], mi[x][p] - ma[y][q]);
			    amax(ma[i][p+q+1], ma[x][p] - mi[y][q]);
			}
			if (p+q <= M) {
			    amin(mi[i][p+q], mi[x][p] + mi[y][q]);
			    amax(ma[i][p+q], ma[x][p] + ma[y][q]);
			} else {
			    break;
			}
		    }
		}
	    }
	}
	ans = ma[0][M];
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}