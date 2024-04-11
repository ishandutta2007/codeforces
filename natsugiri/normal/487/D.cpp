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

struct Seg {
    pair<int, int> val[12]; // (diff, pos_y)
    Seg() { REP (i, 12) val[i] = make_pair(-2, i); } 
    Seg(const string &s) {
	REP (i, s.size()) {
	    int p = i;
	    while (p && s[p] == '<') p--;
	    while (p < (int)s.size() && s[p] == '>') p++;
	    if (s[p] == '<') val[i] = make_pair(-1, -1);
	    else if (s[p] == '&' || s[p] == '$') val[i] = make_pair(0, p);
	    else val[i] = make_pair(1, p);
	}
    }
};

int M;
Seg operator*(const Seg &x, const Seg &y) {
    if (x.val[0].first == -2) return y;
    if (y.val[0].first == -2) return x;
    // TODO: do stuff something
    Seg z;
    REP (i, 12) {
	if (y.val[i].first <= 0 || 
		y.val[i].second <= 0 || (int)y.val[i].second == M+1) z.val[i] = y.val[i];
	else {
	    const pair<int, int> k = x.val[(int)y.val[i].second];
	    if (k.first == -1) z.val[i] = k;
	    else z.val[i] = make_pair(k.first + y.val[i].first, k.second);
	}
    }
    return z;
};

const Seg unit = Seg();
struct SegmentTree {
    int n;
    vector<Seg> d;
    SegmentTree(int n_=0): n(n_), d(2*n) { }
    SegmentTree(const vector<Seg> & d_): n(d_.size()), d(2*n) {
	for (int i=0; i<n; i++) d[i+n] = d_[i];
	for (int i=n; --i; ) d[i] = d[i*2] * d[i*2+1];
    }
    void modify(int i, const Seg &s) {
	i += n;
	d[i] = s;
	for (i/=2; i; i/=2) d[i] = d[i*2] * d[i*2+1];
    }
    Seg query(int x, int y) {
	x += n; y += n;
	Seg ls = Seg(), rs = Seg();
	for (; x < y; x>>=1, y>>=1) {
	    if (y & 1) rs = d[--y] * rs;
	    if (x & 1) ls = ls * d[x++];
	}
	return ls * rs;
    }
};

int N, Q;
char F[100011][15];

int main() {
    scanf("%d%d%d", &N, &M, &Q);
    vector<Seg> segs;
    REP (i, N) scanf("%s", F[i]);
    REP (i, N) {
	segs.emplace_back(string(1, '&') + F[i] + '$');
    }

    SegmentTree X(segs);

    REP ($, Q) {
	char op[9];
	scanf("%s", op);
	if (*op == 'A') {
	    int x, y;
	    scanf("%d%d", &x, &y);
	    Seg s = X.query(0, x);
	    if (s.val[y].second == -1) puts("-1 -1");
	    else printf("%d %d\n", x - s.val[y].first, s.val[y].second);

	} else {
	    int x, y; char dir[9];
	    scanf("%d%d%s", &x, &y, dir);
	    F[x-1][y-1] = *dir;
	    X.modify(x-1, string(1, '&') + F[x-1] + '$');
	}
    }

    return 0;
}