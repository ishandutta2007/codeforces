#pragma GCC optimize ("O3", "unroll-loops")
//#pragma GCC target ("avx2")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define distinct(x) sort(all(x)); x.resize(unique(all(x))-x.begin());
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define CASE(x) int x; cin >> x; while (x--)
#define CASEt(x) int x; cin >> x; for (int tc = 1; tc <= x; ++tc)
using namespace std;
using namespace __gnu_pbds;
namespace {
	const int MOD = 1000000007;
	const int MOD2 = 998244353;
	using ll = long long;
	using ull = unsigned long long;
	using pii = pair<int, int>;
	using pll = pair<ll, ll>;
	using vi = vector<int>;
	using vll = vector<ll>;
	template <class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
	template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
	template <class T> using maxheap = priority_queue<T, vector<T>, less<T>>;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//	mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
	template <int MODVALUE>
	struct Modular {
	private:
		long long val;

		template<class T>
		static Modular toModular(const T& m) {
			long long val = m;
			if (val < 0) val += MODVALUE;
			if (val >= MODVALUE) val -= MODVALUE;
			return Modular(val);
		}

	public:
		long long getVal() {return val;}
		
		bool operator == (const Modular& other) {return val == other.val;}
		bool operator != (const Modular& other) {return !(val == other.val);}
		template<class T> bool operator == (const T& other) {return *this == Modular(other);}
		template<class T> bool operator != (const T& other) {return !(*this == Modular(other));}
		template<class T> friend bool operator == (const T& other, const Modular& m) {return Modular(other) == m;}
		template<class T> friend bool operator != (const T& other, const Modular& m) {return !(Modular(other) == m);}

		bool operator < (const Modular& other) {return val < other.val;}
		bool operator <= (const Modular& other) {return val <= other.val;}
		bool operator > (const Modular& other) {return val > other.val;}
		bool operator >= (const Modular& other) {return val >= other.val;}
		template<class T> bool operator < (const T& other) {return *this < Modular(other);}
		template<class T> bool operator <= (const T& other) {return *this <= Modular(other);}
		template<class T> bool operator > (const T& other) {return *this > Modular(other);}
		template<class T> bool operator >= (const T& other) {return *this >= Modular(other);}
		template<class T> friend bool operator < (const T& other, const Modular& m) {return Modular(other) < m;}
		template<class T> friend bool operator <= (const T& other, const Modular& m) {return Modular(other) <= m;}
		template<class T> friend bool operator > (const T& other, const Modular& m) {return Modular(other) > m;}
		template<class T> friend bool operator >= (const T& other, const Modular& m) {return Modular(other) >= m;}

		Modular operator + (const Modular& other) {return toModular(val + other.val);}
		Modular& operator += (const Modular& other) {return *this = *this + other;}
		template<class T> Modular operator + (const T& other) {return *this + Modular(other);}
		template<class T> Modular& operator += (const T& other) {return *this += Modular(other);}
		template<class T> friend Modular operator + (const T& other, const Modular& m) {return Modular(other) + m;}
		template<class T> friend Modular operator += (const T& other, const Modular& m) {return Modular(other) += m;}

		Modular& operator ++() {return *this += 1;}
		Modular operator ++(int) {Modular tmp = *this; ++*this; return tmp;}

		Modular operator - () const {return Modular(-val);}
		Modular operator - (const Modular& other) {return toModular(val - other.val);}
		Modular& operator -= (const Modular& other) {return *this = *this - other;}
		template<class T> Modular operator - (const T& other) {return *this - Modular(other);}
		template<class T> Modular& operator -= (const T& other) {return *this -= Modular(other);}
		template<class T> friend Modular operator - (const T& other, const Modular& m) {return Modular(other) - m;}
		template<class T> friend Modular operator -= (const T& other, const Modular& m) {return Modular(other) -= m;}

		Modular& operator --() {return *this -= 1;}
		Modular operator --(int) {Modular tmp = *this; --*this; return tmp;}

		Modular operator * (const Modular& other) {return toModular(val * other.val % MODVALUE);}
		Modular& operator *= (const Modular& other) {return *this = *this * other;}
		template<class T> Modular operator * (const T& other) {return *this * Modular(other);}
		template<class T> Modular operator *= (const T& other) {return *this *= Modular(other);}
		template<class T> friend Modular operator * (const T& other, const Modular& m) {return Modular(other) * m;}
		template<class T> friend Modular operator *= (const T& other, const Modular& m) {return Modular(other) *= m;}

		Modular pow(long long power) {
			Modular m = *this, ans = 1;
			while (power) {
				if (power & 1) ans *= m;
				m *= m;
				power >>= 1;
			}
			return ans;
		}
		Modular pow(const Modular& other) {return pow(other.val);}
		Modular inv() {return pow(MODVALUE-2);}

		Modular operator / (const Modular& other) {return *this * other;}
		Modular operator /= (const Modular& other) {return *this = *this / other;}
		template<class T> Modular operator / (const T& other) {return *this / Modular(other);}
		template<class T> Modular operator /= (const T& other) {return *this /= Modular(other);}
		template<class T> friend Modular operator / (const T& other, const Modular& m) {return Modular(other) / m;}
		template<class T> friend Modular operator /= (const T& other, const Modular& m) {return Modular(other) /= m;}

		friend istream& operator >> (istream& in, Modular& m) {in >> m.val; m = toModular(m.val % MODVALUE); return in;}
		friend ostream& operator << (ostream& out, const Modular& m) {return out << m.val;}

		Modular() : val(0) {}
		Modular(int val) : val(val % MODVALUE) {};
		Modular(long long val) : val(val % MODVALUE) {};
	};
	inline ll pow(ll b, ll p, ll mod) {
		b %= mod;
		ll ans = 1;
		for (; p > 0; p >>= 1) {
			if (p&1) {ans *= b; ans %= mod;}
			b *= b;
			b %= mod;
		}
		return ans;
	}
	inline ll max(ll a, int b) {return (a > b ? a : b);}
	inline ll max(int a, ll b) {return (a > b ? a : b);}
	inline ll min(ll a, int b) {return (a < b ? a : b);}
	inline ll min(int a, ll b) {return (a < b ? a : b);}
	inline bool chkmin(ll& x, ll y) {return x > y ? x = y, 1 : 0;}
	inline bool chkmin(ll& x, int y) {return x > y ? x = y, 1 : 0;}
	inline bool chkmin(int& x, ll y) {return x > y ? x = y, 1 : 0;}
	inline bool chkmin(int& x, int y) {return x > y ? x = y, 1 : 0;}
	inline bool chkmax(ll& x, ll y) {return x < y ? x = y, 1 : 0;}
	inline bool chkmax(ll& x, int y) {return x < y ? x = y, 1 : 0;}
	inline bool chkmax(int& x, ll y) {return x < y ? x = y, 1 : 0;}
	inline bool chkmax(int& x, int y) {return x < y ? x = y, 1 : 0;}
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
	
	template<class T> inline void _W(const ordered_set<T>& x);
	
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

	template<class T> inline void _W(const ordered_set<T>& x) { printContainer(x); }

 	inline void W() {cout << '\n';}
	template<class T> inline void W(const T &x) {_W(x); W();}
	template<class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); _W(' '); W(y...);}
} using namespace IO;
namespace outputFormat{
	inline string Case(int tc) {return "Case #" + to_string(tc) + ':';}
	inline string YN(bool b) {return b ? "YES" : "NO";}
} using namespace outputFormat;
}
namespace std {
    template <class T1, class T2> struct hash<pair<T1,T2>> {
    	std::size_t operator()(pair<T1,T2> _) const {
        	return hash<T1>{}(_.first) ^ hash<T2>{}(_.second);
    	}
    };
}
using Mint = Modular<MOD>;


template<class T>
struct primeSieve{
	int maxN = 0;
	vector<int> primes;
	vector<bool> isComposite;
	vector<int> min_divisor;

	vector<pair<T,int> > factorize(T x) {
		assert(x > 1);

		vector<pair<T,int> > factors;
		if (x <= maxN) {
			int cur = -1, cnt = -1;
			while (x != 1) {
				if (min_divisor[x] == cur) {
					cnt++;
					x /= cur;
				} else {
					if (cur != -1) {
						factors.push_back({cur,cnt});
					}
					cur = min_divisor[x];
					cnt = 0;
				}
			}
			factors.push_back({cur,cnt});
			return factors;
		} else {
			for (auto i : primes) {
				if (x == 1) break;
				int cnt = 0;
				while (x % i == 0) {
					cnt++;
					x /= i;
				}
				if (cnt > 0) factors.push_back({i,cnt});
			}
			if (x != 1) factors.push_back({x,1});
		}

		return factors;
	}

	primeSieve(int n) {
		maxN = n;
		primes.clear();
		isComposite.resize(n+1);
		min_divisor.resize(n+1);

		for (int i = 2; i <= n; i++) {
			if (!isComposite[i]) {
				primes.push_back(i);
				min_divisor[i] = i;
			}
			for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
				isComposite[i*primes[j]] = 1;
				min_divisor[i*primes[j]] = primes[j];
				if (i % primes[j] == 0)
					break;
			}
		}
	}
};
primeSieve<long long> sieve(1000000);

int main() {
	CASE(t) {
		ll n,k; R(n,k);
		n += sieve.min_divisor[n];
		n += (k - 1) * 2;
		
		W(n);
	}

	return 0;
}


static auto _batch_ios = [](){
	#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
	#endif
	cout << fixed << setprecision(10);
	return 42;
}();