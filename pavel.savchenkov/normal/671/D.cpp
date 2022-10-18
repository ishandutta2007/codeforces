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


const int MAXN = 3e5 + 10;

struct query {
	int up;
	int cost;
};

vi g[MAXN];
int n, m;
vector<query> qs[MAXN];
int depth[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return false;
	}
	forn(i, n) {
		g[i].clear();
		qs[i].clear();
	}
	forn(i, n - 1) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x;
		--y;
		g[x].pb(y);
		g[y].pb(x);
	}
	forn(i, m) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		--u;
		--v;
		if  (v == u) {
			continue;
		}
		qs[u].pb(query{ v, c });
	}
	return true;
}

const ll INF = 1e18;

struct Set {
	set<pair<int, ll>> s;
	ll add;

	Set() : add(0) {}

	void insert(pair<int, ll> p) {
		p.snd -= add;
		
		auto it = s.lower_bound(p);
		if  (it != s.end() && it->snd <= p.snd) {
			return;
		}
		vector<pair<int, ll>> to_erase;
		if  (it->fst == p.fst) {
			to_erase.pb(*it);
		}

		while (it != s.begin()) {
			--it;
			if  (it->snd >= p.snd) {
				to_erase.pb(*it);
			} else {
				break;
			}
		}

		for (auto tmp : to_erase) {
			s.erase(tmp);
		}

		s.insert(p);
	}

	void remove_deep(int min_depth) {
		while (!s.empty() && s.begin()->fst < min_depth) {
			s.erase(s.begin());
		}
	}

	ll get_min() const {
		return empty() ? INF : s.begin()->snd + add;
	}

	bool empty() const {
		return s.empty();
	}

	void print() const {
		printf("add = %lld\n", add);
		for (auto p : s) {
			printf("(depth=%d, cost=%lld)\n", p.fst, p.snd + add);
		}
	}
};

void merge(Set*& s1, Set*& s2) {
	auto min1 = s1->get_min();
	auto min2 = s2->get_min();
	s1->add += min2;
	s2->add += min1;
	for (auto p : s2->s) {
		p.snd += s2->add;
		s1->insert(p);
	}
}

void dfs0(int v, int p) {
	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		depth[to] = depth[v] - 1;
		dfs0(to, v);
	}
}

Set* merge_sons(vector<Set*>& sons) {
	if  (sons.empty()) {
		return new Set();
	}

	swap(sons[0], *max_element(all(sons), [](Set* s1, Set* s2) { return s1->s.size() < s2->s.size(); }));

	for (int i = 1; i < sz(sons); ++i) {
		merge(sons[0], sons[i]);
	}

	return sons[0];
}

Set* dfs(int v, int p) {
	vector<Set*> sets;
	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		auto* cur = dfs(to, v);
		cur->remove_deep(depth[v]);
		if  (cur->empty()) {
			return cur;
		}
		sets.pb(cur);
	} 

	Set* sons = merge_sons(sets);

	auto mn = sons->get_min();
	if  (mn >= INF) mn = 0;
	for (auto q : qs[v]) {
		pair<int, ll> path(depth[q.up], q.cost);
		path.snd += mn;
		sons->insert(path);
	}

	// printf("in %d\n", v+1);
	// sons->print();
	// printf("\n");

	return sons;
}

ll solve() {
	if  (n == 1) {
		return 0;
	}
	
	const int root = 0;
	depth[root] = 0;
	dfs0(root, -1);

	Set* s = dfs(root, -1);
	if  (s->empty()) {
		return -1;
	}
	return s->get_min();
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%lld\n", solve());
	}

	return 0;
}