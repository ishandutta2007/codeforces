#pragma region
#include <bits/stdc++.h>
using namespace std;
// Common Type shorteners and int128
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<ll, ll>;
template <typename T> using vec = vector<T>;
template <typename K, typename V> using umap = unordered_map<K, V>; template <typename K> using uset = unordered_set<K>;
using vi = vec<int>; using vl = vec<ll>; using vpi = vec<pii>; using vpl = vec<pll>;
#ifdef __SIZEOF_INT128__
using int128 = __int128_t; using uint128 = __uint128_t;
#endif
template<typename I> string intStr(I x) { string ret; while (x > 0) { ret += (x % 10) + '0'; x /= 10; } reverse(ret.begin(), ret.end()); return ret; } // Int to string
// Shorthand Macros
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define mpr make_pair
#define mtup make_tuple
#define pb push_back
#define popcount __builtin_popcount
#define clz __builtin_clz
#define ctz __builtin_ctz
#define finline __attribute__((always_inline))
// Shorthand Function Macros
#define sz(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (__typeof(a) i = a; i < b; i++)
#define reprev(i, a, b) for (__typeof(a) i = a; i > b; i--)
#define repi(a, b) rep(i, a, b)
#define repj(a, b) rep(j, a, b)
#define repk(a, b) rep(k, a, b)
#define Cmplt(type) bool operator<(const type &o) const
#define Cmpgt(type) bool operator>(const type &o) const
#define Cmpfn(name, type) bool name(const type &a, const type &b)
#define Inop(type) istream& operator>>(istream& in, type &o)
#define Outop(type) ostream& operator<<(ostream& out, type o)
#define Pow2(x) (1LL << (x))
#define scn(type, ...) type __VA_ARGS__; scan(__VA_ARGS__) // scn -> Short for SCan New
// Shorthand Functions
template<typename T> inline void maxa(T& st, T v) { st = max(st, v); }
template<typename T> inline void mina(T& st, T v) { st = min(st, v); }
inline void setprec(ostream& out, int prec) { out << setprecision(prec) << fixed; }
// Out operators and printing for arrays and vectors
template <typename T> ostream& operator<<(ostream& out,vector<T> iter){out<<"[";for(auto t:iter){out<<t<<", ";}out<<"]";return out;}
template <typename T> string arrayStr(T *arr,int sz){string ret = "[";for(int i=0;i<sz;i++){ret+=to_string(arr[i])+", "; } return ret + "]";}
template <typename T> void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<" "; } cout<<"\n";}
// I/O Operations
inline void scan(){}
template<typename F, typename... R> inline void scan(F &f,R&... r){cin>>f;scan(r...);}
template <typename F> inline void println(F t){cout<<t<<'\n';}
template<typename F, typename... R> inline void println(F f,R... r){cout<<f<<" ";println(r...);}
inline void print(){}
template<typename F, typename... R> inline void print(F f,R... r){cout<<f;print(r...);}
// Debugging
#define db(x) cout << (#x) << ": " << (x) << ", "
#define dblb(s) cout << "[" << (s) << "] "
#define dba(alias, x) cout << (alias) << ": " << (x) << ", "
template<typename F> inline string __generic_tostring(F f) { stringstream ss; ss << f; return ss.str(); }
template<typename F> inline string __join_comma(F f) {return __generic_tostring(f);}
template<typename F, typename... R> string __join_comma(F f, R... r) { return __generic_tostring(f) + ", " + __join_comma(r...); }
#define dbp(alias, ...) cout << (alias) << ": (" << __join_comma(__VA_ARGS__) << "), "
#define dbbin(x, n) cout << (#x) << ": " << bitset<n>(x) << ", "
#define dbarr(x, n) cout << (#x) << ": " << arrayStr((x), (n)) << ", "
#define dbln cout << endl;
#pragma endregion

const int MN = 15, MSUB = 131072, DIR[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, DIS_SZ = MN * MN * MSUB;
int N, M,
	snakeLen = -1, ex, ey;
char grid[MN][MN];

// bfs stuff
const int Q_SZ = DIS_SZ + 0;
short dis[DIS_SZ];
bitset<DIS_SZ> inq;
int lptr = 0, rptr = 0, q[Q_SZ];
bool badGrid[MN][MN], badSelf[MN][MN];

int getX(int msk) { return msk & 15; }
int getY(int msk) { return (msk >> 4) & 15; }
int getDir(int msk) { return msk >> 8; }
int make(int x, int y, int dir) {
	return x | (y << 4) | (dir << 8);
}

int lenMask() { return (1 << ((snakeLen - 1) * 2)) - 1; }

void push(int st) {
	if (inq[st]) return;
	inq[st] = true;
	q[rptr++] = st;
	if (rptr >= Q_SZ) rptr = 0;
}
int pop() {
	int res = q[lptr++];
	inq[res] = false;
	if (lptr >= Q_SZ) lptr = 0;
	return res; 
}
bool empty() {
	return lptr == rptr;
}

void setBadSelf(int x, int y, int dir, bool val) {
	badSelf[x][y] = val;
	repi(0, snakeLen - 2) {
		x += DIR[dir & 3][0];
		y += DIR[dir & 3][1];
		dir >>= 2;
		badSelf[x][y] = val;
	}
}

bool done = false;
void tryPush(int x, int y, int newDir, int dir, int alt) {
	if (done) return;
	dir = ((dir << 2) | newDir) & lenMask();
	int state = make(x, y, dir);
	if (x < 0 || x >= N || y < 0 || y >= M || 
		alt > dis[state] || badGrid[x][y] || badSelf[x][y]) return;
	dis[state] = alt;
	push(state);
	if (x == ex && y == ey) done = true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	scan(N, M);
	repi(0, N) {
		scan(grid[i]);
		repj(0, M)
			if (grid[i][j] == '#')
				badGrid[i][j] = true;
		// dbarr(grid[i], M);dbln;
	}
	
	// initial state setup
	int initX, initY, initDir = 0;
	repi(0, N) {
		repj(0, M) {
			if (grid[i][j] == '1')
				initX = i, initY = j;
			if (grid[i][j] == '@')
				ex = i, ey = j;
		}
	}
	reprev(i, 8, 0) {
		char A = i + '0', B = A + 1;
		int ax = -1, ay = -1;
		repj(0, N)
			repk(0, M)
				if (grid[j][k] == A)
					ax = j, ay = k;
		int bx = -1, by = -1;
		repj(0, N)
			repk(0, M)
				if (grid[j][k] == B)
					bx = j, by = k;
		// db(i); db(ax); db(ay); db(bx); db(by); dbln;
		if (bx != -1 && ax != -1) {
			int v;
			if (bx == ax + 1) v = 0;
			if (bx == ax - 1) v = 1;
			if (by == ay + 1) v = 2;
			if (by == ay - 1) v = 3;
			initDir = (initDir << 2) | v;
			maxa(snakeLen, i + 1);
		}
	}
	// db(snakeLen); dbln;
	// assert(0);

	// bfs
	memset(dis, 0x3f, sizeof dis);
	push(make(initX, initY, initDir));
	dis[make(initX, initY, initDir)] = 0;
	while (!empty()) {
		auto st = pop();
		int x = getX(st), y = getY(st), dir = getDir(st), cdis = dis[st];
		setBadSelf(x, y, dir, 1);

		// db(x); db(y); dbbin(dir, 18); dbln;
		// repi(0, N) {
		// 	repj(0,M)print(badSelf[i][j]);
		// 	print('\n');
		// }
		// cout.flush();

		tryPush(x + 1, y, 1, dir, cdis + 1);
		tryPush(x - 1, y, 0, dir, cdis + 1);
		tryPush(x, y + 1, 3, dir, cdis + 1);
		tryPush(x, y - 1, 2, dir, cdis + 1);
		setBadSelf(x, y, dir, 0);

		if (done) break;
	}

	// output
	short ans = 16191;
	if (grid[ex][ey] == '@') {
		repk(0, MSUB) {
			int state = make(ex, ey, k);
			if (state < DIS_SZ) {
				mina(ans, dis[state]);
				// db(k); db(ans); dbln;
			}
		}
	}
	println(ans == 16191 ? -1 : ans);

	return 0;
}