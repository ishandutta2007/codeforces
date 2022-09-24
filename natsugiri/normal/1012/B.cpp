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

int N, M, Q;
VI Gx[200011], Gy[200011];
bool tx[200011], ty[200011];

void MAIN() {
    scanf("%d%d%d", &N, &M, &Q);
    REP (i, Q) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	Gx[x].push_back(y);
	Gy[y].push_back(x);
    }

    int ans = 0;
    REP (i, N) {
	if (tx[i] || Gx[i].empty()) continue;

	ans++;
	stack<int> sx, sy;
	sx.push(i);
	tx[i] = true;
	while (!sx.empty() || !sy.empty()) {
	    while (!sx.empty()) {
		int x = sx.top(); sx.pop();
		EACH (e, Gx[x]) if (!ty[*e]) {
		    ty[*e] = true;
		    sy.push(*e);
		}
	    }
	    while (!sy.empty()) {
		int y = sy.top(); sy.pop();
		EACH (e, Gy[y]) if (!tx[*e]) {
		    tx[*e] = true;
		    sx.push(*e);
		}
	    }
	}
    }

    REP (i, N) if (!tx[i]) ans++;
    REP (i, M) if (!ty[i]) ans++;
    printf("%d\n", ans-1);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}