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
const int MAXN = 1000111;
int A[MAXN];
int P[MAXN];
VI G[MAXN];
VI ord;
int dp[MAXN], dp_pos[MAXN];

int main() {
    scanf("%d", &N);
    int root = 0;
    REP (i, N) {
	int a, b;
	scanf("%d%d", &a, &b);
	a--;
	A[i] = b;
	if (a < 0) {
	    root = i;
	} else {
	    G[a].push_back(i);
	}
    }

    int sum = 0;
    REP (i, N) sum += A[i];
    if (sum % 3 != 0) {
	puts("-1");
	return 0;
    }


    ord.reserve(N); ord.push_back(root);
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) {
	    ord.push_back(*e);
	}
    }

    memset(dp_pos, -1, sizeof dp_pos);
    VI cut;
    REP (i_, N) {
	int v = ord[N-1-i_];
	dp[v] = A[v];
	cut.clear();

	EACH (e, G[v]) {
	    dp[v] += dp[*e];
	    if (dp_pos[*e] != -1) cut.push_back(dp_pos[*e]);
	}

	if (v != root && cut.size() && dp[v] == sum / 3 * 2) {
	    cut.push_back(v);
	}
	if (cut.size() >= 2u) {
	    printf("%d %d\n", cut[0] + 1, cut[1] + 1);
	    return 0;
	}
	if (dp[v] == sum / 3) dp_pos[v] = v;
	else if (cut.size()) dp_pos[v] = cut[0];
    }

    puts("-1");
    return 0;
}