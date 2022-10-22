#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define MOD2 998244353
#define SP << ' '
#define EL << '\n'
#define FL << flush
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
//mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 x(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
namespace input {
	template<class T> inline void _R(T &x) {cin >> x;}
	inline void R() {}
	template<class T1, class... T2> inline void R(T1 &x, T2 &...y) { _R(x); R(y...);}
}
namespace overload_output {
	template<class T1, class T2> inline ostream& operator << (ostream& out, pair<T1,T2>& p) {return out << p.first << ' ' << p.second;}
	template<class T> inline ostream& operator << (ostream& out, vector<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, deque<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, forward_list<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, list<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, set<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, multiset<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, unordered_set<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, unordered_multiset<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T1, class T2> inline ostream& operator << (ostream& out, map<T1, T2>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T1, class T2> inline ostream& operator << (ostream& out, multimap<T1, T2>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T1, class T2> inline ostream& operator << (ostream& out, unordered_map<T1, T2>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T1, class T2> inline ostream& operator << (ostream& out, unordered_multimap<T1, T2>& x) {for (auto i : x) out << i << ' '; return out;}
}
namespace output {
	template<class T1, class T2> inline void _W(const pair<T1,T2>& p) {cout << p.first << ' ' << p.second;}
	template<class T> inline void _W(const vector<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const deque<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const forward_list<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const list<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const set<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const multiset<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const unordered_set<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const unordered_multiset<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T1, class T2> inline void _W(const map<T1, T2>& x) {for (auto i : x) cout << i << ' ';}
	template<class T1, class T2> inline void _W(const multimap<T1, T2>& x) {for (auto i : x) cout << i << ' ';}
	template<class T1, class T2> inline void _W(const unordered_map<T1, T2>& x) {for (auto i : x) cout << i << ' ';}
	template<class T1, class T2> inline void _W(const unordered_multimap<T1, T2>& x) {for (auto i : x) cout << i << ' ';}
	
	template<class T> inline void _W(T &x) {cout << x << ' ';}
	inline void W() {cout << "\n";}
	template<class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); W(y...);}
}

using namespace input;
using namespace overload_output;
using namespace output;

struct prime_sieve{
	vector<int> primes;
	vector<bool> isComposite;
	vector<int> min_divisor;

	int checkPrime(int x) {
		vector<int>::iterator it = lower_bound(primes.begin(),primes.end(),x);
		if (it != primes.end() && *it == x)
			return it - primes.begin() + 1;
		else
			return -1;
	}

	vector<pair<int,int> > prime_factorize(int x) {
		vector<pair<int,int> > factors;
		for (auto i : primes) {
			if (x % i == 0) {
				factors.push_back({i,1});
				x /= i;
			}
			while (x % i == 0) {
				factors.back().second++;
				x /= i;
			}
			if (x == 1)
				return factors;
		}
		if (x != 1)
			factors.push_back({x,1});
		return factors;
	}

	prime_sieve(int n) {
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

int main() {
	int n; R(n);
	
	prime_sieve ps(n*2+7);
	
	int target = *lower_bound(ps.primes.begin(),ps.primes.end(),n);
	
	if (target > n + n/2) {
		W(-1);
		return 0;
	}
	
	W(target);
	for (int i = 0; i < n-1; i++)
		W(i+1,i+2);
	W(n,1);
	target -= n;
	
	int incre = n/2;
	
	for (int i = 0; i < target; i++)
		W(i+1,i+1+incre);
	
	return 0;
}

#ifndef LOCAL
static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();
#endif