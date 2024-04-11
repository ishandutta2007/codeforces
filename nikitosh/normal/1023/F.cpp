#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define fst first
#define sc second
#define snd second
#define sz(X) (int)(X).size()
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fornr(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forab(i, a, b) for(int i = int(a); i < int(b); i++)
#define all(X) X.begin(), X.end()

typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef vector<int> vi;

const int MAX_N = 5e5 + 10;
const int LOG = 20;
const int INF = 1e9 + 7;

set<pii> edges;
int p[MAX_N], rk[MAX_N], was[MAX_N], tin[MAX_N], tout[MAX_N], up[MAX_N][LOG], euler[MAX_N], left_end[MAX_N], right_end[MAX_N], to_add[MAX_N];
vi g[MAX_N];
bool inf_ans = false;
int curT, curPos;
ll ans = 0;

struct Edge {
	int v, u, w;
	Edge() {}
	bool operator<(const Edge &edge) {
		return w < edge.w;
	}
};

Edge e[MAX_N];

int get(int v) {
	if (p[v] == v)
		return v;
	return p[v] = get(p[v]);
}

void unite(int v, int u) {
	v = get(v);
	u = get(u);
	if (v == u)
		return;
	if (rk[v] >= rk[u])
		swap(v, u);
	p[v] = u;
	if (rk[v] == rk[u])
		rk[u]++;
}

void dfs(int v, int par) {
	if (edges.count(mp(v, par))) to_add[v] = 1;
	left_end[v] = curPos;
	euler[curPos++] = v;
	tin[v] = curT++;
	
	up[v][0] = par;
	forab(i, 1, LOG) {
		up[v][i] = up[up[v][i - 1]][i - 1];
	}
	for (int to : g[v]) {
		if (to == par) continue;
		dfs(to, v);
	}
	right_end[v] = curPos;
	tout[v] = curT++;
}

bool upper(int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int lca(int v, int u) {
	if (upper(v, u)) return v;
	if (upper(u, v)) return u;
	int cur = v;
	fornr(i, LOG) {
		if (!upper(up[cur][i], u)) cur = up[cur][i];	
	}
	return up[cur][0];
}

set<pii> q_bot[MAX_N];
vector<int> q_up[MAX_N];
int tree[4 * MAX_N], tSize = 1;

int get(int v, int vl, int vr, int l, int r) {
	if (r <= vl || vr <= l) return INF;
	if (l <= vl && vr <= r) return tree[v];
	return min(get(2 * v, vl, (vl + vr) / 2, l, r), get(2 * v + 1, (vl + vr) / 2, vr, l, r));
}

void put(int ind, int cost) {
	int v = ind + tSize;
	tree[v] = cost;
	do {
		v /= 2;
		tree[v] = min(tree[2 * v], tree[2 * v + 1]);
	} while (v != 1);
}	

void update(int v) {
	if (!q_bot[v].empty())
		put(left_end[v], q_bot[v].begin()->fst);
	else
		put(left_end[v], INF);
}

void dfs_calc(int v, int par) {
	for (int to : g[v]) {
		if (to == par) continue;
		dfs_calc(to, v);
	}
	update(v);
	for (int ind : q_up[v]) {
		int w = e[ind].w;
		int vv = e[ind].v, uu = e[ind].u;
		q_bot[vv].erase(mp(w, ind));
		update(vv);
		q_bot[uu].erase(mp(w, ind));
		update(uu);
	}
	int l = left_end[v], r = right_end[v];
	if (to_add[v]) {
		int res = get(1, 0, tSize, l, r);
		if (res == INF) inf_ans = true;
		ans += res;
	}
}	

template <class T = int> inline T readInt();            
inline double readDouble();
inline int readUInt();           
inline int readChar();           
inline void readWord( char *s ); 
inline bool readLine( char *s ); // do not save '\n'
inline bool isEof();
inline int peekChar();
inline bool seekEof();

template <class T> inline void writeInt( T x, int len );
template <class T> inline void writeUInt( T x, int len );
template <class T> inline void writeInt( T x ) { writeInt(x, -1); };
template <class T> inline void writeUInt( T x ) { writeUInt(x, -1); };
inline void writeChar( int x ); 
inline void writeWord( const char *s );
inline void writeDouble( double x, int len = 0 );
inline void flush();

/** Read */

static const int buf_size = 8092;

static char buf[buf_size];
static int buf_len = 0, pos = 0;

inline bool isEof() {
  if (pos == buf_len) {
    pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
    if (pos == buf_len)
      return 1;
  }
  return 0;
}

inline int getChar() { 
  return isEof() ? -1 : buf[pos++];
}

inline int peekChar() { 
  return isEof() ? -1 : buf[pos];
}

inline bool seekEof() { 
  int c;
  while ((c = peekChar()) != -1 && c <= 32)
    pos++;
  return c == -1;
}

inline int readChar() {
  int c = getChar();
  while (c != -1 && c <= 32)
    c = getChar();
  return c;
}

inline int readUInt() {
  int c = readChar(), x = 0;
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getChar();
  return x;
}

template <class T>
inline T readInt() {
  int s = 1, c = readChar();
  T x = 0;
  if (c == '-')
    s = -1, c = getChar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
}

inline double readDouble() {
  int s = 1, c = readChar();
  double x = 0;
  if (c == '-')
    s = -1, c = getChar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getChar();
  if (c == '.') {
    c = getChar();
    double coef = 1;
    while ('0' <= c && c <= '9')
      x += (c - '0') * (coef *= 1e-1), c = getChar();
  }
  return s == 1 ? x : -x;
}

inline void readWord( char *s ) { 
  int c = readChar();
  while (c > 32)
    *s++ = c, c = getChar();
  *s = 0;
}

inline bool readLine( char *s ) { 
  int c = getChar();
  while (c != '\n' && c != -1)
    *s++ = c, c = getChar();
  *s = 0;
  return c != -1;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
  if (write_pos == buf_size)
    fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
  write_buf[write_pos++] = x;
}

inline void flush() {
  if (write_pos)
    fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
}

template <class T> 
inline void writeInt( T x, int output_len ) {
  if (x < 0)
    writeChar('-'), x = -x;

  char s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n < output_len)
    s[n++] = '0';
  while (n--)
    writeChar(s[n]);
}

template <class T> 
inline void writeUInt( T x, int output_len ) {
  char s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n < output_len)
    s[n++] = '0';
  while (n--)
    writeChar(s[n]);
}

inline void writeWord( const char *s ) {
  while (*s)
    writeChar(*s++);
}

inline void writeDouble( double x, int output_len ) {
  if (x < 0)
    writeChar('-'), x = -x;
  int t = (int)x;
  writeUInt(t), x -= t;
  writeChar('.');
  for (int i = output_len - 1; i > 0; i--) {
    x *= 10;
    t = std::min(9, (int)x);
    writeChar('0' + t), x -= t;
  }
  x *= 10;
  t = std::min(9, (int)(x + 0.5));
  writeChar('0' + t);
}

int main() {
#ifdef LOCAL    
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout); 
#endif    
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	forn(i, 4 * MAX_N) tree[i] = INF;
	int n, k, m;
	n = readInt(); k = readInt(); m = readInt();
	forn (i, n)
		p[i] = i, rk[i] = 0;
	forn (i, k) {
		int v, u;
		v = readInt(); u = readInt();
		v--, u--;
		unite(v, u);
		edges.insert(mp(v, u));
		edges.insert(mp(u, v));
		g[v].pb(u);
		g[u].pb(v);
	}
	forn (i, m) {
		e[i].v = readInt(); e[i].u = readInt(); e[i].w = readInt();
		e[i].v--, e[i].u--;
	}
	sort(e, e + m);
	forn (i, m) {
		int v = get(e[i].v);
		int u = get(e[i].u);
		if (v != u) {
			unite(v, u);
			g[e[i].v].pb(e[i].u);
			g[e[i].u].pb(e[i].v);
			was[i] = 1;	
		}
	}	
	while(tSize < n) tSize *= 2;
	dfs(0, 0);
	forn (i, m) {
		if (was[i]) {
			continue;
		}
		int lc = lca(e[i].v, e[i].u);
		q_bot[e[i].v].insert(mp(e[i].w, i));
		q_bot[e[i].u].insert(mp(e[i].w, i));
		q_up[lc].pb(i);
//		cerr << "v = " << e[i].v << " u = " << e[i].u << " lca = " << lc << '\n';
	}
	dfs_calc(0, 0);
	if (inf_ans) cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;
}