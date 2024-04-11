#include<map>
#include<deque>
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

VI ansA, ansB;
int ansS;

struct Node {
    VI mark;
    map<char, int> next;
    int d;
    Node() {
	mark.clear();
	next.clear();
//	memset(next, 0, sizeof next);
    }
};

const int node_max = 800010;
Node node[node_max];
int node_i;
void init_trie() {
    node[0] = Node();
    node[0].d = 0;
    node_i = 1;
}
void insert_trie(const string &s, int mark=-1) {
    Node *x = &node[0];
    for (int i=0; i<(int)s.size(); i++) {
	int k = s[i] - 'a';
	if (!x->next.count(k)) {
	    if (node_i == node_max) break;
	    node[node_i] = Node(); 
	    node[node_i].d = i+1;
	    x->next[k] = node_i; //&node[node_i];
	    node_i++;
	}
	x = &node[x->next[k]];
    }
    x->mark.push_back(mark);
}
void find_trie(const string &s, int mark=-1) {
    Node *x = &node[0];
    for (int i=0; i<(int)s.size(); i++) {
	int k = s[i] - 'a';
	if (!x->next[k]) {
	    break;
	}
	x = &node[x->next[k]];
    }
    //x->mark = mark;
    if (x->mark.size() && x->mark.back() < 0) {
	ansA.push_back(-x->mark.back()); x->mark.pop_back();
	ansB.push_back(mark);
	ansS += x->d;
    } else {
	x->mark.push_back(mark);
    }
}
/*
bool find_trie(const string &s) {
    Node *x = &node[0];
    for (int i=0; i<(int)s.size(); i++) {
	int k = s[i] - 'a';
	if (!x->next[k]) return false; // match s[0..i-1]
	x = x->next[k];
    }
    // match x->mark;
    return true;
}
*/


int N;
char buf[800111];
int main() {
//    eprintf("size %d\n", (int) sizeof (Node));
//    eprintf("size %d\n", (int) sizeof node);

    init_trie();
    scanf("%d", &N);
    REP (i, N) {
	scanf("%s", buf);
	insert_trie(buf, -(i+1));
    }
    REP (i, N) {
	scanf("%s", buf);
	find_trie(buf, (i+1));
    }

    for (int i=node_i; i--; ) {
	Node *x = &node[i];
	VI va, vb;
	if (x->mark.size()) {
	    if (x->mark[0] < 0) va = x->mark;
	    else vb = x->mark;
	    x->mark.clear();
	}
	EACH (e, x->next) if (e->second) {
	    VI &q = node[e->second].mark;
	    if (q.size()) {
		if (q[0] < 0) va.insert(va.end(), q.begin(), q.end());
		if (q[0] > 0) vb.insert(vb.end(), q.begin(), q.end());
	    }
	    q.clear();
	}
	{
	    int i=0;
	    for (; i<(int)va.size() && i<(int)vb.size(); i++) {
		ansA.push_back(-va[i]);
		ansB.push_back(vb[i]);
		ansS += x->d;
	    }
	    if ((int)va.size() > i) x->mark = VI(va.begin()+i, va.end());
	    if ((int)vb.size() > i) x->mark = VI(vb.begin()+i, vb.end());
	}
    }

//    eprintf("%d\n", (int)ansA.size());
    printf("%d\n", ansS);
    REP (i, N) printf("%d %d\n", ansA[i], ansB[i]);

    return 0;
}