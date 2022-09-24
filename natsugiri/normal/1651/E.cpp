#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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

int N;
VI G[3011];
bool use[3011];

LL tri(LL x) {
    return x * (x + 1) / 2;
}

LL way(int v, int right_prev, int right_next) {
    if (right_prev > right_next) swap(right_prev, right_next);
    return LL(v + 1) * (N - v) 
	* (tri(right_prev-N) + tri(right_next - right_prev - 1) + tri(2*N - right_next - 1));
}
LL way(int left_min, int left_max, int right_min, int right_max, int right_prev, int right_next) {
    if (right_prev > right_next) swap(right_prev, right_next);

    LL m = 0;
    if (right_next < right_min) {
	m = (LL)(right_min - right_next) * (LL)(2*N - right_max);
    } else if (right_max < right_prev) {
	m = (LL)(right_min - N + 1) * (LL)(right_prev - right_max);
    } else if (right_prev < right_min && right_max < right_next) {
	m = (LL)(right_min - right_prev) * (LL)(right_next - right_max);
    }
    return m * (left_min + 1) * (N - left_max);
}

LL calc(VI vs) {
    LL sum = 0;
    REP (t, 2) {

	for (int i=0; i<(int)vs.size(); i+=2) {
	    int left_min = vs[i];
	    int left_max = vs[i];

	    int right_prev = vs[(i-1+vs.size()) % vs.size()];
	    int right_next = vs[(i+1) % vs.size()];
	    sum += way(vs[i], right_prev, right_next);

	    int right_min = 1<<29;
	    int right_max = -1;
	    int j = i;

	    REP (c, vs.size() / 2-1) {
		j++;
		if (j == (int)vs.size()) j = 0;
		amin(right_min, vs[j]);
		amax(right_max, vs[j]);

		j++;
		if (j == (int)vs.size()) j = 0;
		amin(left_min, vs[j]);
		amax(left_max, vs[j]);

		right_next = vs[(j+1) % vs.size()];
		LL tmp = way(left_min, left_max, right_min, right_max, right_prev, right_next);
		sum += tmp;

//		printf("[%d] %d %d %d %d %d %d : %lld\n", 
//			vs[i],
//			left_min,
//			left_max,
//			right_min,
//			right_max,
//			right_prev, right_next,
//			tmp);
	    }
	}

	REP (i, vs.size()) {
	    if (vs[i] < N) vs[i] += N;
	    else vs[i] -= N;
	}
	reverse(vs.begin(), vs.end());
    }
    return sum;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, 2*N) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    LL sum = 0;
    REP (i, 2*N) if (!use[i]) {
	VI vs;
	int p = -1, x = i;
	while (!use[x]) {
	    vs.push_back(x);
	    use[x] = true;
	    EACH (e, G[x]) if (*e != p) {
		p = x;
		x = *e;
		break;
	    }
	}

	LL tmp = calc(vs);
	sum += tmp;
    }

    LL ans = 0;
    REP (i, N) {
	LL m = (LL)(i+1) * (N-i) * tri(N) * 2;
	ans += m;
    }

    ans -= sum;
    ans /= 2;
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}