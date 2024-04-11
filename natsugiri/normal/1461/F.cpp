#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

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


const LL INF = 1LL<<30;
struct Safe {
    LL x;
    Safe(): x(0) {}
    Safe(LL x_): x(x_) {}

    Safe operator+(const Safe&o) const {
	return Safe(min(INF, x + o.x));
    }

    Safe operator*(const Safe&o) const {
	return Safe(min(INF, x * o.x));
    }

    bool operator<(const Safe &o) const {
	return x < o.x;
    }
};

struct Data {
    int l, r;
    Safe s;

    Data() {}
    Data(int l_, int r_, Safe s_): l(l_), r(r_), s(s_) {}
};

int N;
int A[100011];
char S[5];
char X[100011];
char IN[100011];

bool ADD, SUB, MUL;

vector<Data> stk;
vector<Data> stk2;

LL dpA[211][211];
LL dpM[211][211];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    scanf("%s", S);

    ADD = SUB = MUL = 0;
    REP (i, 3) {
	if (S[i] == '+') ADD = true;
	if (S[i] == '-') SUB = true;
	if (S[i] == '*') MUL = true;
    }

    if (strlen(S) == 1) {
	REP (i, N) {
	    printf("%d%c", A[i], (i==N-1? '\n': S[0]));
	}
    } else if (ADD && MUL) {
	int i = 0;
	while (i < N) {
	    if (A[i] == 0) {
		if (i) putchar('+');
		printf("0");
		i++;
	    } else if (A[i] == 1) {
		if (i) putchar('+');
		printf("1");
		i++;
	    } else {
		int i_bk = i;
		Safe prod(1);
		stk.clear();
		while (i < N && A[i] != 0) {
		    if (A[i] == 1) {
			int j = i;
			while (j < N && A[j] == 1) j++;
			stk.emplace_back(i, j, 1);
			i = j;
		    } else {
			int j = i;
			Safe s(1);
			while (j < N && A[j] > 1) {
			    s = s * Safe(A[j]);
			    j++;
			}
			stk.emplace_back(i, j, s);
			prod = prod * s;
			i = j;
		    }
		}

		if (stk.back().s.x == 1) {
		    i = stk.back().l;
		    stk.pop_back();
		}

		const int len = stk.size();
		if (prod.x >= INF/2) {
		    REP (j, len) {
			X[j] = '*';
			IN[j] = '*';
		    }
		} else {
		    REP (x, len) REP (y, len+1) dpM[x][y] = 0;
		    REP (x, len) dpM[x][x+1] = stk[x].s.x;
		    for (int x=len-1; x>=0; x--) {
			for (int y=x+1; y<len; y++) {
			    for (int z=y+1; z<=len; z++) {
				amax(dpM[x][z], dpM[x][y] * dpM[y][z]);
			    }
			}
		    }

		    REP (x, len) for (int y=x+1; y<=len; y++) dpA[x][y] = dpM[x][y];

		    REP (x, len) if (stk[x].s.x == 1) {
			amax(dpA[x][x+1], (LL)stk[x].r - stk[x].l);
		    }

		    for (int x=len-1; x>=0; x--) {
			for (int y=x+1; y<len; y++) {
			    for (int z=y+1; z<=len; z++) {
				amax(dpA[x][z], dpA[x][y] + dpA[y][z]);
			    }
			}
		    }

		    stk2.clear();
		    stk2.emplace_back(0, len, 0);
		    X[0] = '+';
		    while (!stk2.empty()) {
			Data d = stk2.back();
			stk2.pop_back();
			LL val = dpA[d.l][d.r];

			if (dpM[d.l][d.r] == val) {
			    for (int j=d.l; j<d.r; j++) IN[j] = '*';
			    assert(X[d.l] == '+');
			    X[d.l] = '+';
			    for (int j=d.l+1; j<d.r; j++) X[j] = '*';
			} else if (d.l + 1 == d.r) {
			    IN[d.l] = '+';
			    assert(X[d.l] == '+');
			    X[d.l] = '+';
			} else {
			    bool ok = false;
			    for (int y=d.l+1; y<d.r; y++) {
				if (dpA[d.l][y] + dpA[y][d.r] == val) {
				    X[y] = '+';
				    stk2.emplace_back(d.l, y, 0);
				    stk2.emplace_back(y, d.r, 0);
				    ok = true;
				    break;
				}
			    }
			    assert(ok);
			}
		    }
		}

		REP (x, len) {
		    for (int j=stk[x].l; j<stk[x].r; j++) {
			if (j == 0) {

			} else if (j == i_bk) {
			    putchar('+');
			} else if (j == stk[x].l) {
			    putchar(X[x]);
			} else {
			    putchar(IN[x]);
			}
			printf("%d", A[j]);
		    }
		}
	    }
	}
	puts("");
    } else if (ADD) { // ADD && SUB;
	REP (i, N) {
	    printf("%d%c", A[i], (i==N-1? '\n': '+'));
	}
    } else { // SUB && MUL;
	REP (i, N) {
	    printf("%d", A[i]);
	    if (i == N-1) putchar('\n');
	    else if (i+1 < N && A[i+1] == 0) putchar('-');
	    else putchar('*');
	}
    }
}

int main() {
    int TC = 1;
    //    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}