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

struct BinaryTrie {
    struct Node {
	int ch[2];
	int val;
	Node() : val(0) {
	    ch[0] = ch[1] = 0;
	}
    };
    vector<Node> D; // D[0] is unefined, D[1] is the root.
    BinaryTrie() {
	D.assign(2, Node());
    }
    void add(const string &s, int v) {
	int n = s.size();
	VI t(n+1); // trail
	t[0] = 1;
	REP (i, n) {
	    int b = s[i] - '0';
	    if (!D[t[i]].ch[b]) {
		D[t[i]].ch[b] = D.size();
		D.push_back(Node());
	    }
	    t[i+1] = D[t[i]].ch[b];
	}
	REP (i, n+1) D[t[i]].val += v;
    }
    int get_node(const string &s) {
	int n = s.size();
	VI t(n+1);
	t[0] = 1;
	REP (i, n) {
	    int b = s[i] - '0';
	    if (!D[t[i]].ch[b]) {
		return 0; // NULL
	    }
	    t[i+1] = D[t[i]].ch[b];
	}
	return t[n];
    }

    int query(const string &s) {
	int n = s.size();
	VI t(n+1);
	int ret = 0;
	t[0] = 1;
	REP (i, n) {
	    int b = s[i] - '0';
	    if (D[t[i]].ch[!b] && D[D[t[i]].ch[!b]].val != 0) {
		b = !b;
	    }
	    ret = (ret << 1) | b;
	    t[i+1] = D[t[i]].ch[b];
	}
	return ret;
    }
};


int N;
char op[9];
int x;
char S[55];

int main() {
    scanf("%d", &N);
    BinaryTrie BT;
    REP (i, 30) S[i] = '0';
    BT.add(S, 2 * N);

    REP ($, N) {
	scanf("%s%u", op, &x);
	REP (i, 30) {
	    S[i] = ((x >> (29 - i)) & 1) + '0';
	}
	if (op[0] == '+') {
	    BT.add(S, 1);
	} else if (op[0] == '-') {
	    BT.add(S, -1);
	} else {
	    int y = BT.query(S);
	    printf("%u\n", y ^ x);
	}
    }

    return 0;
}