#define MOD 998244353
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define has(set, x) set.find(x) != set.end()
#define nohas(set, x) set.find(x) == set.end()
#define inc(mpp, x) {if(has(mpp, x)) mpp[x]++; else mpp.insert(mp(x,1));}
#define decc(mpp, x) {if(has(mpp, x)) {if(mpp[x] > 1) mpp[x]--; else mpp.erase(x);}}
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define um unordered_map
#define us unordered_set
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <numeric>
#include <bitset>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
struct frac {
	ll a, b;
	frac(int x, int y) {
		if (!y) {
			a = 0;
			b = 0;
		}
		else if (!x) {
			a = 0;
			b = 1;
		}
		else {
			bool neg = (x >= 0) ^ (y >= 0);
			x = abs(x);
			y = abs(y);
			int g = gcd(x, y);
			a = x / g; b = y / g;
			if (neg)a = -a;
		}
	}
	const bool operator<=(const frac& other) const {
		return (a*other.b <= b * other.a);
	}
	const bool operator>=(const frac& other) const {
		return(a*other.b >= b * other.a);
	}
	const bool operator==(const frac& other) const {
		return (*this <= other && *this >= other);
	}
	const bool operator<(const frac& other) const {
		return (a*other.b < b * other.a);
	}
	const bool operator>(const frac& other) const {
		return(a*other.b > b * other.a);
	}
};
struct pt {
	ll x, y;
	pt(): x(0), y(0) {}
	pt(int a, int b): x(a), y(b) {}
	frac slope(pt other) {
		return frac(y - other.y, x - other.x);
	}
	frac offset(pt other) {
		if (x == other.x)return frac(x, 1);
		return frac(y*other.x - other.y*x, other.x - x);
	}
};
struct line {
	frac m, b;
	line() : m(frac(0,0)), b(frac(0,0)) {}
	line(pt p, pt q) : m(p.slope(q)), b(p.offset(q)) {}
	line(frac slope, frac offset): m(slope), b(offset) {}
	const bool operator<=(const line& other) const {
		if (this->m == other.m) return this->b <= other.b;
		return this->m <= other.m;
	}
	const bool operator>=(const line& other) const {
		if (this->m == other.m) return this->b >= other.b;
		return this->m >= other.m;
	}
	const bool operator<(const line& other) const {
		if (this->m == other.m) return this->b < other.b;
		return this->m < other.m;
	}
	const bool operator>(const line& other) const {
		if (this->m == other.m) return this->b > other.b;
		return this->m > other.m;
	}
	const bool operator==(const line& other) const {
		return (this->m == other.m) && (this->b == other.b);
	}
	
};

struct lineCmp {
	bool operator()(const line& l1, const line& l2) {
		if (l1.m == l2.m) return l1.b < l2.b;
		return l1.m < l2.m;
	}
};

ll res = 0;
set<line> mem;
map<frac, int> cnt;
pt pts[1001];
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	us<ll> bad;
	cin >> n;
	foru(i, 0, n)cin >> pts[i].x >> pts[i].y;
	foru(i, 0, n - 1) {
		foru(j, i + 1, n) {
			if (pts[i].x == pts[j].x) bad.insert(pts[i].x);
			else mem.insert(line(pts[i], pts[j]));
		}
	}
	ll amt = mem.size() + bad.size();
	for (line l : mem) {
		cnt[l.m]++;
	}
	for (auto x : cnt) {
		amt -= x.second;
		res += x.second * amt;
	}
	cout << res << endl;
	return 0;
}