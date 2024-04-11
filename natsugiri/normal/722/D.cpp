#include<set>
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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

struct BinaryTrie {
    typedef unsigned U; // key
    static const int BITS = sizeof (U) * 8;

//    typedef unsigned long long U;
//    static const int BITS = sizeof (U) * 8;

    typedef int T; // type of value.

    struct Node {
	int l, r; // Children nodes. If this is a leaf, l is prev, and r is next.
	T val; // Sum of children.
	U u;

	Node() : l(0), r(0), val(0), u(0) {
	}

	inline const int& ch(bool R) const { return R? r: l; }

	inline int& ch(bool R) { return R? r: l; }
    };

    static int stk[BITS+1];

    inline bool has(int x) const {
	return x && D[x].val != 0;
    }

    vector<Node> D; // D[0] is header, not a node. D[1] is root.

    BinaryTrie() : D(2, Node()) {
    }

    void add(const U u, const T v) {
	int x = stk[BITS] = 1; // root
	for (int i=BITS; i--; ) {
	    D[x].u = u;
	    D[x].val += v;
	    bool R = u & (1u << i);
	    if (D[x].ch(R) == 0) {
		D[x].ch(R) = D.size();
		D.push_back(Node());
	    }
	    x = D[x].ch(R);
	    stk[i] = x;
	}

	bool pre_zero = (D[x].val == 0);
	D[x].u = u;
	D[x].val += v;
	bool cur_zero = (D[x].val == 0);

	if (pre_zero && !cur_zero) { // Created
	    int y = 0; // Find next node of x.
	    for (int i=0; i<BITS; i++) {
		y = stk[i+1];
		if ((~u & (1u << i)) && has(D[y].r)) {
		    y = D[y].r;
		    for (; i--; ) y = (has(D[y].l)? D[y].l: D[y].r);
		    break;
		}
	    }
	    if (y == 1) y = 0; // If x is maximum node: y be header.
	    D[x].l = D[y].l; D[x].r = y;
	    D[D[y].l].r = D[y].l = x;
	} else if (!pre_zero && cur_zero) { // Erased
	    D[D[x].l].r = D[x].r;
	    D[D[x].r].l = D[x].l;
	}
    }

    int get_node(U u) const {
	int x = 1; // root
	for (int i=BITS; i--; ) {
	    bool R = u & (1u << i);
	    if (D[x].ch(R) == 0) return 0; // Not found. Returns header.
	    x = D[x].ch(R);
	}
	return x;
    }

    int get_val(U u) const {
	int x = get_node(u);
	if (x == 0) return T(0); // initial value
	else return D[x].val;
    }

    T size() const { return D[1].val; } // Useful when add(u, 1) and add(u, -1).

    // x must be a leaf. Nodes whose val==0 are skiped. When D[x].val == 0, Returns undefined.
    // If leaf value be negative, next/prev be broken.
    inline int next_node(int x) const { return D[x].r; }

    inline int prev_node(int x) const { return D[x].l; }

    inline int min_node() const { return D[0].r; }

    inline int max_node() const { return D[0].l; }

    // Returns a node.
    int lower_bound(U u) const {
	int x = 1;
	for (int i=BITS; i--; ) {
	    bool R = u & (1u << i);
	    if (has(D[x].ch(R))) {
		x = D[x].ch(R);
	    } else {
		x = D[x].ch(!R);
		for (; i--; ) x = (has(D[x].ch(R))? D[x].ch(R): D[x].ch(!R));
		if (!R) x = next_node(x);
		break;
	    }
	} // If non-break ends loop, x be u's node.
	return x;
    }

    // Returns a node more than u.
    int more_than(U u) const {
	int x = lower_bound(u);
	if (x == 0) return 0; // No higher than u.
	if (D[x].u == u) return next_node(x); // x is exactly u's node.
	return x;
    }

    // Returns a node less than u
    int less_than(U u) const {
	int x = lower_bound(u);
	return prev_node(x); // If x is header: returns max node
    }

    vector<U> get_vector() const {
	vector<U> ret;
	get_vector_rec(1, 0, ret);
	return ret;
    }

    void get_vector_rec(int x, int d, vector<U> &v) const {
	if (has(x)) {
	    if (d == BITS) v.push_back(D[d].u);
	    else get_vector_rec(D[x].l, d+1, v), get_vector_rec(D[x].r, d+1, v);
	}
    }

    U max_xor_key(U u) const {
	int x = 1;
	for (int i=BITS; i--; ) {
	    bool R = u & (1u << i);
	    x = (has(D[x].ch(!R))? D[x].ch(!R): D[x].ch(R));
	}
	return D[x].u;
    }
};
int BinaryTrie::stk[];


int N, Y[50111];


int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", Y+i);

    BinaryTrie B;
    REP (i, N) B.add(Y[i], 1);

    while (true) {
	unsigned tmp = B.D[B.max_node()].u;
	unsigned bak = tmp;
	while (tmp) {
	    tmp >>= 1;
	    if (B.get_val(tmp) == 0) break;
	}

	if (tmp == 0) break;
	B.add(bak, -1);
	B.add(tmp, 1);
    }

    int x = B.min_node();

    while (x) {
	printf("%u\n", B.D[x].u);
	x = B.next_node(x);
    }

    return 0;
}