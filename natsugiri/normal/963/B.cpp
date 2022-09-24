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

const int MAXN = 200011;
int N;
VI G[MAXN];
int P[MAXN];
int par[MAXN];
int sz[MAXN];

bool in[MAXN];
int deg[MAXN];
int even[MAXN];
VI ord;

bool active(int v) {
    return deg[v] % 2 == 0 && even[v] == 0;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", P+i);

    if (N & 1) {
	REP (i, N) if (P[i]) {
	    int w = P[i]-1;
	    G[i].push_back(w);
	    G[w].push_back(i);
	}
	ord.reserve(N);
	ord.push_back(0);
	REP (i_, N) {
	    int v = ord[i_];
	    EACH (e, G[v]) if (*e != par[v]) {
		ord.push_back(*e);
		par[*e] = v;
	    }
	}

	REP (i_, N) {
	    int v = ord[N-1-i_];
	    sz[v] = 1;
	    EACH (e, G[v]) if (*e != par[v]) {
		sz[v] += sz[*e];
		deg[v]++;
		if (sz[*e] % 2 == 0) even[v]++;
	    }

	    if (v) {
		deg[v]++;
		if (sz[v] % 2 == 1) even[v]++;
	    }
	}

	stack<int> st;
	VI ans;
	REP (i, N) if (active(i)) {
	    in[i] = true;
	    st.push(i);
	}
	while (!st.empty()) {
	    int v = st.top(); st.pop();
	    if (!active(v)) {
		in[v] = false;
		continue;
	    }
	    ans.push_back(v);
	    EACH (e, G[v]) {
		deg[*e]--;
		even[*e]--;
		if (!in[*e] && active(*e)) {
		    in[*e] = true;
		    st.push(*e);
		}
	    }
	}

	if ((int)ans.size() == N) {
	    puts("YES");
	    REP (i, N) printf("%d\n", ans[i]+1);
	} else {
	    puts("NO");
	}
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}