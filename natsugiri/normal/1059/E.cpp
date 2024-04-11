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

const int MAXN = 100011;
int N, L;
LL S;
LL W[MAXN];
VI G[MAXN];
int par[MAXN];

int cnt_path[MAXN];

vector<pair<LL, int> > H[MAXN];

void MAIN() {
    scanf("%d%d%lld", &N, &L, &S);
    REP (i, N) scanf("%lld", W+i);
    REP (i, N-1) {
	int p;
	scanf("%d", &p);
	p--;
	par[i+1] = p;
	G[p].push_back(i+1);
    }

    for (int v=N; v--;) {
	if (W[v] > S) {
	    puts("-1");
	    return;
	}

	EACH (e, G[v]) {
	    cnt_path[v] += cnt_path[*e];
	}

	bool b = false;
	EACH (e, G[v]) {
	    EACH (f, H[*e]) if (L > f->second && S >= f->first + W[v]) {
		b = true;
		H[v].emplace_back(f->first + W[v], f->second+1);
	    }
	}

	if (b) {
	    sort(H[v].begin(), H[v].end());
	    int cur = 0;
	    for (int i=1; i<(int)H[v].size(); i++) {
		if (H[v][cur].first < H[v][i].first && H[v][cur].second > H[v][i].second) {
		    H[v][++cur] = H[v][i];
		}
	    }
	    H[v].erase(H[v].begin()+cur+1, H[v].end());
	} else {
	    H[v].emplace_back(W[v], 1);
	    cnt_path[v]++;
	}
    }

    printf("%d\n", cnt_path[0]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}