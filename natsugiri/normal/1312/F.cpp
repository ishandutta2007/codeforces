#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include<map>
#include<array>
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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}
int mex(int a, int b, int c) {
    REP (t, 5) {
	if (a != t && b != t && c != t) return t;
    }
    assert(false);
}
int mex(int a, int b) {
    return mex(a, a, b);
}

int N;
int X, Y, Z;

using Arr = array<char, 15>;
LL A[300011];

struct Data {
    char px[111], py[111], pz[111];

    int line, cycle;

    void build() {
	map<Arr, int> mp;

	px[0] = py[0] = pz[0] = 0;
	cycle = 0;
	for (int i=1; i<111; i++) {
	    int vx = 0, vy = 0, vz = 0;
	    if (i >= X) vx = px[i-X];
	    if (i >= Y) vy = py[i-Y];
	    if (i >= Z) vz = pz[i-Z];

	    px[i] = mex(vx, vy, vz);
	    py[i] = mex(vx, vz);
	    pz[i] = mex(vx, vy);
	    // eprintf("[%d] %d %d %d\n", i, px[i], py[i], pz[i]);

	    if (i >= 4 && cycle == 0) {
		Arr ar;
		int len = 0;
		REP (j, 5) {
		    ar[len++] = px[i-4+j];
		    ar[len++] = py[i-4+j];
		    ar[len++] = pz[i-4+j];
		}

		auto it = mp.lower_bound(ar);
		if (it != mp.end() && it->first == ar) {
		    line = it->second;
		    cycle = i - it->second;
		} else {
		    mp.emplace_hint(it, ar, i);
		}
	    }
	}

	assert(line + cycle + 10 < 111);
	return;
	// eprintf("%d %d\n", line, cycle);
    }

    void solve() {
	int game = 0;
	const int BASE = line + 10;
	REP (i, N) {
	    LL a = A[i];
	    if (a >= BASE) a = (a - BASE) % cycle + BASE;
	    game ^= px[a];
	}
	int ans = 0;
	REP (i, N) {
	    LL a = A[i];
	    if (a == 0) continue;
	    if (a >= BASE) a = (a - BASE) % cycle + BASE;

	    int s = px[a];
	    int vx = 0, vy = 0, vz = 0;
	    if (a >= X) vx = px[a-X];
	    if (a >= Y) vy = py[a-Y];
	    if (a >= Z) vz = pz[a-Z];
	    if ((game^s^vx) == 0) ans++;
	    if ((game^s^vy) == 0) ans++;
	    if ((game^s^vz) == 0) ans++;
	}
	printf("%d\n", ans);
    }
} D[126];

void MAIN() {
    scanf("%d%d%d%d", &N, &X, &Y, &Z);
    int key = (X-1) * 25 + (Y-1) * 5 + (Z-1);
    REP (i, N) scanf("%lld", A+i);
    D[key].solve();
}

int main() {
    REP (x, 5) REP (y, 5) REP (z, 5) {
	X = x+1;
	Y = y+1;
	Z = z+1;
	int key = x * 25 + y * 5 + z;
	D[key].build();
    }

    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}