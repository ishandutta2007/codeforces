#pragma GCC optimize ("O3", "unroll-loops")
// #pragma GCC target ("avx2")
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define distinct(x) sort(all(x)); x.resize(unique(all(x))-x.begin())
#define pb push_back
#define mp make_pair
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
//	mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
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
		template<class T> void setMod(const T& MOD) { MODVALUE = MOD; }
 
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
	template <class T> inline bool chkmin(T&x, const T& y) { return x > y ? x = y, 1 : 0; }
	template <class T> inline bool chkmax(T&x, const T& y) { return x < y ? x = y, 1 : 0; }
}
namespace IO {
	template<class T> inline void _R(T &x) {cin >> x;}
	template<class T1, class T2> inline void _R(pair<T1,T2> &x) {_R(x.first); _R(x.second);}
	template<class T> inline void _R(vector<T> &x) {for (auto& i : x) _R(i);}
	template<class T> inline void _R(deque<T> &x) {for (auto& i : x) _R(i);}
	inline void R() {}
	template<class T1, class... T2> inline void R(T1 &x, T2 &...y) { _R(x); R(y...);}

	template<class T> inline void _W(const T& x);
	template<class T1, class T2> inline void _W(const pair<T1,T2>& p);
	template<class... T> inline void _W(const vector<T...>& x);
	template<class... T> inline void _W(const deque<T...>& x);
	template<class... T> inline void _W(const forward_list<T...>& x);
	template<class... T> inline void _W(const list<T...>& x);
	template<class... T> inline void _W(const set<T...>& x);
	template<class... T> inline void _W(const multiset<T...>& x);
	template<class... T> inline void _W(const unordered_set<T...>& x);
	template<class... T> inline void _W(const unordered_multiset<T...>& x);
	template<class... T> inline void _W(const map<T...>& x);
	template<class... T> inline void _W(const multimap<T...>& x);
	template<class... T> inline void _W(const unordered_map<T...>& x);
	template<class... T> inline void _W(const unordered_multimap<T...>& x);

	template<class Container> inline void printContainer(const Container& x) { bool isFirst = 1; for (auto i : x) { if (!isFirst) cout << ' '; isFirst = 0; _W(i); } }

	template<class T> inline void _W(const T& x) {cout << x;}
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

 	inline void W() {cout << '\n';}
	template<class T> inline void W(const T &x) {_W(x); W();}
	template<class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); _W(' '); W(y...);}
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


void ntt(vector<int> & a, bool invert) {
	const static int root = 15311432;
	const static int root_1 = 469870224;
	const static int root_pw = 1 << 23;

    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % MOD998);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % MOD998);
                a[i+j] = u + v < MOD998 ? u + v : u + v - MOD998;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + MOD998;
                w = (int)(1LL * w * wlen % MOD998);
            }
        }
    }

    if (invert) {
		int b = n;
        int n_1 = 1;
		int p = MOD998 - 2;
		for (; p; p >>= 1) {
			if (p & 1) { n_1 = 1LL * n_1 * b % MOD998; }
			b = 1LL * b * b % MOD998;
		}
        for (int & x : a)
            x = (int)(1LL * x * n_1 % MOD998);
    }
}

void multiply(vector<int>& a, vector<int>& b) {
	int n = 1;
	while (n < a.size() + b.size())
		n <<= 1;
		
	int p = __lg(n);
 
	a.resize(n, 0);
	b.resize(n, 0);
 
	ntt(a, false);
	ntt(b, false);
 
	for (int i = 0; i < n; i++)
		a[i] = 1LL * a[i] * b[i] % MOD998;
 
	ntt(a, true);
}

struct cmp {
	bool operator () (vector<int>& v1, vector<int>& v2) {
		return v1.size() > v2.size();
	}
};

int main() {
	int n; R(n);
	const int thres = n / 2 + 1;
	map<int, int> m;
 
	for (int i = 0; i < n; i++) {
		int x; R(x);
		m[x]++;
	}
	
	vector<int> v;
	for (auto& i : m)
		v.pb(i.se + 1);
	sort(all(v));

	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
	for (auto& i : v)
		pq.push(vector<int>(i, 1));
	
	while (pq.size() > 1) {
		vector<int> a, b;
		a = pq.top(); pq.pop();
		b = pq.top(); pq.pop();

		multiply(a, b);
		while (a.back() == 0)
			a.pop_back();
		while (a.size() > thres)
			a.pop_back();
			
		pq.push(a);
	}
 
	vector<int> ans = pq.top();
	int x = ans[n / 2];
	x %= MOD998;
	x += MOD998;
	x %= MOD998;
	W(x);

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