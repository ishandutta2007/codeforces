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

const int SIZE = 100011;
int N, M;
bool C[SIZE];
VI G[SIZE];
int deg[SIZE];
stack<int> S[2];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) {
	char s[3];
	scanf("%s", s);
	C[i] = *s - '0';
    }

    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	G[y].push_back(x);
	deg[x]++;
    }


    REP (i, N) if (deg[i] == 0) {
	S[C[i]].push(i);
    }

    int ans = 0;
    while (!S[0].empty() || !S[1].empty()) {
	while (!S[0].empty()) {
	    int v = S[0].top(); S[0].pop();
	    EACH (e, G[v]) {
		deg[*e]--;
		if (deg[*e] == 0) {
		    S[C[*e]].push(*e);
		}
	    }
	}

	if (!S[1].empty()) ans++;

	while (!S[1].empty()) {
	    int v = S[1].top(); S[1].pop();
	    EACH (e, G[v]) {
		deg[*e]--;
		if (deg[*e] == 0) {
		    S[C[*e]].push(*e);
		}
	    }
	}
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}