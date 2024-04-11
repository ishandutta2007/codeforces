#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>
#include<array>


#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

using Arr = array<int, 10>;
int N;
int M;
VI A[10];
Arr ban[100011];
Arr buf;

struct Data {
    int i;
    Arr pos;
    LL val;

    Data(){}
    Data(int i_, Arr pos_, LL val_): i(i_), pos(pos_), val(val_) {}

    bool operator<(const Data &o) const {
	return val < o.val;
    }
};

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int c;
	scanf("%d", &c);
	A[i].resize(c);
	REP (j, c) {
	    scanf("%d", &A[i][j]);
	}
    }

    scanf("%d", &M);
    REP (k, M) {
	REP (i, N) {
	    int x;
	    scanf("%d", &x);
	    x--;
	    ban[k][i] = x;
	}
    }
    sort(ban, ban+M);

    LL val = 0;
    REP (i, N) {
	buf[i] = A[i].size() - 1;
	val += A[i].back();
    }
    priority_queue<Data> Q;
    Q.emplace(0, buf, val);

    while (1) {
	Data d = Q.top();
	Q.pop();

	int k = lower_bound(ban, ban+M, d.pos) - ban;
	if (k < M && ban[k] == d.pos) {
	    for (int i=d.i; i<N; i++) if (d.pos[i]) {
		Data nxt;
		nxt.i = i;
		nxt.pos = d.pos;
		nxt.pos[i]--;
		nxt.val = d.val - A[i][d.pos[i]] + A[i][d.pos[i]-1];

		Q.push(nxt);
	    }
	} else {
	    REP (i, N) printf("%d%c", d.pos[i]+1, " \n"[i==N-1]);
	    return;
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}