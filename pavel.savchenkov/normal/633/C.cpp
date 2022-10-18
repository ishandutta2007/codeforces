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

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const int A = 26;
const int MAXN = 1e4 + 10;

struct Node {
	Node* to[A];
	int who;

	Node() {
		who = -1;
		memset (to, 0, sizeof to);
	}

	void* operator new(size_t);
};

Node pool[(int) 1e6 + 10];
int ptr = 0;

void* Node::operator new(size_t) {
	pool[ptr] = Node();
	return pool + ptr++;
}

void add(Node* t, char* s, int id) {
	// printf("add %s\n", s);
	for (int i = 0; s[i]; ++i) {
		int c = tolower(s[i]) - 'a';
		if  (!t->to[c]) {
			t->to[c] = new Node();
		}
		t = t->to[c];
	}
	t->who = id;
}

Node* root;

int n, m;
char s[MAXN];
int dp[MAXN];
int nxt[MAXN];
vector<string> inputs;

bool read() {
	if  (scanf("%d\n", &n) < 1) {
		return false;
	}
	gets(s);
	root = new Node();
	scanf("%d\n", &m);
	forn(i, m) {
		static char buf[MAXN];
		gets(buf);
		reverse(buf, buf + strlen(buf));
		inputs.pb(string(buf));
		add(root, buf, i);
	}
	return true;
}

void solve() {
	dp[n] = 1;
	ford(i, n) {
		dp[i] = 0;
		nxt[i] = -1;
		Node* v = root;
		for (int j = i; j < n; ++j) {
			int c = s[j] - 'a';
			v = v->to[c];
			if  (!v) {
				break;
			}
			if  (v->who != -1 && dp[j + 1]) {
				nxt[i] = j + 1;
				dp[i] = 1;
				break;
			}
		}
	}

	assert(nxt[0] != -1);

	vector<string> res;	
	int i = 0;
	while (i < n) {
		Node* v = root;
		for (int j = i; j < nxt[i]; ++j) {
			int c = s[j] - 'a';
			v = v->to[c];
		}
		int id = v->who;
		assert(id != -1);
		res.pb(inputs[id]);
		i = nxt[i];
	}

	for (string t : res) {
		reverse(all(t));
		printf("%s ", t.c_str());
	}
	puts("");
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
		break;
	}

	return 0;
}