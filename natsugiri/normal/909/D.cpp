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

int N;
char S[1000111];
int B[1000111];
int D[1000111];

int L[1000111];
int R[1000111];

void Del(int x) {
    if (L[x] >= 0) R[L[x]] = R[x];
    if (R[x] >= 0) L[R[x]] = L[x];
}


void MAIN() {
    scanf("%s", S);
    N = strlen(S);
//    N = 1000000;
//    REP (i, N) S[i] = rand() % 2 + 'a';

    REP (i, N) {
	L[i] = i - 1;
	R[i] = i + 1;
    }
    R[N-1] = -1;

    int time = 1;
    VI cur; cur.reserve(N);
    REP (i, N) cur.push_back(i);

    int sum = 0;
    while (!cur.empty()) {
	sum += cur.size();
	VI nxt;
	VI dd;

	REP (i, cur.size()) {
	    int x = cur[i];
	    if (D[x]) continue;

	    int le = L[x], ri = R[x];
	    if ((0 <= le && S[le] != S[x]) || (0 <= ri && S[ri] != S[x])) {
		x = cur[i];
		int y = L[x];
		D[x] = time;
		dd.push_back(x);

		while (1) {
		    if (y >= 0 && S[x] != S[y]) {
			D[y] = time;
			x = y;
			y = L[y];
			dd.push_back(x);
		    } else {
			if (y >= 0 && D[y] == 0) {
			    nxt.push_back(y);
			}
			break;
		    }
		}

		x = cur[i];
		y = R[x];
		while (1) {
		    if (y >= 0 && S[x] != S[y]) {
			D[y] = time;
			x = y;
			y = R[y];
			dd.push_back(x);
		    } else {
			if (y >= 0 && D[y] == 0) {
			    nxt.push_back(y);
			}
			break;
		    }
		}

	    } else {

	    }
	}

	EACH (e, dd) {
	    Del(*e);
	}

	cur.clear();
	sort(nxt.begin(), nxt.end());
	nxt.erase(unique(nxt.begin(), nxt.end()), nxt.end());
	EACH (e, nxt) if (D[*e] == 0) cur.push_back(*e);
	time++;
    }

    int ans = *max_element(D, D+N);
    printf("%d\n", ans);
//    eprintf("%d\n", sum);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}