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
	template <class T1, class T2> inline bool chkmin(T1& x, const T2& y) { return x > y ? x = y, 1 : 0; }
	template <class T1, class T2> inline bool chkmax(T1& x, const T2& y) { return x < y ? x = y, 1 : 0; }
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
namespace std {
    template <class T1, class T2> struct hash<pair<T1,T2>> {
    	std::size_t operator()(pair<T1,T2> _) const {
        	return hash<T1>{}(_.first) ^ hash<T2>{}(_.second);
    	}
    };
}
using Mint = Modular<MOD>;


const int THRES = 200000;
void small(string& s) {
	W("SMALL");
	W(s.size());
	W(s);
	exit(0);
}

void big(ll ans) {
	W("BIG");
	W(ans);
	exit(0);
}

void imp() {
	W("IMPOSSIBLE");
	exit(0);
}

int main() {
	int n; R(n);

	vector<ll> a(n); R(a);
	vector<ll> b(n); R(b);

	if (a == b) {
		string s = "";
		small(s);
	}

	reverse(all(b));

	if (a == b) {
		string s = "R";
		small(s);
	}

	reverse(all(b));

	if (n == 1) {
		imp();
	}

	if (n == 2) {
		auto proc = [&](vector<ll>& v) {
			vector<pair<char, ll>> op;
			while (true) {
				if (v[0] > v[1]) {
					swap(v[0], v[1]);
					op.pb( {'R', 1} );
				}

				ll mul = v[1] / v[0];
				op.pb( {'P', mul} );
				v[1] -= mul * v[0];

				if (v[1] == 0) return op;
			}
		};

		vector<pair<char, ll>> opA = proc(a);
		vector<pair<char, ll>> opB = proc(b);

		if (a == b) {
			while (!opA.empty() && !opB.empty()) {
				if (opA.back().first == opB.back().first) {
					ll take = min(opA.back().second, opB.back().second);

					opA.back().second -= take;
					opB.back().second -= take;

					if (opA.back().second == 0) opA.pop_back();
					if (opB.back().second == 0) opB.pop_back();
				} else if (opA.back().first == 'R') {
					opA.pop_back();
					opB.pb( {'R', 1} );
				} else {
					break;
				}
			}

			if (opA.empty()) {
				ll len = 0;
				for (auto& i : opB)
					if (i.first == 'P')
						len += i.second;

				if (len <= THRES) {
					string s;
					while (!opB.empty()) {
						for (int i = 0; i < opB.back().second; i++)
							s += opB.back().first;
						opB.pop_back();
					}

					small(s);
				} else {
					big(len);
				}
			}
		}

		imp();
	} else {
		auto proc = [&](vector<ll>& v) {
			string s;
			while (true) {
				bool chkInc = (v[0] < v[1]);

				bool is = 1;
				for (int i = 0; i < n - 1; i++)
					if (chkInc)
						is &= (v[i] < v[i + 1]);
					else
						is &= (v[i] > v[i + 1]);

				if (!is)
					break;

				if (!chkInc) {
					s += 'R';
					reverse(all(v));
				}

				s += 'P';
				for (int i = n - 1; i > 0; i--)
					v[i] -= v[i - 1];
			}
			return s;
		};

		string sA = proc(a);
		string sB = proc(b);

		for (int times = 0; times < 2; times++) {
			if (a == b) {
				while (!sA.empty() && !sB.empty()) {
					if (sA.back() == sB.back()) {
						sA.pop_back();
						sB.pop_back();
					} else if (sA.back() == 'R') {
						sA.pop_back();
						sB += 'R';
					} else break;
				}

				if (sA.empty()) {
					reverse(all(sB));
					int len = 0;
					for (auto& i : sB)
						if (i == 'P')
							len++;

					if (len <= THRES) {
						small(sB);
					} else {
						big(len);
					}
				}
			}
			reverse(all(b));
			sB += 'R';
		}

		imp();
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