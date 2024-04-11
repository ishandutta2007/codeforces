#include<unordered_set>
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

const LL MOD = 998244353;
const int SIZE = 1<<18;
//const int SIZE = 1<<2;

struct Store {
    unordered_set<int> all, any;
    Store() {}
} store[SIZE];

struct Seg {
    LL val;
    int sz;
    Seg() {
	val = 0;
	sz = 0;
    };

    static const Seg unit;
} seg[SIZE*2];
const Seg Seg::unit = Seg();

Seg operator*(const Seg &x, const Seg &y) {
    // TODO: do stuff something
    Seg z;
    z.val = x.val + y.val;
    z.sz = x.sz + y.sz;
    return z;
};

struct Lazy {
    // mul X + add;
    LL mul;
    LL add;
    Lazy() {
	mul = 1;
	add = 0;
    }
//    Lazy(LL val_) : add(val_) {}

    Lazy& operator+=(const Lazy &y) {
	// TODO: do stuff something
	mul = mul * y.mul % MOD;
	add = (add * y.mul + y.add) % MOD;
	return *this;
    }

    static const Lazy unit;
} lazy[SIZE*2];
const Lazy Lazy::unit = Lazy();

Seg operator+(const Seg &x, const Lazy &y) {
    // TODO: do stuff something
    Seg z;
    z.val = (x.val * y.mul + x.sz * y.add) % MOD;
    z.sz = x.sz;
    return z;
}


Seg eval(int k) {
    return seg[k] + lazy[k];
}

void force(int k) {
    if (k < SIZE) {
	if (lazy[k].mul != 1 || lazy[k].add != 0) {
	    lazy[k*2] += lazy[k];
	    lazy[k*2+1] += lazy[k];
	    lazy[k] = Lazy::unit;
	    seg[k] = eval(k*2) * eval(k*2+1);
	}
    } else if (k < SIZE*2) {
	seg[k].val = (seg[k].val * lazy[k].mul + lazy[k].add) % MOD;
	lazy[k] = Lazy::unit;
    }
}

void mul_(int x, int y, int v, int l, int r, int k) {
    if (y <= l || r <= x) {
    } else if (x <= l && r <= y) {
	// force(k);
	lazy[k].mul *= 2;
	lazy[k].add *= 2;
	if (lazy[k].mul >= MOD) lazy[k].mul -= MOD;
	if (lazy[k].add >= MOD) lazy[k].add -= MOD;
    } else {
	force(k);
	mul_(x, y, v, l, (l+r)/2, k*2);
	mul_(x, y, v, (l+r)/2, r, k*2+1);
	seg[k] = eval(k*2) * eval(k*2+1);
    }
}

void add_(int x, int y, int v, int l, int r, int k) {
    if (y <= l || r <= x) {
    } else if (store[v].all.find(k) != store[v].all.end()) {
	mul_(x, y, v, l, r, k);
    } else if (x <= l && r <= y && store[v].any.find(k) == store[v].any.end()) {
	// force(k);
	store[v].all.insert(k);
	store[v].any.insert(k);
	lazy[k].add++;
	if (lazy[k].add >= MOD) lazy[k].add -= MOD;
    } else {
	force(k);
	add_(x, y, v, l, (l+r)/2, k*2);
	add_(x, y, v, (l+r)/2, r, k*2+1);
	seg[k] = eval(k*2) * eval(k*2+1);

	store[v].any.insert(k);
	auto it = store[v].all.find(k*2);
	if (it != store[v].all.end()) {
	    auto it2 = store[v].all.find(k*2+1);
	    if (it2 != store[v].all.end()) {
		store[v].all.erase(it);
		store[v].all.erase(it2);
		store[v].all.insert(k);
	    }
	}
    }
}
void add(int x, int y, int v) {
    add_(x, y, v, 0, SIZE, 1);
}

Seg query_(int x, int y, int l, int r, int k) {
    if (y <= l || r <= x) {
	return Seg::unit;
    } else if (x <= l && r <= y) {
	return eval(k);
    } else {
	force(k);
	return (query_(x, y, l, (l+r)/2, k*2) * query_(x, y, (l+r)/2, r, k*2+1)) + lazy[k];
    }
}

LL query(int x, int y) {
    return query_(x, y, 0, SIZE, 1).val;
}

void build(int n) {
    REP (i, n) seg[SIZE+i].sz = 1;
    for (int i=SIZE; --i;) seg[i] = seg[i*2] * seg[i*2+1];
}

int N, Q;

void MAIN() {
    scanf("%d%d", &N, &Q);
    build(N);

    REP ($, Q) {
	char op[9];
	scanf("%s", op);
	if (*op == '1') {
	    int l, r, x;
	    scanf("%d%d%d", &l, &r, &x);
	    l--;
	    add(l, r, x);
	} else {
	    int l, r;
	    scanf("%d%d", &l, &r);
	    l--;
	    LL ans = query(l, r);
	    printf("%lld\n", ans);
	}

//	eprintf("%s: \n", op);
//	REP (i, SIZE*2) eprintf("(%lld %d)", seg[i].val, seg[i].sz);
//	eprintf("\n");
//	REP (i, SIZE*2) eprintf("(%lld %lld)", lazy[i].mul, lazy[i].add);
//	eprintf("\n");
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}