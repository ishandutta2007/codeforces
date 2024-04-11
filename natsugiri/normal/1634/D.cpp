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

int query(int i, int j, int k) {
    if (i > j) swap(i, j);
    if (j > k) swap(j, k);
    if (i > j) swap(i, j);
    printf("? %d %d %d\n", i+1, j+1, k+1);
    fflush(stdout);

    int ret;
    scanf("%d", &ret);
    return ret;
}

pair<int, int> FOUR(int a, int b, int c, int d) {
    int arr[4] = {a, b, c, d};
    int val[4];
    VI v;
    REP (i, 4) {
	v.clear();
	REP (j, 4) if (j != i) v.push_back(arr[j]);
	val[i] = query(v[0], v[1], v[2]);
    }

    int ma = *max_element(val, val+4);
    int cnt = count(val, val+4, ma);

    if (cnt == 4) return make_pair(-1, -1);


    // cnt = 2 or 3;
    VI ret;
    REP (i, 4) if (val[i] != ma) ret.push_back(arr[i]);
    ret.push_back(-1);
    return make_pair(ret[0], ret[1]);
}

void answer(int i, int j) {
    printf("! %d %d\n", i+1, j+1);
    fflush(stdout);
}

void MAIN() {
    scanf("%d", &N);

    VI cur, nxt;
    REP (i, N) cur.push_back(i);

    while (cur.size() >= 4) {
	nxt.clear();
	while (cur.size() >= 4) {
	    int a = cur.back(); cur.pop_back();
	    int b = cur.back(); cur.pop_back();
	    int c = cur.back(); cur.pop_back();
	    int d = cur.back(); cur.pop_back();
	    pair<int, int> p = FOUR(a, b, c, d);
	    if (p.first != -1) nxt.push_back(p.first);
	    if (p.second != -1) nxt.push_back(p.second);
	}
	cur.insert(cur.end(), nxt.begin(), nxt.end());
    }

    int ansX, ansY;
    if (cur.size() == 1u) {
	ansX = cur[0];
	ansY = -1;
    } else if (cur.size() == 2u) {
	ansX = cur[0];
	ansY = cur[1];
    } else if (cur.size() == 3u) {
	REP (a, N) {
	    if (cur[0] != a && cur[1] != a && cur[2] != a) {
		cur.push_back(a);
		break;
	    }
	}
	pair<int, int> p = FOUR(cur[0], cur[1], cur[2], cur[3]);
	ansX = p.first;
	ansY = p.second;
    } else {
	assert(false);
	ansX = 0;
	ansY = 1;
    }

    if (ansY == -1) ansY = (ansX + 1) % N;

    answer(ansX, ansY);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}