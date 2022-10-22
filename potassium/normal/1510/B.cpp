#pragma GCC optimize ("O3", "unroll-loops")
// #pragma GCC target ("avx2")
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define distinct(x) sort(all(x)); x.resize(unique(all(x))-x.begin())
// #define pb push_back
// #define mp make_pair
#define fi first
#define se second
#define CASE(x) int x; cin >> x; while (x--)
#define CASEt(x) int x; cin >> x; for (int tc = 1; tc <= x; ++tc)
using namespace std;
namespace {
	const int MOD107 = 1000000007;
	const int MOD998 = 998244353;
	using ll = long long;
	using ull = unsigned long long;
	using pii = pair<int, int>;
	using pll = pair<ll, ll>;
	template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
	template <class T> using maxheap = priority_queue<T, vector<T>, less<T>>;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
	struct Modular {
	private:
		long long MODVALUE = 0;
		long long val = 0;
 
		Modular initModular(long long val) const { return Modular(val, MODVALUE); }
 
	#ifdef LOCAL
		inline void validate() const {
			assert(MODVALUE != 0);
			assert(0 <= val && val < MODVALUE);
		}
 
		inline void validate(const Modular& other) const {
			validate();
			other.validate();
			assert(MODVALUE == other.MODVALUE);
		}
	#else
		inline void validate() const { }
		inline void validate(const Modular& other) const { }
	#endif
 
	public:
		explicit operator long long() const { return val; }
 
		template<class T> Modular& operator = (const T& other) { val = (other % MODVALUE + MODVALUE) % MODVALUE; return *this; }
		long long getMod() { return MODVALUE; }
		template<class T> void setMod(const T& MOD) { MODVALUE = MOD; }

		bool operator == (const Modular& other) const { validate(other); return val == other.val; }
		bool operator != (const Modular& other) const { return !(*this == other); }
 
		Modular& operator += (const Modular& other)       { validate(other); val += other.val; if (val >= MODVALUE) val -= MODVALUE; return *this; }
		Modular  operator +  (const Modular& other) const { Modular tmp = *this; return tmp += other; }
		template<class T> Modular& operator += (const T& other)       { return *this += initModular(other); }
		template<class T> Modular  operator +  (const T& other) const { return *this +  initModular(other); }
		template<class T> friend Modular operator + (const T& other, const Modular& m) { return m.initModular(other) + m; }
 
		Modular& operator ++()    { return *this += 1; }
		Modular  operator ++(int) { Modular tmp = *this; ++*this; return tmp; }
 
		Modular  operator -  () const { return initModular(-val); }
		Modular& operator -= (const Modular& other)       { validate(other); val -= other.val; if (val < 0) val += MODVALUE; return *this;}
		Modular  operator -  (const Modular& other) const { Modular tmp = *this; return tmp -= other; }
		template<class T> Modular& operator -= (const T& other)       { return *this -= initModular(other); }
		template<class T> Modular  operator -  (const T& other) const { return *this -  initModular(other); }
		template<class T> friend Modular operator - (const T& other, const Modular& m) { return m.initModular(other) - m; }
 
		Modular& operator --()    { return *this -= 1; }
		Modular  operator --(int) { Modular tmp = *this; --*this; return tmp; }
 
		Modular& operator *= (const Modular& other)       { validate(other); val *= other.val; val %= MODVALUE; if (val < 0) val += MODVALUE; return *this; }
		Modular  operator *  (const Modular& other) const { Modular tmp = *this; return tmp *= other; }
		template<class T> Modular& operator *= (const T& other)       { return *this *= initModular(other); }
		template<class T> Modular  operator *  (const T& other) const { return *this *  initModular(other); }
		template<class T> friend Modular operator * (const T& other, const Modular& m) { return m.initModular(other) * m; }
 
		Modular pow(long long power) const {
			Modular m = *this, ans = initModular(1);
			while (power) {
				if (power & 1) ans *= m;
				m *= m;
				power >>= 1;
			}
			return ans;
		}
		Modular pow(const Modular& other) const { return pow(other.val); }
		Modular inv() const { return pow(MODVALUE - 2); }
 
		Modular& operator /= (const Modular& other)       { val *= other.inv().val; val %= MODVALUE; if (val < 0) val += MODVALUE; return *this; }
		Modular  operator /  (const Modular& other) const { Modular tmp = *this; return tmp /= other; }
		template<class T> Modular& operator /= (const T& other)       { return *this /= initModular(other); }
		template<class T> Modular  operator /  (const T& other) const { return *this /  initModular(other); }
		template<class T> friend Modular operator / (const T& other, const Modular& m) { return m.initModular(other) / m; }
 
		friend istream& operator >> (istream& in, Modular& m) { in >> m.val; m.val %= m.MODVALUE; if (m.val < 0) m.val += m.MODVALUE; return in; }
		friend ostream& operator << (ostream& out, const Modular& m) { return out << m.val; }
 
		Modular() { val = 0; MODVALUE = 0; }
		Modular(long long val, long long MOD) : MODVALUE(MOD), val((val % MOD + MOD) % MOD) { }
	};
	using Mint = Modular;
	inline ll binpow(ll b, ll p, ll mod) {
		b %= mod;
		ll ans = 1;
		for (; p > 0; p >>= 1) {
			if (p&1) {ans *= b; ans %= mod;}
			b *= b;
			b %= mod;
		}
		return ans;
	}
	inline ll max(ll a, int b) { return (a > b ? a : b); }
	inline ll max(int a, ll b) { return (a > b ? a : b); }
	inline ll min(ll a, int b) { return (a < b ? a : b); }
	inline ll min(int a, ll b) { return (a < b ? a : b); }
	template <class T> inline bool chkmin(T&x, const T& y) { return y < x ? x = y, 1 : 0; }
	template <class T> inline bool chkmax(T&x, const T& y) { return x < y ? x = y, 1 : 0; }
}
namespace IO {
	struct InputWrapper {
	private:
		istream& in;

	public:
		template<class T> inline void _R(T &x) { in >> x; }
		template<class T1, class T2> inline void _R(pair<T1,T2> &x) { _R(x.first); _R(x.second); }
		template<class T> inline void _R(vector<T> &x) { for (auto& i : x) _R(i); }
		template<class T> inline void _R(deque<T> &x) { for (auto& i : x) _R(i); }
		inline void R() { }
		template<class T1, class... T2> inline void R(T1 &x, T2 &...y) { _R(x); R(y...); }
		template<class... T> inline void operator () (T &...x) { R(x...); }
		InputWrapper(istream& in) : in(in) { }
	} R(cin);

	struct OutputWrapper {
	private:
		ostream& out;
		
	public:
		template<class Container> inline void printContainer(const Container& x) { bool isFirst = 1; for (auto i : x) { if (!isFirst) out << ' '; isFirst = 0; _W(i); } }
		template<class T> inline void _W(const T& x) { out << x; }

		template<class T1, class T2> inline void _W(const pair<T1,T2>& p) {_W(p.first); _W(' '); _W(p.second);}
		template<class... T> inline void _W(const vector<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const deque<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const forward_list<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const list<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const set<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const multiset<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const unordered_set<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const unordered_multiset<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const map<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const multimap<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const unordered_map<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const unordered_multimap<T...>& x) { printContainer(x); }

		inline void W() { out << '\n'; }
		template<class T> inline void W(const T &x) { _W(x); W(); }
		template<class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); _W(' '); W(y...); }
		template<class... T> inline void operator () (const T &...x) { W(x...); }
		OutputWrapper(ostream& out) : out(out) { }
	} W(cout), D(cerr);
} using namespace IO;
namespace outputFormat{
	inline string Case(int tc) {return "Case #" + to_string(tc) + ':';}
	inline string YN(bool b) {return b ? "Yes" : "No";}
} using namespace outputFormat;
namespace std {
	template <class T1, class T2> struct hash<pair<T1,T2>> {
		std::size_t operator()(pair<T1,T2> _) const {
			return hash<T1>{}(_.first) ^ hash<T2>{}(_.second);
		}
	};
}


template<class T>
struct KM {
public:
	int N,M;
	int matched;
	vector<vector<T>> cost;
	vector<T> lx,rx;
	vector<int> lm,rm;
	vector<bool> s,t;
	vector<T> slack;
	vector<T> slackx;
	vector<int> prev;

	void init_labels() {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				lx[i] = max(lx[i], cost[i][j]);
	}

	void update_labels() {
		T delta = numeric_limits<T>::max();
		for (int y = 0; y < M; y++)
			if (!t[y]) delta = min(delta, slack[y]);
		for (int x = 0; x < N; x++)
			if (s[x]) lx[x] -= delta;
		for (int y = 0; y < M; y++)
			if (t[y])
				rx[y] += delta;
			else
				slack[y] -= delta;
	}

	void add_to_tree(int x, int prevx) {
		s[x] = true;
		prev[x] = prevx;
		for (int y = 0; y < M; y++)
			if (lx[x] + rx[y] - cost[x][y] < slack[y]) {
				slack[y] = lx[x] + rx[y] - cost[x][y];
				slackx[y] = x;
			}
	}

	void augment() {
		if (matched == min(N, M)) return;
		int root = -1;
		queue<int> Q;
		s.assign(N, false);
		t.assign(M, false);
		prev.assign(N, -1);
		for (int x = 0; x < N; x++) {
			if (lm[x] == -1) {
				Q.push(x);
				root = x;
				prev[x] = -2;
				s[x] = true;
				break;
			}
		}
		assert(root != -1);
		for (int y = 0; y < M; y++) {
			slack[y] = lx[root] + rx[y] - cost[root][y];
			slackx[y] = root;
		}
		
		int x0 = -1;
		int y0 = -1;
		while (true) {
			while (!Q.empty()) {
				int x = Q.front();
				Q.pop();

				for (int y = 0; y < M; y++)
					if (cost[x][y] == lx[x] + rx[y] && !t[y]) {
						if (rm[y] == -1) { x0 = x; y0 = y; break; }
						t[y] = true;
						Q.push(rm[y]);
						add_to_tree(rm[y], x);
					}

				if (y0 != -1) break;
			}
			if (y0 != -1) break;
			update_labels();
			while (!Q.empty()) Q.pop();

			for (int y = 0; y < M; y++)
				if (!t[y] && slack[y] == 0) {
					if (rm[y] == -1) {
						x0 = slackx[y];
						y0 = y;
						break;
					}
					else {
						t[y] = true;
						if (!s[rm[y]]) {
							Q.push(rm[y]);
							add_to_tree(rm[y], slackx[y]);
						}
					}
				}

			if (y0 != -1) break;
		}

		if (y0 < M) {
			matched++;
			for (int cx = x0, cy = y0, ty; cx != -2; cx = prev[cx], cy = ty) {
				ty = lm[cx];
				rm[cy] = cx;
				lm[cx] = cy;
			}
		}
	}

	KM(int N, int M) : N(N), M(M), matched(0), cost(N, vector<T>(M)), 
		lx(N), rx(M), lm(N, -1), rm(M, -1), s(N), t(M), slack(M), slackx(M), prev(N) { }
};

int main() {
	int d,n; R(d,n);
	const int N = 1 << d;

	vector<bool> exist(N, false);
	for (int i = 0; i < n; i++) {
		string s; R(s);
		reverse(s.begin(), s.end());
		exist[bitset<10>(s).to_ulong()] = true;
	}

	KM<int> km(N, N);
	for (int mask = 1; mask < N; mask++) {
		if (!exist[mask]) continue;
		for (int submask = (mask - 1) & mask; submask > 0; submask = (submask - 1) & mask) {
			if (!exist[submask]) continue;
			km.cost[submask][mask] = __builtin_popcount(submask) + 1;
		}
	}

	km.init_labels();
	for (int i = 0; i < N; i++)
		km.augment();
	
	vector<int> to(N, -1);
	for (int mask = 1; mask < N; mask++)
		if (km.cost[mask][km.lm[mask]] != 0)
			to[mask] = km.lm[mask];

	string ans;
	auto go = [&](int addmask) {
		for (int i = 0; i < d; i++)
			if (addmask >> i & 1)
				ans += '0' + i;
	};
	auto reset = [&]() {
		ans += 'R';
	};
	
	for (int mask = 1; mask < N; mask++) {
		if (!exist[mask] || km.cost[km.rm[mask]][mask] != 0) continue;

		int curMask = 0;
		int h = mask;
		do {
			go(h ^ curMask);
			curMask = h;
			h = to[h];
		} while (h != -1);

		reset();
	}
	ans.pop_back();

	W(ans.size());
	for (int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] << " \n"[i + 1 == (int)ans.size()];

	return 0;
}

static auto __init__ = [](){
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
#endif
	cout << fixed << setprecision(10);
	return 42;
}();