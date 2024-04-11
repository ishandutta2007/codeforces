#include<cassert>
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

/*
8 9 7 2 3 1 5 6 4 8
8 9 7 2 3 9 9 6 4 8
8 9 15 10 11 17 17 14 12 16
8 9 15 [10 11 17] 17 14 12 16
(100 + 121 + 289) % 4 == 2
8 9 15 18 19 17 17 14 12 16
1 1 1 1 1 1 1 14 12 16
1 1 1 1 1 1 [1 14 12] 16
(1 + 38416 + 20736) % 4 == 1
*/

int N, M;
LL seed, vmax;
LL A[100011];


struct Data {
    int left;
    int right;
    LL value;

    Data(){};
    Data(const int left_, const int right_, const LL value_) {
	left = left_;
	right = right_;
	value = value_;
    }

    int length() const {
	return right - left;
    }
};

void add(vector<Data>&v, const Data &d) {
    if (v.empty() || v.back().value != d.value) v.push_back(d);
    else v.back().right = d.right;
}

struct ByValue {
    bool operator()(const Data &x, const Data &y) const {
	return x.value < y.value;
    }
} byValue;

LL powMod(LL x, LL y, LL mod) {
    x %= mod;
    LL r = 1;
    for (; y; y>>=1) {
	if (y & 1) (r *= x) %= mod;
	(x *= x) %= mod;
    }
    return r;
}

LL rnd() {
    LL ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;
}

void calc() {
    int sum = 0;

    REP (i, N) A[i] = rnd() % vmax + 1;
    vector<Data> cur, nxt;
    cur.reserve(N);
    nxt.reserve(N);
    REP (i, N) cur.emplace_back(i, i+1, A[i]);

    REP ($, M) {
	int op = rnd() % 4 + 1;
	int l = rnd() % N + 1;
	int r = rnd() % N + 1;
	if (l > r) swap(l, r);

	LL x, y;
	if (op == 3) {
	    x = rnd() % (r - l + 1) + 1;
	} else {
	    x = rnd() % vmax + 1;
	}
	if (op == 4) {
	    y = rnd() % vmax + 1;
	}


	l--;

	if (op == 1) {
	    nxt.clear();
	    EACH (e, cur) {
		Data d;
		if (e->left < l) {
		    d = Data(e->left, min(e->right, l), e->value);
		    add(nxt, d);
		}

		d = Data(max(e->left, l), min(e->right, r), e->value + x);
		if (d.left < d.right) {
		    add(nxt, d);
		}

		if (r < e->right) {
		    d = Data(max(e->left, r), e->right, e->value);
		    add(nxt, d);
		}
	    }

	    swap(nxt, cur);
	} else if (op == 2) {
	    nxt.clear();
	    EACH (e, cur) {
		Data d;
		if (e->left < l) {
		    d = Data(e->left, min(e->right, l), e->value);
		    add(nxt, d);
		}

		d = Data(max(e->left, l), min(e->right, r), x);
		if (d.left < d.right) {
		    add(nxt, d);
		}

		if (r < e->right) {
		    d = Data(max(e->left, r), e->right, e->value);
		    add(nxt, d);
		}
	    }

	    swap(nxt, cur);
	} else if (op == 3) {
	    nxt.clear();
	    EACH (e, cur) {
		Data d;
		d = Data(max(e->left, l), min(e->right, r), e->value);
		if (d.left < d.right) {
		    nxt.push_back(d);
		}
	    }
	    sort(nxt.begin(), nxt.end(), byValue);
	    int cnt = 0;
	    LL ans = -1;
	    EACH (e, nxt) {
		cnt += e->length();
		if (cnt >= x) {ans = e->value; break; }
	    }
	    printf("%lld\n", ans);
	} else if (op == 4) {
	    nxt.clear();
	    EACH (e, cur) {
		Data d;
		d = Data(max(e->left, l), min(e->right, r), e->value);
		if (d.left < d.right) {
		    nxt.push_back(d);
		}
	    }

	    LL ans = 0;
	    EACH (e, nxt) {
		ans += powMod(e->value, x, y) * e->length();
		ans %= y;
	    }
	    ans %= y;
	    printf("%lld\n", ans);
	} 

	sum += cur.size();
#ifdef LOCAL
	int len = 0;
	REP (i, cur.size()) {
	    len += cur[i].length();
	    if (i) assert(cur[i-1].right == cur[i].left);
	}
	assert(len == N);
#endif
//	eprintf("len %d\n", (int)cur.size());
//	EACH (e, cur) eprintf("(%d %d %lld) ", e->left, e->right, e->value);
//	eprintf("\n");
    }

#ifdef LOCAL
    eprintf("sum %d\n", sum);
#endif
}

void MAIN() {
    scanf("%d%d%lld%lld", &N, &M, &seed, &vmax);
    calc();
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}