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

int Q;

struct Point {
    int x, y, i;

    bool operator<(const Point &o) const {
	return x != o.x? x < o.x:
	    y != o.y? y < o.y:
	    i < o.i;
    }
} P[300011];

struct Node {
    int parent;
    int x_cnt, y_cnt;
    int time;

    Node(int parent_, int x_cnt_, int y_cnt_, int time_) {
	parent = parent_;
	x_cnt = x_cnt_;
	y_cnt = y_cnt_;
	time = time_;
    }

    int size() const { return x_cnt + y_cnt; }

    LL eval() const { return (LL)x_cnt * y_cnt; }
};

const int LIMIT = 300011;
vector<Node> nodes[LIMIT*2];
VI update;
int stamp = 0;
int Uroot(int x) {
    while (nodes[x].back().parent != x) {
	x = nodes[x].back().parent;
    }
    return x;
}
LL Ulink(int x, int y) {
    x = Uroot(x);
    y = Uroot(y);
    if (x == y) return 0;
    if (nodes[x].back().size() > nodes[y].back().size()) swap(x, y);
    LL ret = -nodes[x].back().eval() - nodes[y].back().eval();
    nodes[y].emplace_back(y,
	    nodes[y].back().x_cnt + nodes[x].back().x_cnt,
	    nodes[y].back().y_cnt + nodes[x].back().y_cnt,
	    stamp);
    nodes[x].emplace_back(y, 0, 0, stamp);
    update.push_back(x);
    update.push_back(y);
    ret += nodes[y].back().eval();
    return ret;
}
LL Uins(int x, int y) {
    y += LIMIT;
    if (nodes[x].empty()) {
	nodes[x].emplace_back(x, 1, 0, stamp);
	update.push_back(x);
    }
    if (nodes[y].empty()) {
	nodes[y].emplace_back(y, 0, 1, stamp);
	update.push_back(y);
    }
    return Ulink(x, y);
}

const int SIZE = 1<<19;
vector<pair<int, int> > seg[SIZE*2];
void add(int x, int y, const pair<int, int> &p, int k, int l, int r) {
    if (y <= l || r <= x) {
    } else if (x <= l && r <= y) {
	seg[k].push_back(p);
    } else {
	add(x, y, p, k*2, l, (l+r)/2);
	add(x, y, p, k*2+1, (l+r)/2, r);
    }
}
void add(int x, int y, const pair<int, int> &p) {
    add(x, y, p, 1, 0, SIZE);
}

LL answer;
LL ans[SIZE];
void run(int k, int l, int r) {
    const LL answer_bak = answer;
    stamp++;
    EACH (e, seg[k]) {
	answer += Uins(e->first, e->second);
    }

    if (l+1 == r) {
	ans[k - SIZE] = answer;
    } else {
	run(k*2, l, (l+r)/2);
	run(k*2+1, (l+r)/2, r);
    }

    // rollback;
    while (!update.empty()) {
	int x = update.back();
	if (nodes[x].back().time == stamp) {
	    nodes[x].pop_back();
	    update.pop_back();
	} else {
	    break;
	}
    }
    answer = answer_bak;
    stamp--;
}

void run() {
    run(1, 0, SIZE);
}

void MAIN() {
    scanf("%d", &Q);
    REP (i, Q) {
	int x, y;
	scanf("%d%d", &x, &y);
	///x--; y--;
	P[i].x = x;
	P[i].y = y;
	P[i].i = i;
    }

    sort(P, P+Q);
    for (int i=0; i<Q; ) {
	int j = i;
	while (j < Q && P[i].x == P[j].x && P[i].y == P[j].y) j++;
	for (int k=i; k<j; k+=2) {
	    int right;
	    if (k+1 < j) right = P[k+1].i;
	    else right = SIZE;

	    add(P[k].i, right, make_pair(P[k].x, P[k].y));
	}
	i = j;
    }

    run();
    rprintf("%lld", ans, ans+Q);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}