#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define ws ws_____________________
#define y1 y1_____________________
#define y0 y0_____________________
#define left left_________________
#define right right_______________
#define next next_________________
#define prev prev_________________
#define hash hash_________________

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

const int MAX = 1e6 + 10;

string read_string() {
	static char buf[MAX];
	scanf("%s\n", buf);
	return buf;
}

int n;
vector<string> s;

bool read() {
	if  (scanf("%d\n", &n) < 1) {
		return 0;
	}
	s.resize(n);
	forn(i, n) {
		s[i] = read_string();
	}
	return 1;
}

const int A = 26;

struct Node;
using NodePtr = Node*;

struct Node {
	NodePtr to[A];
	NodePtr go[A];
	NodePtr link;

	NodePtr par;
	int c_par;
	int len;

	Node() {
		memset (to, 0, sizeof to);
		memset (go, 0, sizeof go);
		link = par = 0;
		len = 0;
		c_par = -1;
	}

	void* operator new(size_t);
};

Node pool[MAX * 2];
int ptr_pool;

void* Node::operator new(size_t) {
	pool[ptr_pool] = Node();
	return pool + ptr_pool++;
}

NodePtr root;

NodePtr get_link(NodePtr);
NodePtr get_go(NodePtr, int);

NodePtr get_go(NodePtr v, int c) {
	if  (!v) {
		return root;
	}	

	if  (v->to[c]) {
		return v->to[c];
	}

	if  (v == root) {
		return root;
	}

	if  (v->go[c]) {
		return v->go[c];
	}

	return (v->go[c] = get_go(get_link(v), c));
}

NodePtr get_link(NodePtr v) {
	assert(v);

	if  (v == root) {
		return 0;
	}

	if  (v->link) {
		return v->link;
	}

	return (v->link = get_go(get_link(v->par), v->c_par));
}

void add_string(const string& s, NodePtr& root) {
	NodePtr v = root;
	for (char ch : s) {
		const int c = ch - 'a';
		if  (!v->to[c]) {
			v->to[c] = new Node();
			v->to[c]->par = v;
			v->to[c]->len = v->len + 1;
			v->to[c]->c_par = c;
		}
		v = v->to[c];
	}
}

vi dfs(vvi& g, int v) {
	vi dp(2, 0);
	for (int to : g[v]) {
		vi dp_to = dfs(g, to);

		vi ndp(2);
		ndp[0] = dp[0] + dp_to[0];
		ndp[1] = *max_element(all(dp)) + *max_element(all(dp_to));

		dp.swap(ndp);
	}

	dp = {dp[1], dp[0] + 1};

	// eprintf("v = %d\n", v);
	// eprintf("dp:\n");
	// forn(i, sz(dp)) {
	// 	eprintf("i=%d, dp=%d\n", i, dp[i]);
	// }

	return dp;
}

int solve() {
	ptr_pool = 0;
	root = new Node();

	for (const auto& str : s) {
		add_string(str, root);
	}

	vvi g(ptr_pool);
	vi deg_in(ptr_pool);
	for (int i = 1; i < ptr_pool; ++i) {
		NodePtr v = pool + i;
		NodePtr u = get_link(v);
		assert(u);
		if  (u != root && u->len + 1 == v->len) {
			g[u - pool].pb(v - pool);
			++deg_in[v - pool];
		}
	}

	// eprintf("graph:\n");
	// for (int v = 1; v < ptr_pool; ++v) {
	// 	eprintf("v = %d\n", v);
	// 	for (int to : g[v]) {
	// 		eprintf(" -> %d\n", to);
	// 	}
	// }

	int ans = 0;
	for (int i = 1; i < ptr_pool; ++i) {
		if  (deg_in[i] == 0) {
			vi dp = dfs(g, i);
			ans += *max_element(all(dp));
		}
	}

	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	int T;
	scanf("%d\n", &T);
	forn(t, T) {
		assert(read());
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}