#include<random>
#include<set>
#include<deque>
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
namespace TreeImpl {
;

mt19937 engine(19480430);

inline int gen_pri() {
    return __builtin_ctz((1<<31) | engine());
}

struct NodeBase;
typedef NodeBase* Pointer;
struct NodeBase {
    Pointer parent, left, right;
    int size;
    int pri;
    NodeBase() {
	parent = left = right = 0;
	size = 1;
	pri = gen_pri();
    }
};

template<class T> struct NodeBaseT : NodeBase {
    T val;
    NodeBaseT(const T &val_=T()) : NodeBase(), val(val_) {}
};

inline int size(Pointer x) {
    return x? x->size: 0;
}

inline void resize(Pointer x) {
    x->size = 1 + size(x->left) + size(x->right);
}

Pointer merge(Pointer x, Pointer y) {
    if (!x || !y) return x? x: y;
    if (x->pri < y->pri) {
	y->left = merge(x, y->left);
	y->left->parent = y;
	resize(y);
	return y;
    } else {
	x->right = merge(x->right, y);
	x->right->parent = x;
	resize(x);
	return x;
    }
}

pair<Pointer, Pointer> split(Pointer x, int k) {
    if (!x) return pair<Pointer, Pointer>(0, 0);
    x->parent = 0;
    if (k == 0) return pair<Pointer, Pointer>(0, x);
    if (size(x) == k) return pair<Pointer, Pointer>(x, 0);
    if (k <= size(x->left)) {
	pair<Pointer, Pointer> p = split(x->left, k);
	if ((x->left = p.second)) x->left->parent = x;
	resize(x);
	p.second = x;
	return p;
    } else {
	pair<Pointer, Pointer> p = split(x->right, k - size(x->left) - 1);
	if ((x->right = p.first)) x->right->parent = x;
	resize(x);
	p.first = x;
	return p;
    }
}

Pointer get_kth(Pointer x, int k) {
    while (1) {
	int s = size(x->left);
	if (s == k) return x;
	if (k < s) {
	    x = x->left;
	} else {
	    k -= s + 1;
	    x = x->right;
	}
    }
}

Pointer get_root(Pointer x) {
    while (x->parent) x = x->parent;
    return x;
}

int get_rank(Pointer x) {
    int ret = size(x->left);
    Pointer y = x;
    x = x->parent;
    while (x) {
	if (y == x->right) ret += size(x->left) + 1;
	y = x;
	x = x->parent;
    }
    return ret;
}

Pointer get_next(Pointer x) {
    if (x->right) {
	x = x->right;
	while (x->left) x = x->left;
    } else {
	Pointer y = 0;
	while (x && x->right == y) {
	    y = x;
	    x = x->parent;
	}
    }
    return x;
}

Pointer get_prev(Pointer x) {
    if (x->left) {
	x = x->left;
	while (x->right) x = x->right;
    } else {
	Pointer y = 0;
	while (x && x->left == y) {
	    y = x;
	    x = x->parent;
	}
    }
    return x;
}

Pointer get_front(Pointer x) {
    while (x->left) x = x->left;
    return x;
}

Pointer get_back(Pointer x) {
    while (x->right) x = x->right;
    return x;
}

template<class Tree> inline int size(Tree x) { return size((Pointer)x); }
template<class Tree> Tree merge(Tree x, Tree y) { return (Tree)merge((Pointer)x, (Pointer)y); }
template<class Tree> pair<Tree, Tree> split(Tree x, int k) { 
    pair<Pointer, Pointer> p = split((Pointer)x, k);
    return make_pair((Tree)p.first, (Tree)p.second);
}
template<class Tree> Tree get_kth(Tree x, int k) { return (Tree)get_kth((Pointer)x, k); }
template<class Tree> Tree get_root(Tree node) { return (Tree)get_root((Pointer)node); }
template<class Tree> int get_rank(Tree node) { return get_rank((Pointer)node); }
template<class Tree> Tree get_next(Tree node) { return (Tree)get_next((Pointer)node); }
template<class Tree> Tree get_prev(Tree node) { return (Tree)get_prev((Pointer)node); }
template<class Tree> Tree get_front(Tree x) { return (Tree)get_front((Pointer)x); }
template<class Tree> Tree get_back(Tree x) { return (Tree)get_back((Pointer)x); }
}; // namespace TreeImpl;


int N, K;
int B[10];

struct Data {
    int cnt;
    int low[10], high[10];
    Data(){}
};

using namespace TreeImpl;
NodeBaseT<Data> nodes[50011];
typedef NodeBaseT<Data>* Tree;


Tree low_search(Tree x) {
    if (!x) return 0;
    bool win = false;
    REP (k, K) if (B[k] > x->val.low[k]) {
	win = true;
	break;
    }
    if (!win) return low_search((Tree) x->right);
    else {
	Tree y = low_search((Tree) x->left);
	return y? y: x;
    }
}
Tree high_search(Tree x) {
    if (!x) return 0;
    bool lose = false;
    REP (k, K) if (B[k] < x->val.high[k]) {
	lose = true;
	break;
    }
    if (!lose) return high_search((Tree) x->left);
    else {
	Tree y = high_search((Tree) x->right);
	return y? y: x;
    }
}

void MAIN() {
    scanf("%d%d", &N, &K);

    REP (k, K) scanf("%d", B+k);
    Data &d = nodes[0].val;
    REP (k, K) d.low[k] = d.high[k] = B[k];
    d.cnt = 1;
    Tree root = &nodes[0];
    puts("1");
    
    REP (_, N-1) {
	REP (k, K) scanf("%d", B+k);

	Tree win_node = low_search(root);
	Tree lose_node = high_search(root);

	int lose_rank = (lose_node? get_rank(lose_node): -1);
	int win_rank = (win_node? get_rank(win_node): size(root));

	if (win_node == lose_node) {
	    Data &d = win_node->val;
	    d.cnt++;
	    REP (k, K) {
		amin(d.low[k], B[k]);
		amax(d.high[k], B[k]);
	    }
	} else if (lose_rank < win_rank) {
	    Data &d = nodes[_+1].val;
	    d.cnt = 1;
	    REP (k, K) d.low[k] = d.high[k] = B[k];
	    pair<Tree, Tree> p = split(root, win_rank);
	    root = merge(p.first, merge(&nodes[_+1], p.second));
	} else {
	    Tree x = (win_node? get_next(win_node): get_front(root));
	    while (1) {
		win_node->val.cnt += x->val.cnt;
		if (!x || x == lose_node) break;
		x = get_next(x);
	    }

	    win_node->val.cnt++;
	    REP (k, K) {
		amin(win_node->val.low[k], x->val.low[k]);
		amin(win_node->val.low[k], B[k]);
		amax(win_node->val.high[k], B[k]);
	    }

	    pair<Tree, Tree> p = split(root, lose_rank+1);
	    pair<Tree, Tree> q = split(p.first, win_rank+1);
	    root = merge(q.first, p.second);
	}

	printf("%d\n", get_front(root)->val.cnt);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}