#include<cassert>
#include<stack>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

struct PMA {
    struct Node {
	// *ch : head of its children
	// *l : little sister
	// *r : big sister
	// *fail : failure link
	Node *ch, *l, *r, *fail;
	char c;
	LL cnt;
        Node() : ch(0), l(0), r(0), fail(0), c(0), cnt(0) { }
    };

    Node *root, *nodes;
    int nodes_i;

    PMA() { }

    PMA(const vector<string> &d, const vector<int> &g) {
	int len = 0;
	REP (i, d.size()) len += d[i].size();
	len++;
	nodes_i = 0;
	nodes = new Node[len];
	root = new_node();

	// Trie
	VI idx(d.size());
	REP (i, d.size()) idx[i] = i;
	random_shuffle(idx.begin(), idx.end());

	REP (i_, d.size()) {
	    int i = idx[i_];
	    Node *x = root;
	    const string &s = d[i];
	    REP (j, s.size()) x = get_child(x, s[j], true);
	    x->cnt += g[i];
	}

	// failure link, bfs
	vector<Node*> ord; ord.reserve(nodes_i);
	ord.push_back(root);
	for (int i=0; i<nodes_i; i++) {
	    Node *x = ord[i];
	    if (x->ch) {
		int j = ord.size();
		ord.push_back(x->ch);
		for (; j<(int)ord.size(); j++) {
		    if (ord[j]->l) ord.push_back(ord[j]->l);
		    if (ord[j]->r) ord.push_back(ord[j]->r);
		}
	    }
	}

	root->fail = root; // ord[0]
	stack<Node*> S;
	if (root->ch) S.push(root->ch);
	while (!S.empty()) {
	    Node *ch = S.top(); S.pop();
	    if (ch->l) S.push(ch->l);
	    if (ch->r) S.push(ch->r);
	    ch->fail = root;
	}

	for (int i=1; i<nodes_i; i++) {
	    Node *x = ord[i];
	    if (x->ch) S.push(x->ch);
	    while (!S.empty()) {
		Node *ch = S.top(); S.pop();
		if (ch->l) S.push(ch->l);
		if (ch->r) S.push(ch->r);
		Node *f = x->fail, *y;
		while (!(y=get_child(f, ch->c)) && f != root) f = f->fail;
		ch->fail = y ?: root;
	    }
	}

	// accumulate
	REP (i, nodes_i) ord[i]->cnt += ord[i]->fail->cnt;
    }

    Node *new_node(char c=0) {
	nodes[nodes_i].c = c;
	return &nodes[nodes_i++];
    }

    Node *get_child(Node *x, char c, bool create=false) { // assert(x != NULL);
	if (!x->ch) {
	    if (create) x->ch = new_node(c);
	    return x->ch;
	} else {
	    Node *ch = x->ch;
	    while (ch) {
		if (c < ch->c) {
		    if (create && !ch->l) ch->l = new_node(c);
		    ch = ch->l;
		} else if (ch->c < c) {
		    if (create && !ch->r) ch->r = new_node(c);
		    ch = ch->r;
		} else {
		    return ch;
		}
	    }
	    return NULL;
	}
    }

    // Aho Corasick
    LL match(const string &s) {
	Node *x = root;
	LL ret = 0;
	REP (i, s.size()) {
	    Node *y = NULL;
	    while (!(y=get_child(x, s[i])) && x != root) x = x->fail;
	    x = y ?: root;
	    ret += x->cnt;
	}
	return ret;
    }

    void clear() {
	delete[] nodes;
	root = nodes = NULL;
	nodes_i = 0;
    }
};


int N;
PMA Z[30];
char op[99], buf[300111];
vector<string> D[30];
VI G[30];

void add(const string &s, int x) {
    vector<string> cur_d(1, s);
    VI cur_g(1, x);
    REP (i, 20) {
	if (D[i].empty()) {
	    D[i] = cur_d;
	    G[i] = cur_g;
	    Z[i] = PMA(D[i], G[i]);
	    break;
	} else {
	    cur_d.insert(cur_d.end(), D[i].begin(), D[i].end());
	    cur_g.insert(cur_g.end(), G[i].begin(), G[i].end());
	    D[i].clear();
	    G[i].clear();
	    Z[i].clear();
	}
    }
}
LL query(const string &s) {
    LL ret = 0;
    REP (i, 20) {
	if (!D[i].empty()) {
	    ret += Z[i].match(s);
	}
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    REP ($, N) {
	scanf("%s%s", op, buf);
	if (op[0] == '1') {
	    add(buf, 1);
	} else if (op[0] == '2') {
	    add(buf, -1);
	} else {
	    printf("%lld\n", query(buf));
	    fflush(stdout);
	}
    }

    return 0;
}