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
template<class T> struct Line {
    T a, b;
    Line(const T a_, const T b_) : a(a_), b(b_) { }

    T eval(T x) const {
	return a * x + b;
    }
};

//  \       /
//   \     /
//    -----
//
// f(x) = ax + b;
template<class T> struct ConvexHullTrickMaxLinear {
    using Line = ::Line<T>;

    vector<Line> lines;

    void insert(const T a, const T b) {
	if (lines.empty()) {
	    lines.emplace_back(a, b);
	} else if ((lines[0].a < a && a < lines.back().a)
		|| (lines[0].a > a && a > lines.back().a)) {
	    vector<Line> st;
	    while (!lines.empty()
		    && ((lines[0].a < a && a < lines.back().a)
			|| (lines[0].a > a && a > lines.back().a))) {
		st.push_back(lines.back());
		lines.pop_back();
	    }
	    insert(a, b);
	    while (!st.empty()) {
		insert(st.back().a, st.back().b);
		st.pop_back();
	    }
	} else {
	    if ((a <= lines[0].a && lines[0].a < lines.back().a)
		    || (a >= lines[0].a && lines[0].a > lines.back().a)) {
		reverse(lines.begin(), lines.end());
	    }
	    if (lines.back().a == a) {
		if (lines.back().b < b) lines.back().b = b;
		else return;
	    } else {
		lines.emplace_back(a, b);
	    }
	    int sz = lines.size();
	    while (sz >= 3 && cover(lines[sz-3], lines[sz-2], lines[sz-1])) {
		lines[sz-2] = lines.back();
		if (last_index == sz-2) last_index--;
		lines.pop_back();
		sz--;
	    }
	}
    }

    inline bool cover(const Line &s, const Line &t, const Line &u) const {
	if (s.a > t.a) return cover(u, t, s);
	assert(s.a < t.a);
	assert(t.a < u.a);
	return (s.b-t.b)*(u.a-t.a) >= (t.b-u.b)*(t.a-s.a);
    }

    int bisect_index_max(const T x) const {
	int lo = 0, hi = lines.size();
	while (hi - lo > 1) {
	    int m = (lo + hi) / 2;
	    if (lines[m-1].eval(x) < lines[m].eval(x)) lo = m;
	    else hi = m;
	}
	return lo;
    }

    Line bisect_max(const T x) const {
	return lines[bisect_index_max(x)];
    }

    int last_index = 0;

    Line linear_search_max(const T x) {
	amax(last_index, 0);
	amin(last_index, (int)lines.size()-1);
	while (last_index+1 < (int)lines.size() && lines[last_index].eval(x) < lines[last_index+1].eval(x)) 
	    last_index++;
	while (last_index && lines[last_index].eval(x) <= lines[last_index-1].eval(x)) 
	    last_index--;
	return lines[last_index];
    }
};

template<class T> struct ConvexHullTrickMinLinear {
    using Line = ::Line<T>;
    ConvexHullTrickMaxLinear<T> cht;

    void insert(T a, T b) {
	cht.insert(-a, -b);
    }

    Line bisect_min(const T x) const {
	Line l = cht.bisect_max(x);
	return Line(-l.a, -l.b);
    }

    Line linear_search_min(const T x) {
	Line l = cht.linear_search_max(x);
	return Line(-l.a, -l.b);
    }
};

const int MAXN = 500011;
int N;
VI G[MAXN];
LL ans;
inline LL sq(LL x) { return x*x; }

int par[MAXN];
int sz[MAXN];
LL dp[MAXN];

struct CMP {
    bool operator()(const int i, const int j) const {
	return sz[i] < sz[j];
    }
} cmp;

void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    VI ord;
    ord.reserve(N);
    ord.push_back(0);
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    ord.push_back(*e);
	}
    }

    ans = 1LL<<60;
    REP (i_, N) {
	int v = ord[N-1-i_];
	sz[v] = 1;
	sort(G[v].begin(), G[v].end(), cmp);

	ConvexHullTrickMinLinear<LL> X;
	EACH (e, G[v]) if (*e != par[v]) {
	    sz[v] += sz[*e];
	}

	dp[v] = sq(sz[v]);
	bool ins = false;
	EACH (e, G[v]) if (*e != par[v]) {
	    LL tmp = dp[*e] + sq(sz[*e]) - 2LL*N*sz[*e];
	    if (ins) {
		auto l = X.linear_search_min(sz[*e]);
		amin(ans, l.a * sz[*e] + l.b + sq(N) + tmp);
	    }
	    X.insert(2LL*sz[*e], tmp);
	    ins = true;
	    amin(dp[v], dp[*e] + sq(sz[v]-sz[*e]));
	    amin(ans, dp[*e] + sq(N-sz[*e]));
	}
    }

//    eprintf("ans %lld\n", ans);
    ans = sq(N) * 2 - N - ans;
    printf("%lld\n", ans/2);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}