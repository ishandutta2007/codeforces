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

using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair 
#define SZ(C) ((int) (C).size())
#define FORN(i, n) for (int i = 0; i < (int) n; ++i)
#define FORD(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define ALL(C) begin(C), end(C)

#define DEBUG(x) cerr << #x" = " << x << '\n';

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef vector <vector<pii> > vvii;

const double EPS = 1e-9;
const int MOD = int(1e9 + 7);
const int MAX_M = 20 + 2;
const int MAX_LEN = 200 + 2;
const int MAX_K = 500 + 2;

void add( int& x, int y ) {
	if  ((x += y) >= MOD) {
		x -= MOD;
	}
}

struct vertex {
	vertex* next[MAX_M];
	vertex* link;
	vertex* jump[MAX_M];
	int sum_w;
	int dp[2][2][MAX_LEN][MAX_K]; // dp[less or equal][leading zeros][have chars][have sum]

	vertex() {
		memset (dp, -1, sizeof dp);
	}

	int calc_dp( bool eq, bool zeros, int len, int sum );

	int get_id();

	static void* operator new( size_t size );	
};

vertex _VERTEX_POOL[MAX_LEN + 5];
vertex* _PTR;
vertex* root;
int m, k;
vi R;

static void* vertex::operator new( size_t size ) {
	return _PTR++;
}	

int vertex::get_id() {
	return this - _VERTEX_POOL;
}

void init() {
	_PTR = _VERTEX_POOL;
	root = new vertex();
}

int vertex::calc_dp( bool eq, bool zeros, int len, int sum ) {
	if  (sum > k) {
		return 0;
	}

	if  (len == SZ(R)) {
		return 1;
	}

	int& ans = dp[eq][zeros][len][sum];

	if  (ans != -1) {
		return ans;
	}	

	ans = 0;

	for (int c = 0; c <= (eq ? R[len] : (m - 1)); ++c) {
		bool neq = eq && c == R[len];
		bool nzeros = zeros && c == 0; 
		vertex* to = nzeros ? root : jump[c];
		int nsum = sum + to->sum_w;

		add(ans, to->calc_dp(neq, nzeros, len + 1, nsum));
	}

	return ans;
}

void clear_dp( vertex* v ) {
	if  (!v) {
		return;
	}

	memset (v->dp, -1, sizeof v->dp);

	FORN(c, m) {
		clear_dp(v->next[c]);				
	}
}

void clear_dp() {
	clear_dp(root);
}

void add_string( vi& s, int w ) {
	vertex* v = root;
	int pos = 0;

	do {
		int c = s[pos];
		if  (!v->next[c]) {
			v->next[c] = new vertex();
		}
		v = v->next[c];
		++pos;
	} while (pos < SZ(s));

	v->sum_w += w;
}

void build_links() {
	queue <vertex*> q;
	q.push(root);

	root->link = nullptr;
	FORN(c, m) {
		root->jump[c] = root;
	}

	// links
	while (!q.empty()) {
		vertex* v = q.front();
		q.pop();

		FORN(c, m) {
			vertex* to = v->next[c];

			if  (!to) {
				continue;
			}

			vertex* u = v->link;
			while (u && !u->next[c]) u = u->link;

			to->link = u ? u->next[c] : root;

			q.push(to);
		}
	}

	// jumps (and sum_w through link)
	q.push(root);
	while (!q.empty()) {
		vertex* v = q.front();
		q.pop();

		if  (v->link) {
			v->sum_w += v->link->sum_w;
		}

		FORN(c, m) {
			v->jump[c] = v->next[c] ? v->next[c] : (v->link ? v->link->jump[c] : root);

			if  (v->next[c]) {
				q.push(v->next[c]);
			}
		}
	}
}

int solve( vi r ) {
	R = r;

	clear_dp();

	return root->calc_dp(true, true, 0, 0);
}

void read_vec( vi& a ) {
	int len;
	scanf("%d", &len);

	a.resize(len);
	FORN(i, SZ(a)) {
		scanf("%d", &a[i]);
	}
}

int main() {
	init();

	int n;
	scanf("%d%d%d", &n, &m, &k);
	                           
	vi l;
	read_vec(l);

	FORD(i, SZ(l)) {
		if  (l[i]) {
			--l[i];
			for (int j = i + 1; j < SZ(l); ++j) {
				l[j] = m - 1;
			}
			break;
		}
	}

	reverse(ALL(l));
	while (SZ(l) > 1 && !l.back()) l.pop_back();
	reverse(ALL(l));

	vi r;
	read_vec(r);

	while (n --> 0) {
		vi s;
		read_vec(s);
		int w;
		scanf("%d", &w);

		add_string(s, w);
	}
	                   
	build_links();
   	 
	int ans = solve(r); 
	add(ans, -solve(l) + MOD);

	printf("%d\n", ans);
	return 0;
}