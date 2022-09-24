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

int N;
int S;
VI G[100011];
VI R[100011];
int win[100011];
int lose[100011];
int deg[100011];

bool taskWin() {
    memset(win, -1, sizeof win);
    memset(lose, -1, sizeof lose);
    stack<int> st;
    REP (i, N) if (deg[i] == 0) {
	lose[i] = -2;
	st.push(i);
    }

    while (!st.empty()) {
	int v = st.top(); st.pop();
	if (win[v] != -1) {
	    EACH (e, R[v]) if (lose[*e] == -1) {
		lose[*e] = v;
		st.push(*e);
	    }
	}
	if (lose[v] != -1) {
	    EACH (e, R[v]) if (win[*e] == -1) {
		win[*e] = v;
		st.push(*e);
	    }
	}
    }

    if (win[S] != -1) {
	puts("Win");
	VI ans;
	int cur = S;
	while (1) {
	    ans.push_back(cur+1);
	    cur = win[cur];
	    ans.push_back(cur+1);
	    cur = lose[cur];
	    if (cur == -2) break;
	}
	rprintf("%d", ans.begin(), ans.end());
	return true;
    } else {
	return false;
    }
}

bool checked[100011];
bool in[100011];
bool dfs(int v) {
    if (in[v]) return true;
    in[v] = true;
    if (checked[v]) return false;
    checked[v] = true;
    EACH (e, G[v]) if (dfs(*e)) return true;
    in[v] = false;
    return false;
}

bool taskDraw() {
    if (dfs(S)) {
	puts("Draw");
	return true;
    } else {
	return false;
    }
}

void MAIN() {
    scanf("%d%*d", &N);

    REP (i, N) {
	int c;
	scanf("%d", &c);
	REP (j, c) {
	    int x;
	    scanf("%d", &x);
	    x--;
	    G[i].push_back(x);
	    R[x].push_back(i);
	    deg[i]++;
	}
    }

    scanf("%d", &S);
    S--;
    if (!taskWin() && !taskDraw()) {
	puts("Lose");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}