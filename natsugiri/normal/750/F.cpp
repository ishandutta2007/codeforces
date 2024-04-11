#include<queue>
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

int H;
int A[100111];
bool use[1099];
VI G[1099];

VI query(int x) {
    use[x] = true;
    printf("? %d\n", x+1);
    fflush(stdout);

    scanf("%d", &x);
    VI ret(x);
    REP (i, x) {
	int p;
	scanf("%d", &p);
	ret[i] = p-1;
    }
    return ret;
}
void answer(int x) {
    printf("! %d\n", x+1);
    fflush(stdout);
}

void MAIN() {
    memset(use, 0, sizeof use);
    REP (i, 1099) G[i].clear();

    scanf("%d", &H);
    G[0] = query(0);
    
    if (G[0].size() == 2u) {
	answer(0);
	return;
    }

    deque<int> path;
    path.push_back(0);
    int cur;
    cur = G[0][0];
    while (1) {
	path.push_back(cur);

	G[cur] = query(cur);
	if (G[cur].size() == 2u) {
	    answer(cur);
	    return;
	}

	if (G[cur].size() == 1u) break;

	EACH (e, G[cur]) if (!use[*e]) {
	    cur = *e; break;
	}
    }

    if (G[0].size() == 3u) {
	cur = G[0][1];
	while (1) {
	    path.push_front(cur);

	    G[cur] = query(cur);
	    if (G[cur].size() == 2u) {
		answer(cur);
		return;
	    }

	    if (G[cur].size() == 1u) break;

	    EACH (e, G[cur]) if (!use[*e]) {
		cur = *e; break;
	    }
	}
    }

    int height = 0;
    while (1) {
	height = path.size() / 2 + 1;
	if (height >= 4) break;

	REP (i, height-1) path.pop_back();

	cur = path.back();
	EACH (e, G[cur]) if (!use[*e]) { cur = *e;  break; }

	while (1) {
	    path.push_back(cur);

	    G[cur] = query(cur);
	    if (G[cur].size() == 2u) {
		answer(cur);
		return;
	    }

	    if (G[cur].size() == 1u) break;

	    EACH (e, G[cur]) if (!use[*e]) {
		cur = *e; break;
	    }
	}
    }

    int s = path[path.size()/2];
    EACH (e, G[s]) if (!use[*e]) { cur = *e; break; }
    VI ord(1, cur);
    for (int k=0; k<6 && k <(int)ord.size(); k++) {
	int v = ord[k];
	G[v] = query(v);
	if (G[v].size() == 2u) {
	    answer(v);
	    return;
	}

	EACH (e, G[v]) if (!use[*e]) ord.push_back(*e);
    }

    answer(ord[6]);
    return;
}



int main() {
    int tt;
    scanf("%d", &tt);
    REP (i, tt) MAIN();
    return 0;
}