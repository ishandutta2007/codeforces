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

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) begin(C), end(C)

#define debug(x) cerr << #x" = " << x << '\n';

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

const double EPS = 1e-9;
const int MAXN = 1e5 + 5;
const ll INF = 1e18 + 1;

struct Node {
	map <char, Node*> next;
	Node* link;
	int len;

	static void* operator new(size_t sz);
};

Node pool[3 * MAXN];
int ptr_ = 0;

static void* Node::operator new(size_t sz) {
	return pool + ptr_++;
}

int get_id(Node* v) {
	return v - pool;
}

Node* root;

void add(char c, Node*& last) {
	Node* cur = new Node();
	cur->len = last->len + 1;

	Node* p = last;
	last = cur;
	for (; p && !p->next.count(c); p = p->link) {
		p->next[c] = cur;
	}

	if  (!p) {
		cur->link = root;
		return;
	}

	Node* q = p->next[c];
	if  (q->len == p->len + 1) {
		cur->link = q;
		return;
	}

	Node* clone = new Node();
	clone->next = q->next;
	clone->link = q->link;
	clone->len = p->len + 1;
	for (; p && p->next.count(c) && p->next[c] == q; p = p->link) {
		p->next[c] = clone;
	}
	q->link = clone;
	cur->link = clone;
}

void build(char* t, int len) {
	root = new Node();

	Node* last = root;
	forn(i, len) {
		add(t[i], last);
	}
}

void output(Node* v, string s) {
	cout << s << endl;
	for (const auto& it : v->next) {
		char c = it.f;
		Node* to = it.s;

		output(to, s + c);
	}
}

ll dp[3 * MAXN];

ll calc(Node* v, char c) {
	ll& res = dp[get_id(v)];

	if  (res != -1ll) {
		return res;
	}

	if  (!v->next.count(c)) {
		return res = 0;
	}

	res = INF;
	for (const auto& it : v->next) {
		Node* to = it.s;
		res = min(res, 1 + calc(to, c));
	}

	return res;
}        

ll calc(char c1, char c2) {
	if  (!root->next.count(c1)) {
		return INF;
	}

	return 1 + calc(root->next[c1], c2);
}

ll dist[5][5];

ll min_path[5][5][80];

ll MinPath(ll cnt_v) {
	forn(a, 4) forn(b, 4) min_path[a][b][0] = dist[a][b];
	for (int k = 1; k < 64; ++k) {
		forn(a, 4) forn(b, 4) {
			min_path[a][b][k] = INF;
			forn(c, 4) {
				min_path[a][b][k] = min(min_path[a][b][k], min_path[a][c][k - 1] + min_path[c][b][k - 1]);
			}
		}
	}

	ll path[4][4];
	forn(a, 4) forn(b, 4) path[a][b] = 0;

	forn(k, 64) {
		if  ((cnt_v >> k) & 1) {
			ll new_path[4][4];
			forn(a, 4) forn(b, 4) {
				new_path[a][b] = INF;
				forn(c, 4)
					new_path[a][b] = min(new_path[a][b], path[a][c] + min_path[c][b][k]);
			}

			forn(a, 4) forn(b, 4) path[a][b] = new_path[a][b];
		}
	}

	ll mn = INF;
	forn(a, 4) forn(b, 4) mn = min(mn, path[a][b]);

	return mn;	
}

ll n;
char t[MAXN];
int m;

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	scanf("%I64d\n", &n);
	gets(t);
	m = strlen(t);

	build(t, m);

//	output(root, "");

	forn(a, 4) forn(b, 4) {
		memset (dp, -1, sizeof dp);
		dist[a][b] = calc('A' + a, 'A' + b);
//		printf("dist[%c][%c] = %I64d\n", 'A' + a, 'A' + b, dist[a][b]);
	}

	// len < n, cnt_v -> max
	// cnt_v: 1 1 1 1 0 0 0 0
	ll L = 0;
	ll R = n + 1;
	while (L != R - 1) {
		ll M = (L + R) >> 1;
		if  (MinPath(M) < n) {
			L = M;
		} else {
			R = M;
		}
	}

	cout << L + 1 << endl;
	return 0;
}