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

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define foran(i, a, n) for (int i = int(a); i < int(n); i++)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgk
#define right yytrwtretywretwreytwreytwr
#define all(A) A.begin(), A.end()

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;

const double EPS = 1e-9;
const int MAXN = int(1e5) + 10;

struct query {
	int l, r, cnt, id;

   	query() {}

   	query( int l, int r, int cnt, int id ) : l(l), r(r), cnt(cnt), id(id) {}
};

vi g[MAXN];
int tin[MAXN];
int tout[MAXN];
int c[MAXN];
int n, m;
int timer;

int color[MAXN];
int cnt_color[MAXN]; // cnt_color[i] - how many vertices with color i
int cnt[MAXN]; // cnt[i] - how many colors with amount i
int suff[MAXN]; // suff[i] = cnt[i] + cnt[i + 1] + ...

int sqrtN;
vector <query> queries;

bool in_seg[MAXN];
int answer[MAXN];

bool cmp_queries( const query & a, const query & b ) {
	if  (a.l / sqrtN != b.l / sqrtN)
		return a.l / sqrtN < b.l / sqrtN;

	return a.r < b.r;
}

void dfs( int v, int p = -1 ) {
	tin[v] = timer++;
	color[tin[v]] = c[v];

	forn(i, sz(g[v])) {
		int to = g[v][i];

		if  (to != p) {
			dfs(to, v);
		}
	}

	tout[v] = timer;
}

void read() {
	scanf("%d%d", &n, &m);

	forn(i, n) {
		scanf("%d", &c[i]);
	}

	forn(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;

		g[a].pb(b);
		g[b].pb(a);
	}

	sqrtN = 1;
	while (sqr(sqrtN) < n) sqrtN++;
}

void precalc() { 
	timer = 0;
	dfs(0);
	         
	forn(i, m) {
		int v, k;
		scanf("%d%d", &v, &k);
		v--;
		   
		queries.pb(query(tin[v], tout[v] - 1, k, i));
	}
}

void add( int pos ) {
	if  (in_seg[pos]) {
		return;
	}
	in_seg[pos] = true;

	int col = color[pos];

	int old_cnt = cnt_color[col]++;
	cnt[old_cnt]--;
	cnt[old_cnt + 1]++;
   	suff[old_cnt + 1]++;
}

void del( int pos ) {
	if  (!in_seg[pos]) {
		return;
	}
	in_seg[pos] = false;

	int col = color[pos];

	int old_cnt = cnt_color[col]--;
	cnt[old_cnt]--;
	assert(old_cnt >= 1);
	cnt[old_cnt - 1]++;
	suff[old_cnt]--;
}

void work_point( int pos, int oldL, int oldR, int newL, int newR ) {
	int oldIn = oldL <= pos && pos <= oldR;
	int newIn = newL <= pos && pos <= newR;

	if  (oldIn && !newIn) {
		del(pos);
	}

	if  (!oldIn && newIn) {
		add(pos);
	}
}

void solve() {
	sort(all(queries), cmp_queries);
	                          
	memset (cnt_color, 0, sizeof cnt_color);
	memset (cnt, 0, sizeof cnt);
	memset (suff, 0, sizeof suff);
	memset (in_seg, false, sizeof in_seg);
	                   
	int L = 0;
	int R = -1;
	forn(i, sz(queries)) {
		int l = queries[i].l;
		int r = queries[i].r;
		int id = queries[i].id;
		int k = queries[i].cnt;

		for (int j = L; j != l; j > l ? j-- : j++)
			work_point(j, L, R, l, r);
		work_point(l, L, R, l, r);

		for (int j = R; j != r; j > r ? j-- : j++)
			work_point(j, L, R, l, r);
		work_point(r, L, R, l, r);

	    L = l;
	    R = r;
	     
		answer[id] = suff[k];
	}	
}

void output() {
	forn(i, m)
		printf("%d\n", answer[i]);
}

int main() {	
	read();
		      
	precalc(); 

	solve();  

	output();

	return 0;
}