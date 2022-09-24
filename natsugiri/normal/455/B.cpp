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

// Trie LCRS implementation
struct Trie {
    typedef int T;
    struct Node {
	int game, misere;
	char c;
	Node *ch, *sib;
	Node() : game(0), misere(0), c(0), ch(0), sib(0) {}
    };
    Node *root;
    Trie() {
	root = new_node();
    }
//    Trie(const vector<string> &d, T v=1) : Trie() {
//	REP (i, d.size()) add(d[i], v);
//    }
    Node *new_node(char c=0) {
	Node *r = new Node();
	r->c = c;
	return r;
    }
    void add(const string &s) {
	Node *x = root;
//	x->val += v;
	REP (i, s.size()) {
	    if (x->ch) {
		x = x->ch;
		while (x->c != s[i]) {
		    if (!x->sib) x->sib = new_node(s[i]);
		    x = x->sib;
		}
	    } else {
		x->ch = new_node(s[i]);
		x = x->ch;
	    }
//	    x->val += v;
	}
    }

    Node* calc() {
	vector<Node*> ord;
	ord.push_back(root);
	for (int i=0; i<(int)ord.size(); i++) {
	    Node *x = ord[i];
	    if (x->ch) ord.push_back(x->ch);
	    if (x->sib) ord.push_back(x->sib);
	}
	for (int i=ord.size(); i--;) {
	    Node *x = ord[i];
	    Node *c = x->ch;
	    if (c == NULL) x->misere = 1;
	    while (c) {
		if (c->game == 0) x->game = 1;
		if (c->misere == 0) x->misere = 1;
		c = c->sib;
	    }
	}
	return root;
    }

    Node *find(const string &s) {
	Node *x = root;
	REP (i, s.size()) {
	    if (!x->ch) return NULL;
	    x = x->ch;
	    while (x->c != s[i]) {
		if (!x->sib) return NULL;
		x = x->sib;
	    }
	}
    }
};

int N, K;
char buf[100111];

int main() {
    scanf("%d%d", &N, &K);
    Trie X;
    REP (i, N) {
	scanf("%s", buf);
	X.add(buf);
    }

    Trie::Node *x = X.calc();
    bool yes ;
    if (x->game && x->misere) yes = true;
    else if (x->game && !x->misere) yes = K & 1;
    else yes = false;

    puts(yes? "First": "Second");
//    eprintf("%d %d\n", x->game, x->misere);
    return 0;
}